#include "../../s21_addition.h"

// вычитание двух положительных чисел одинакового порядка, val_1 > val_2
int bit_sub(s21_big_decimal val_1, s21_big_decimal val_2,
            s21_big_decimal *result) {
  int ERROR = 0, borrow = 0, borrow2 = 0;
  int end = get_first_bit(val_1);  // найти старший бит - функция
  for (int i = 0; i <= end; i++) {
    int x = get_bit_big(val_1, i);  // берем бит из первого децимала
    int y = get_bit_big(val_2, i);  // берем бит из второго децимала
    unsigned int result_bit = x ^ y;  // 0 если одинаковые, 1 если разные х и у
    if (borrow == 1) {
      borrow2 = (~result_bit) & 1;
      result_bit = result_bit ^ 1;
    }
    borrow = (~x) & y;  // нужно ли нам замещение
    if (borrow2 == 1) borrow = 1;
    set_bit_big(result, i, result_bit);
  }
  return ERROR;
}

// побитовое сложение
int bit_add(s21_big_decimal val_1, s21_big_decimal val_2,
            s21_big_decimal *res) {
  unsigned add = 0;
  for (int i = 0;
       i < (int)(sizeof(s21_big_decimal) / sizeof(unsigned) - 1) * 32; ++i) {
    unsigned res_bit = get_bit_big(val_1, i) + get_bit_big(val_2, i) + add;
    add = res_bit / 2;
    set_bit_big(res, i, res_bit % 2);
  }
  res->bits[7] = val_1.bits[7];
  return 0;
}

// увеличиваем число в заданном масштабе
void level_up_scale(s21_big_decimal *val_1, int size_2) {
  s21_big_decimal *helper_1 = init_big(), *helper_2 = init_big();
  for (int i = size_2; i > 0; --i) {
    paste_big(val_1, helper_1);
    paste_big(val_1, helper_2);
    shift_left_big(helper_1, 3);  // домножили на 8
    shift_left_big(helper_2, 1);  // домножили на 2
    bit_add(*helper_1, *helper_2, val_1);
  }
  free(helper_1);
  free(helper_2);
}

int inf_checking(s21_big_decimal *help_mass, int sign) {
  int ERROR = 0;
  // число не вмещается и положительное -> +inf
  if ((help_mass->bits[3] != 0 || help_mass->bits[4] != 0 ||
       help_mass->bits[5] != 0 || help_mass->bits[6] != 0) &&
      sign == 0)
    ERROR = 1;
  // число не вмещается и отрицательное -> -inf
  else if ((help_mass->bits[3] != 0 || help_mass->bits[4] != 0 ||
            help_mass->bits[5] != 0 || help_mass->bits[6] != 0) &&
           sign == 1)
    ERROR = 2;
  return ERROR;
}

// Обрабатывает переполнение при сложении положительных mass=0,5 - для
// точности(порганичный случай)
void help_to_overf1(s21_big_decimal help_mass, s21_big_decimal big_result) {
  int bit = get_bit_big(help_mass, 0);
  if (bit == 1) {  // переполнение
    s21_big_decimal one = {{1, 0, 0, 0}};
    bit_add(help_mass, one, &big_result);
  } else
    paste_big(&help_mass, &big_result);
}

// Обрабатывает переполнение при сложении или вычитании 
void help_to_overf2(s21_big_decimal *mass, int sign, s21_big_decimal *help_mass,
                    s21_big_decimal *big_result) {
  set_sign_big(mass, 0);
  s21_big_decimal check_mass = {{5, 0, 0, 0}}, number = {{1, 0, 0, 0}};
  set_scale_big(&check_mass, 1);
  int check = compare_big(mass, &check_mass);
  if (check == 1) {
    if (sign == 0) {
      bit_add(*help_mass, number, big_result);
    } else {
      set_sign_big(help_mass, 0);
      bit_add(*help_mass, number, big_result);
      set_sign_big(help_mass, 1);
    }
  } else {
    paste_big(help_mass, big_result);
  }
  set_sign_big(big_result, sign);
}

