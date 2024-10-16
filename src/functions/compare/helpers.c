#include "../../s21_addition.h"

// // печатает число в двоичном представлении
// void print_binary(int num) {
//   for (int i = 31; i >= 0; i--) {
//     printf("%d", (num >> i) & 1);
//   }
//   printf("\n");
// }

// // печатает весь децимал побитово
// void print_decimal(s21_decimal num) {
//   for (int i = 3; i >= 0; i--) {
//     print_binary(num.bits[i]);
//   }
//   printf("\n");
// }

// возвращает значение бита в заданной позиции
int s21_get_bit(s21_decimal num, int pos) {
  return (num.bits[pos / 32] &= (1 << pos)) >> pos;
}

/**
 * @brief меняет значение бита
 *
 * @param num наша структура
 * @param pos номер позиции, где требуется замена (0 <= pos <= 127)
 * @param bit на какое значение требуется замена (0 or 1)
 */
void s21_set_bit(s21_decimal *num, int pos, int bit) {
  int i;
  if (pos >= 0 && pos <= 31)
    i = 0;
  else if (pos >= 32 && pos <= 63)
    i = 1;
  else if (pos >= 64 && pos <= 95)
    i = 2;
  else if (pos >= 96 && pos <= 127)
    i = 3;
  if (bit == 1) {
    num->bits[i] |= (1 << pos);
  } else if (bit == 0) {
    num->bits[i] &= ~(1 << pos);
  }
}

void set_minus(s21_decimal *num) { s21_set_bit(num, 127, 1); }

void set_plus(s21_decimal *num) { s21_set_bit(num, 127, 0); }

s21_decimal binary_and(s21_decimal num1, s21_decimal num2) {
  s21_decimal result = {0};
  result.bits[0] = num1.bits[0] & num2.bits[0];
  result.bits[1] = num1.bits[1] & num2.bits[1];
  result.bits[2] = num1.bits[2] & num2.bits[2];
  result.bits[3] = num1.bits[3] & num2.bits[3];

  return result;
}

s21_decimal binary_xor(s21_decimal num1, s21_decimal num2) {
  s21_decimal result = {0};
  result.bits[0] = num1.bits[0] ^ num2.bits[0];
  result.bits[1] = num1.bits[1] ^ num2.bits[1];
  result.bits[2] = num1.bits[2] ^ num2.bits[2];
  result.bits[3] = num1.bits[3] ^ num2.bits[3];

  return result;
}

s21_decimal shift_left_one(s21_decimal num) {
  s21_decimal result = {0};

  unsigned int result0 = num.bits[0];
  result0 = result0 << 1;
  result.bits[0] = result0;

  unsigned int result1 = num.bits[1];
  result1 = result1 << 1;
  result.bits[1] = result1;

  unsigned int result2 = num.bits[2];
  result2 = result2 << 1;
  result.bits[2] = result2;

  unsigned int result3 = num.bits[3];
  result3 = result3 << 1;
  result.bits[3] = result3;

  return result;
}

s21_decimal shif_left(s21_decimal num, int shift) {
  s21_decimal result = num;
  while (shift > 0) {
    result = shift_left_one(result);
    --shift;
  }
  return result;
}

int binary_equal_zero(s21_decimal num) {
  return num.bits[0] == 0 && num.bits[1] == 0 && num.bits[2] == 0 &&
         num.bits[3] == 0;
}

s21_decimal binary_addition(s21_decimal num1, s21_decimal num2) {
  s21_decimal result = num1;
  s21_decimal tmp = num2;

  while (!binary_equal_zero(tmp)) {
    // s21_decimal overflow_bits = binary_and(result, tmp);
    // overflow_bits = shif_left(overflow_bits, 1);
    result = binary_xor(result, tmp);
  }
  return result;
}

/// @brief Установка знака
/// @param dst
void s21_set_sign(s21_decimal *dst) { dst->bits[3] = dst->bits[3] | 1u << 31; }

/// @brief Обнуление decimal
/// @param dst
void s21_zero_decimal(s21_decimal *dst) {
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
}

/// @brief Копирование d2 в d1
/// @param d1
/// @param d2
void s21_copy_decimal(s21_decimal *d1, s21_decimal d2) {
  for (int i = 127; i >= 0; i--) {
    s21_set_bit(d1, i, s21_get_bit(d2, i));
  }
}

int s21_s21_get_bit_big(s21_big_decimal dst, int index) {
  int mask = 1u << (index % 32);
  return (dst.bits[index / 32] & mask) != 0;
}