int is_there_overflow(s21_big_decimal *big_dec, s21_decimal *dec) {
  int ERROR = 0, sign = get_sign_big(big_dec);
  if (big_dec->bits[3] == 0 && big_dec->bits[4] == 0 && big_dec->bits[5] == 0 &&
      big_dec->bits[6] == 0)
    to_small(big_dec, dec);
  else {
    s21_big_decimal massiv = {0}, help_mass = {0}, big_result = {0},
                    ten = {{10, 0, 0, 0}};
    int scale = get_scale_big(big_dec);
    paste_big(big_dec, &massiv);
    paste_big(big_dec, &help_mass);
    set_scale_big(&massiv, 0);
    while (scale != 0) {
      decimall_null_big(&help_mass);
      integer_div(massiv, ten, &help_mass);
      scale--;
      if (help_mass.bits[3] == 0 && help_mass.bits[4] == 0 &&
          help_mass.bits[5] == 0 && help_mass.bits[6] == 0) {
        set_scale_big(&help_mass, scale);
        set_scale_big(&massiv, scale + 1);
        s21_big_decimal mass, help_mass_massiv;
        decimall_null_big(&mass);
        paste_big(&help_mass, &help_mass_massiv);
        paste_big(big_dec, &massiv);
        make_normal(&massiv, &help_mass_massiv);
        set_scale_big(&mass, get_scale_big(&massiv) - scale);
        bit_sub(massiv, help_mass_massiv, &mass);
        if (mass.bits[0] == 5 && scale == 1 && mass.bits[1] == 0 &&
            mass.bits[2] == 0 && mass.bits[3] == 0 && mass.bits[4] == 0 &&
            mass.bits[5] == 0 && mass.bits[6] == 0) {
          help_to_overf1(help_mass, big_result);
        } else
          help_to_overf2(&mass, sign, &help_mass, &big_result);
        to_small(&big_result, dec);
        break;
      } else {
        decimall_null_big(&massiv);
        paste_big(&help_mass, &massiv);
      }
    }
    ERROR = inf_checking(&help_mass, sign);
    if (ERROR == ERROR_INF || ERROR == ERROR_NEGINF) {
      paste_big(&help_mass, big_dec);
    }
  }
  return ERROR;
}

void to_big(s21_decimal *dst, s21_big_decimal *big_dst) {
  decimall_null_big(big_dst);
  if (dst) {
    big_dst->bits[0] = dst->bits[0];
    big_dst->bits[1] = dst->bits[1];
    big_dst->bits[2] = dst->bits[2];
    big_dst->bits[7] = dst->bits[3];
  }
}

// возвращает 1 при ошибке
int to_small(s21_big_decimal *big_dst, s21_decimal *dst) {
  if (big_dst != NULL) {
    if (!if_big_correct(*big_dst)) return 1;
    if (!dst) dst = init_decimal();
    dst->bits[0] = big_dst->bits[0];
    dst->bits[1] = big_dst->bits[1];
    dst->bits[2] = big_dst->bits[2];
    dst->bits[3] = big_dst->bits[7];
  }
  return 0;
}

// на вход только положительные - нормализация
void make_normal(s21_big_decimal *val_1, s21_big_decimal *val_2) {
  int size_1 = get_scale_big(val_1), size_2 = get_scale_big(val_2);
  if (size_1 < size_2) {
    level_up_scale(val_1, size_2 - size_1);
    set_scale_big(val_1, size_2);
  } else if (size_1 > size_2) {
    level_up_scale(val_2, size_1 - size_2);
    set_scale_big(val_2, size_1);
  }
}

s21_decimal *init_decimal() {
  s21_decimal *dec = malloc(sizeof(s21_decimal));
  for (int i = 0; i < 4; ++i) dec->bits[i] = 0;
  return dec;
}

// обнуление
void decimal_null(s21_decimal *result) {
  for (int i = 0; i < 4; ++i) result->bits[i] = 0;
}

// 1 - yes, 0 - no
int zero(s21_decimal val) {
  return (val.bits[0] == 0 && val.bits[1] == 0 && val.bits[2] == 0);
}

// 1 - если есть ошибки, 0 - если нет ошибок
int if_correct(s21_decimal *val) {
  int ERROR = 0;
  for (int i = 96; i < 112 && !ERROR; i++) ERROR = get_bit(*val, i);
  for (int i = 120; i < 127 && !ERROR; i++) ERROR = get_bit(*val, i);
  return ERROR;
}

// int if_correct(s21_decimal *val) {
//   int ERROR = 0;
//   for (int i = 96; i < 112 && !ERROR; i++) ERROR = +get_bit(*val, i);
//   for (int i = 120; i < 127 && !ERROR; i++) ERROR = +get_bit(*val, i);
//   if(val->bits[3] > MAX_BIT) ERROR = 1;
//   if (ERROR!=0) ERROR = 1;
//   return ERROR;
// }

// копирование числа
void paste(s21_decimal *what, s21_decimal *into_what) {
  for (int i = 0; i <= 3; ++i) into_what->bits[i] = what->bits[i];
}

s21_big_decimal *init_big() {
  s21_big_decimal *big_dst = malloc(sizeof(s21_big_decimal));
  for (int i = 0; i < 8; i++) big_dst->bits[i] = 0;
  return big_dst;
}

// обнуление
void decimall_null_big(s21_big_decimal *result) {
  for (int i = 0; i < 8; ++i) result->bits[i] = 0;
}

// 1 - yes, 0 - no
int if_big_correct(s21_big_decimal a) {
  return (a.bits[3] > 0 || a.bits[4] > 0 || a.bits[5] > 0 || a.bits[6] > 0) ? 0
                                                                            : 1;
}

// 1 - yes, 0 - no
int zero_big(s21_big_decimal *a) {
  int k = 1;
  for (int i = 0; i < 7; i++)
    if (a->bits[i] > 0) k = 0;
  return k;
}

// копирование числа
void paste_big(s21_big_decimal *what, s21_big_decimal *into_what) {
  for (int i = 0; i <= 7; ++i) into_what->bits[i] = what->bits[i];
}

// получение знака числа
int get_sign(s21_decimal val) { return (val.bits[3] & (1u << 31)) >> 31; }

// получение знака числа
int get_sign_big(s21_big_decimal *val) {
  return (val->bits[7] & (1u << 31)) >> 31;
}

// устанавливает знак
// void set_sign(s21_decimal *num, int sign) { num->bits[3] |= sign << 31; }

void set_sign(s21_decimal *val, int sign_val) {
  if (sign_val == 0) {
    val->bits[3] = val->bits[3] & ~(1u << 31);
  } else if (sign_val == 1) {
    val->bits[3] = val->bits[3] | (1u << 31);
  }
}

void set_sign_big(s21_big_decimal *val, unsigned sign_val) {
  if (sign_val == 0) {
    val->bits[7] &= ~((1u << 31));
  } else if (sign_val == 1) {
    val->bits[7] |= ((1u << 31));
  }
}

// получает степень
int get_scale(s21_decimal dec) { return (~(1 << 31) & (dec.bits[3])) >> 16; }

// получает степень
int get_scale_big(s21_big_decimal *dec) {
  return (~(1 << 31) & (dec->bits[7])) >> 16;
}

unsigned get_bit(s21_decimal dec, int place) {
  if (place < 0 || place > 95) return -1;
  return ((dec.bits[place / 32]) >> (place % 32)) %
         2;  // возвращает либо 1, либо 0
}

void set_bit(s21_decimal *val, int position, unsigned bit_val) {
  val->bits[position / 32] &= ~(1U << (position % 32));
  val->bits[position / 32] |= bit_val << (position % 32);
}

unsigned get_bit_big(s21_big_decimal val, int place) {
  if (place < 0 || place > 224) return 0;
  return ((val.bits[place / 32]) >> (place % 32)) %
         2;  // возвращает либо 1, либо 0
}

void set_bit_big(s21_big_decimal *val, int position, unsigned bit_val) {
  val->bits[position / 32] &= ~(1U << (position % 32));
  val->bits[position / 32] |= bit_val << (position % 32);
}

// устанавливает степень
int set_scale(s21_decimal *dec, int exp) {
  if (exp > 28 || exp < 0) return 1;  // неверно задана степень
  int mask = 1 << 31;
  dec->bits[3] = dec->bits[3] & mask;  // очищаем биты экспоненты
  mask = exp << 16;
  dec->bits[3] = dec->bits[3] | mask;  // ставим новые биты экспоненты
  return 0;
}

int set_scale_big(s21_big_decimal *dec, int scale_val) {
  if (scale_val > 28 || scale_val < 0) return 1;
  int mask = 1 << 31;
  dec->bits[7] &= mask;
  mask = scale_val << 16;
  dec->bits[7] |= mask;
  return 0;
}

// -1 - первое меньше, 0 - числа равны, 1 - первое больше
int compare_big(s21_big_decimal *super, s21_big_decimal *voper) {
  make_normal(super, voper);
  int sign_1 = 0, sign_2 = 0, result = 0;
  sign_1 = get_sign_big(super);
  sign_2 = get_sign_big(voper);
  if (sign_1 == 1 && sign_2 == 0) {
    result = -1;
  } else if (sign_1 == 0 && sign_2 == 1) {
    result = 1;
  } else {
    int i = 224;
    unsigned t1 = get_bit_big(*super, i);
    unsigned t2 = get_bit_big(*voper, i);
    while ((t1 == t2) && (i >= 0)) {
      i--;
      t1 = get_bit_big(*super, i);
      t2 = get_bit_big(*voper, i);
    }
    if (i == -1) {
      result = 0;
    } else if (sign_1 == 0 && sign_2 == 0) {
      if (t1 > t2)
        result = 1;
      else if (t1 < t2)
        result = -1;
    } else if (sign_1 == 1 && sign_2 == 1) {
      if (t1 > t2)
        result = -1;
      else if (t1 < t2)
        result = 1;
    }
  }
  return result;
}