/// @brief Установить бит в большой структуре
/// @param dst
/// @param index
/// @param bit
void s21_s21_set_bit_big(s21_big_decimal *dst, int index, int bit) {
  int mask = 1u << (index % 32);
  if (bit == 0)
    dst->bits[index / 32] = dst->bits[index / 32] & ~mask;
  else
    dst->bits[index / 32] = dst->bits[index / 32] | mask;
}

// Сложение в формате большого децимала
void s21_add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result) {
  int ovf = 0;
  for (int i = 0; i < 256; i++) {
    int res =
        s21_s21_get_bit_big(value_1, i) + s21_s21_get_bit_big(value_2, i) + ovf;
    ovf = res / 2;
    s21_s21_set_bit_big(result, i, res % 2);
  }
}

/// @brief Сдвиг big decimal влево +
/// @param dst
/// @param num
/// @return
// int s21_shift_big_dec_left(s21_big_decimal *dst, int num) {
//   int error = 0;
//   int buffer[8] = {0};
//   for (int k = 0; k < num; k++) {
//     for (int i = 0; i < 7; i++) {
//       buffer[i] = s21_s21_get_bit_big(*dst, (i + 1) * 32 - 1);
//     }
//     for (int i = 7; i > 0 && !error; i--) {
//       if (s21_s21_get_bit_big(*dst, 255)) error = 1;
//       dst->bits[i] <<= 1;
//       s21_s21_set_bit_big(dst, i * 32, buffer[i - 1]);
//     }
//     dst->bits[0] <<= 1;
//   }
//   return error;
// }

/// @brief Сдвиг big decimal вправо +
/// @param dst
/// @param num
// void s21_shift_big_dec_right(s21_big_decimal *dst, int num) {
//   int buffer[7] = {0};
//   for (int k = 0; k < num; k++) {
//     for (int i = 0; i < 7; i++) {
//       buffer[i] = s21_s21_get_bit_big(*dst, (i + 1) * 32);
//     }
//     for (int i = 0; i < 7; i++) {
//       dst->bits[i] >>= 1;
//       s21_s21_set_bit_big(dst, (i + 1) * 32 - 1, buffer[i]);
//     }
//     dst->bits[7] >>= 1;
//   }
// }

// int s21_mul_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
//                         s21_big_decimal *result) {
//   int error = 0, count = 0;
//   for (int i = 0; i < 256 && !error; i++) {
//     if (s21_s21_get_bit_big(value_2, i)) {
//       error = s21_shift_big_dec_left(&value_1, i - count);
//       s21_add_big_decimal(value_1, *result, result);
//       count = i;
//     }
//   }
//   return error;
// }

/// @brief Перенос данных из decimal в big decimal
/// @param value_1
/// @param value_2
void s21_import_to_big_decimal(s21_decimal value_1, s21_big_decimal *value_2) {
  value_2->bits[0] = value_1.bits[0];
  value_2->bits[1] = value_1.bits[1];
  value_2->bits[2] = value_1.bits[2];
}

/// @brief Перенос данных из big decimal в decimal
/// @param value_1
/// @param value_2
void s21_import_to_small_decimal(s21_decimal *value_1,
                                 s21_big_decimal value_2) {
  value_1->bits[0] = value_2.bits[0];
  value_1->bits[1] = value_2.bits[1];
  value_1->bits[2] = value_2.bits[2];
}

/// @brief  Поиск наибольшего бита в big decimal
/// @param v1
/// @param v2
/// @param bit_1
/// @param bit_2
void s21_find_highest_bit_big_decimal(s21_big_decimal v1, s21_big_decimal v2,
                                      int *bit_1, int *bit_2) {
  for (int i = 255; i >= 0 && (!(*bit_1) || !(*bit_2)); i--) {
    if (*bit_1 == 0 && s21_s21_get_bit_big(v1, i)) *bit_1 = i;
    if (*bit_2 == 0 && s21_s21_get_bit_big(v2, i)) *bit_2 = i;
  }
}

/// @brief Проверка на пустоту
/// @param dst
/// @return 0 или число большее 0
int s21_is_big_decimal_not_empty(s21_big_decimal dst) {
  return dst.bits[0] + dst.bits[1] + dst.bits[2] + dst.bits[3] + dst.bits[4] +
         dst.bits[5] + dst.bits[6] + dst.bits[7];
}