// -1 - первое меньше, 0 - числа равны, 1 - первое больше
int compare(s21_decimal *first, s21_decimal *second) {
  s21_big_decimal *super = init_big(), *voper = init_big();
  to_big(first, super);
  to_big(second, voper);
  make_normal(super, voper);
  int sign_1 = 0, sign_2 = 0, result = 0;
  sign_1 = get_sign_big(super);
  sign_2 = get_sign_big(voper);
  if (sign_1 == 1 && sign_2 == 0) {
    result = -1;
  } else if (sign_1 == 0 && sign_2 == 1) {
    result = 1;
  } else {
    int i = 224;
    unsigned t1 = get_bit_big(*super, i);
    unsigned t2 = get_bit_big(*voper, i);
    while ((t1 == t2) && (i >= 0)) {
      i--;
      t1 = get_bit_big(*super, i);
      t2 = get_bit_big(*voper, i);
    }
    if (i == -1) {
      result = 0;
    } else if (sign_1 == 0 && sign_2 == 0) {
      if (t1 > t2)
        result = 1;
      else if (t1 < t2)
        result = -1;
    } else if (sign_1 == 1 && sign_2 == 1) {
      if (t1 > t2)
        result = -1;
      else if (t1 < t2)
        result = 1;
    }
  }
  free(super);
  free(voper);
  return result;
}

int shift_left_big(s21_big_decimal *val, int shift_val) {
  if (shift_val <= 0 || shift_val > 96) {
    return 1;
  }
  for (int i = 32 * 7 - shift_val; i >= 0; i--) {
    set_bit_big(val, i + shift_val, get_bit_big(*val, i));
    set_bit_big(val, i, 0);
  }

  return 0;
}

int shift_right_big(s21_big_decimal *val, int shift_val) {
  int ERROR = 0;
  if (shift_val < 0 || shift_val > 32)
    ERROR = 1;
  else {
    unsigned memory = 0;
    for (int i = 6; i >= 0; i--) {
      unsigned massiv = val->bits[i];
      val->bits[i] >>= shift_val;
      val->bits[i] |= memory;
      memory = massiv << (32 - shift_val);
    }
  }
  return ERROR;
}

// деление двух положительных чисел, целочисленное
void integer_div(s21_big_decimal val_1, s21_big_decimal val_2,
                 s21_big_decimal *res) {
  int sign_1 = get_sign_big(&val_1);
  int sign_2 = get_sign_big(&val_2);
  int shift = 0;
  set_sign_big(&val_1, 0);
  set_sign_big(&val_2, 0);
  make_normal(&val_1, &val_2);
  while (compare_big(&val_2, &val_1) != 1) {
    shift_left_big(&val_2, 1);
    shift++;
  }
  while (shift > 0 && !zero_big(&val_1)) {
    shift_right_big(&val_2, 1);
    shift_left_big(res, 1);
    shift--;
    if (compare_big(&val_2, &val_1) != 1) {
      bit_sub(val_1, val_2, &val_1);
      set_bit_big(res, 0, 1);
    } else
      set_bit_big(res, 224, 0);
  }
  while (shift) {
    shift_left_big(res, 1);
    shift--;
  }
  if (sign_1 != sign_2) set_sign_big(res, 1);
}

int s21_shift_big_dec_left(s21_big_decimal *dst, int num) {
  int ERROR = 0;
  int buffer[8] = {0};
  for (int k = 0; k < num; k++) {
    for (int i = 0; i < 7; i++) {
      buffer[i] = get_bit_big(*dst, (i + 1) * 32 - 1);
    }
    for (int i = 7; i > 0; i--) {
      // if (get_bit_big(*dst, 255)) ERROR = 1;
      dst->bits[i] <<= 1;
      set_bit_big(dst, i * 32, buffer[i - 1]);
    }
    dst->bits[0] <<= 1;
  }
  return ERROR;
}

void s21_shift_big_dec_right(s21_big_decimal *dst, int num) {
  int buffer[7] = {0};
  for (int k = 0; k < num; k++) {
    for (int i = 0; i < 7; i++) {
      buffer[i] = get_bit_big(*dst, (i + 1) * 32);
    }
    for (int i = 0; i < 7; i++) {
      dst->bits[i] >>= 1;
      set_bit_big(dst, (i + 1) * 32 - 1, buffer[i]);
    }
    dst->bits[7] >>= 1;
  }
}

void initt_decimal(s21_decimal *d) {
  d->bits[0] = 0u;
  d->bits[1] = 0u;
  d->bits[2] = 0u;
  d->bits[3] = 0u;
}

int get_exp(s21_decimal d) {
  return (d.bits[3] & 0x00FF0000) >> 16;  // ислоьзование маски и смещения влево
                                          // для получения инта экспоненты
}