/// @brief Увеличение scale big decimal на n
/// @param dst
/// @param n
void s21_increase_scale_big_decimal(s21_big_decimal *dst, int n) {
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}}, tmp = {0};
  for (int i = 0; i < n; i++) {
    s21_mul_big_decimal(*dst, ten, &tmp);
    *dst = tmp;
    s21_zero_big_decimal(&tmp);
  }
}

/// @brief Обнуление big decimal
/// @param dst
void s21_zero_big_decimal(s21_big_decimal *dst) {
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = dst->bits[4] =
      dst->bits[5] = dst->bits[6] = dst->bits[7] = 0;
}

/// @brief Больше
/// @param value_1
/// @param value_2
/// @return 0 - если < , 1 - если >
int s21_is_greater_big_decimal(s21_big_decimal value_1,
                               s21_big_decimal value_2) {
  int result = 0, out = 0;
  for (int i = 7; i >= 0 && !result && !out; i--) {
    if (value_1.bits[i] || value_2.bits[i]) {
      if (value_1.bits[i] > value_2.bits[i]) {
        result = 1;
      }
      if (value_1.bits[i] != value_2.bits[i]) out = 1;
    }
  }
  return result;
}

/// @brief Больше или равно
/// @param value_1
/// @param value_2
/// @return 0 - если < , 1 - если >=
int s21_is_greater_or_equal_big_decimal(s21_big_decimal value_1,
                                        s21_big_decimal value_2) {
  int result = 0, out = 0;
  for (int i = 7; i >= 0 && !out && !result; i--) {
    if (value_1.bits[i] != 0 || value_2.bits[i] != 0) {
      if (value_1.bits[i] >= value_2.bits[i]) {
        result = 1;
      }
      out = 1;
    }
  }
  return result;
}

/// @brief Уравнение big decimal
/// @param value_1
/// @param value_2
/// @return scale
int s21_equation_bits_big_decimal(s21_big_decimal *value_1,
                                  s21_big_decimal *value_2) {
  int scale = 0;
  while (s21_is_greater_big_decimal(*value_2, *value_1)) {
    s21_increase_scale_big_decimal(value_1, 1);
    scale++;
  }
  while (s21_is_greater_or_equal_big_decimal(*value_1, *value_2)) {
    s21_shift_big_dec_left(value_2, 1);
  }
  s21_shift_big_dec_right(value_2, 1);
  return scale;
}

// Вычитание в формате большого децимала
void s21_sub_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result) {
  int tmp = 0;
  for (int i = 0; i < 256; i++) {
    int res =
        s21_s21_get_bit_big(value_1, i) - s21_s21_get_bit_big(value_2, i) - tmp;
    tmp = res < 0;
    res = abs(res);
    s21_s21_set_bit_big(result, i, res % 2);
  }
}

/// @brief Деление big decimal
/// @param value_1
/// @param value_2
/// @param result
/// @return 0 - OK 1 - число слишком велико или равно бесконечности 2 - число
/// слишком мало или равно отрицательной бесконечности 3 - деление на 0

int s21_div_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  int b_1 = 0, b_2 = 0, bit_2 = 0, save_scale = 0;
  s21_big_decimal tmp = {0};
  s21_find_highest_bit_big_decimal(value_1, value_2, &b_1, &b_2);
  bit_2 = b_2;
  for (int i = 0; i < 96 && s21_is_big_decimal_not_empty(value_1);) {
    if (i > 0) {
      s21_shift_big_dec_left(&value_2, 1);
      s21_increase_scale_big_decimal(result, 1);
      s21_increase_scale_big_decimal(&value_1, 1);
      save_scale++;
    }
    int scale = s21_equation_bits_big_decimal(&value_1, &value_2);
    save_scale += scale;
    b_1 = b_2 = 0;
    s21_find_highest_bit_big_decimal(value_1, value_2, &b_1, &b_2);
    int diff = b_2 - bit_2;
    if (diff < 0) diff = 0;
    for (; diff >= 0 && s21_is_big_decimal_not_empty(value_1);) {
      if (s21_is_greater_big_decimal(value_2, value_1)) {
        s21_s21_set_bit_big(&tmp, 0, 0);
      } else {
        s21_sub_big_decimal(value_1, value_2, &value_1);
        s21_s21_set_bit_big(&tmp, 0, 1);
      }
      i++;
      diff--;
      if (diff >= 0) s21_shift_big_dec_right(&value_2, 1);
      s21_shift_big_dec_left(&tmp, 1);
    }
    if (diff >= 0) s21_shift_big_dec_left(&tmp, diff + 1);
    s21_shift_big_dec_right(&tmp, 1);
    s21_add_big_decimal(*result, tmp, result);
    s21_zero_big_decimal(&tmp);
  }
  return save_scale;
}

/// @brief Уменьшение scale big decimal на n
/// @param dst
/// @param n
void s21_decreace_scale_big_decimal(s21_big_decimal *dst, int n) {
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}}, tmp = {0};
  for (int i = 0; i < n; i++) {
    s21_div_big_decimal(*dst, ten, &tmp);
    *dst = tmp;
    s21_zero_big_decimal(&tmp);
  }
}

/// @brief Пост нормализация для big decimal
/// @param result
/// @param scale
/// @return Число больше, равно или меньше нуля
// int s21_post_normalization(s21_big_decimal *result, int scale) {
//   int dop = 0;
//   while ((result->bits[3] || result->bits[4] || result->bits[5] ||
//           result->bits[6] || result->bits[7]) &&
//          scale > 0) {
//     if (scale == 1 && result->bits[3]) dop = 1;
//     s21_decreace_scale_big_decimal(result, 1);
//     scale--;
//   }
//   if (dop && scale == 0 && result->bits[3] == 0 &&
//   s21_s21_get_bit_big(*result, 0))
//     s21_s21_set_bit_big(result, 0, 0);
//   if ((result->bits[3] || result->bits[4] || result->bits[5] ||
//        result->bits[6] || result->bits[7]))
//     scale = -1;
//   return scale;
// }

/// @brief Умножение
/// @param value_1
/// @param value_2
/// @param result
/// @return 0 - OK 1 - число слишком велико или равно бесконечности 2 - число
/// слишком мало или равно отрицательной бесконечности
// int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
//   int error = 0, scale = 0;
//   s21_big_decimal v1 = {0}, v2 = {0}, r = {0};
//   s21_import_to_big_decimal(value_1, &v1);
//   s21_import_to_big_decimal(value_2, &v2);
//   if (s21_get_sign(value_1) != s21_get_sign(value_2)) s21_set_sign(result);
//   scale = get_scale(value_1) + get_scale(value_2);
//   error = s21_mul_big_decimal(v1, v2, &r);
//   scale = s21_post_normalization(&r, scale);
//   if (scale >= 0) {
//     s21_set_scale(result, scale);
//     s21_import_to_small_decimal(result, r);
//   } else {
//     error = 1;
//   }
//   if (error == 1 && s21_get_sign(*result)) error = 2;
//   if (error) s21_zero_decimal(result);
//   return error;
// }

/// @brief Повышение scale на norm
/// @param d
/// @param norm
void s21_normalize_scale_upper(s21_decimal *d, int norm) {
  s21_decimal _norm = {0};
  s21_decimal _res = {0};
  s21_from_float_to_decimal(pow(10, norm), &_norm);
  s21_mul(*d, _norm, &_res);
  set_scale(&_res, get_scale(*d) + norm);
  s21_copy_decimal(d, _res);
}

/// @brief Нормализация d1 d2 путем уравнения их scale
/// @param d1
/// @param d2
void s21_normalize(s21_decimal *d1, s21_decimal *d2) {
  int norm = get_scale(*d1) - get_scale(*d2);
  if (norm > 0) {
    s21_normalize_scale_upper(d2, norm);
  } else if (norm < 0) {
    s21_normalize_scale_upper(d1, -norm);
  }
}

union data {
  float f;
  int x;
};

int s21_get_bitt(int num, int ind) { return (num & (1 << ind)) ? 1 : 0; }

int s21_count_exp(float src) {
  union data data;
  data.f = src;
  int expon = ((data.x & EXP) >> 23);
  return expon;
}

int s21_get_sign_from_float(float src) {
  union data data;
  data.f = src;
  return s21_get_bitt(data.x, 31);
}

int s21_divide_10_float(s21_decimal *dst) {
  s21_decimal tmp = {0};
  for (int i = 0; i < 3; i++) tmp.bits[i] = dst->bits[i];
  return !s21_10_division(&tmp);
}

int s21_10_division(s21_decimal *dst) {
  int mod = 0;
  for (int i = 2; i >= 0; i--) {
    long long int tmp = dst->bits[i] + ((long long)(mod) << 32);
    mod = tmp % 10;
    dst->bits[i] = tmp / 10;
  }
  return mod;
}
