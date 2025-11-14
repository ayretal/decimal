#include "../../s21_addition.h"
#include "../../s21_decimal.h"

void bit_binary(unsigned int chis,
                int *result) {  // добавить проверки, проверка на положительный
                                // знак, если число = 0
  int array[32] = {0};
  int flag = 0;
  while (chis > 0) {
    array[flag] = chis % 2;
    chis = chis / 2;
    flag++;
  }
  for (int i = 31; i >= 0; i--) {
    result[31 - i] = array[i];
  }
}

void full_binary(s21_decimal value, int *result) {
  int bit0[32] = {0};
  int bit1[32] = {0};
  int bit2[32] = {0};
  bit_binary(value.bits[0], bit0);
  bit_binary(value.bits[1], bit1);
  bit_binary(value.bits[2], bit2);
  for (int i = 0; i < 32; i++) {
    result[i] = bit2[i];
    result[i + 32] = bit1[i];
    result[i + 64] = bit0[i];
  }
}

int get_power(s21_decimal value) {
  int bit3[32] = {0};
  bit_binary(value.bits[3], bit3);
  int power = bit3[15] + bit3[14] * 2 + bit3[13] * 4 + bit3[12] * 8 +
              bit3[11] * 16 + bit3[10] * 32 + bit3[9] * 64 + bit3[8] * 128;
  return power;
}

unsigned int bit_to_unsigned(int const *bit) {
  unsigned int itog = 0, mult = 1;
  for (int i = 31; i >= 0; i--) {
    itog = itog + bit[i] * mult;
    if (i == 0) {
      break;
    }
    mult = mult * 2;
  }
  return itog;
}

int index_first(int const *value) {
  int index = 0;
  for (int i = 0; i < 96; i++) {
    if (value[i] == 1) {
      index = i;
      break;
    }
  }
  return index;
}

// рекурсивно делит число на 1010 (10 в десятичной), пока степерь не станет
// равна нулю
void divide(int const *before, int *result, int power) {
  if (power != 0) {
    int arr[96];
    for (int i = 0; i < 96; i++) {
      arr[i] = 2;
    }
    int arr2[96];
    int buff[96] = {0};
    for (int i = 0; i < 96; i++) {
      arr2[i] = before[i];
    }
    // определяем индекс начала числа
    int index = index_first(before), flag = 0, flag2 = 95;
    // генерируем число, деленное на 1010 (10 в десятичной)
    for (int i = index + 3; i < 96; i++) {
      if (arr2[i - 3] == 1 && arr2[i - 2] == 1 && arr2[i - 1] == 1 &&
          (arr2[i] == 1 || arr2[i] == 0)) {
        arr2[i - 3] = 0;
        arr2[i - 1] = 0;
        arr[flag] = 1;
        flag++;
        continue;
      }
      if (arr2[i - 3] == 1 && arr2[i - 2] == 1 && arr2[i - 1] == 0 &&
          (arr2[i] == 1 || arr2[i] == 0)) {
        arr2[i - 3] = 0;
        arr2[i - 2] = 0;
        arr2[i - 1] = 1;
        arr[flag] = 1;
        flag++;
        continue;
      }
      if (arr2[i - 3] == 1 && arr2[i - 2] == 0 && arr2[i - 1] == 1 &&
          (arr2[i] == 1 || arr2[i] == 0)) {
        arr2[i - 3] = 0;
        arr2[i - 1] = 0;
        arr[flag] = 1;
        flag++;
        continue;
      }
      if (arr2[i - 3] == 1 && arr2[i - 2] == 0 && arr2[i - 1] == 0 &&
          arr2[i] == 1) {
        arr[flag] = 0;
        flag++;
        continue;
      }
      if (arr2[i - 3] == 1 && arr2[i - 2] == 0 && arr2[i - 1] == 0 &&
          arr2[i] == 0) {
        arr[flag] = 0;
        flag++;
        continue;
      }
      if (arr2[i - 3] == 0 && arr2[i - 2] == 1 && arr2[i - 1] == 1 &&
          arr2[i] == 0) {
        arr[flag] = 0;
        flag++;
        continue;
      }
      if (arr2[i - 3] == 0 && arr2[i - 2] == 1 && arr2[i - 1] == 0 &&
          arr2[i] == 1) {
        arr[flag] = 0;
        flag++;
        continue;
      }
      if (arr2[i - 3] == 0 && arr2[i - 2] == 1 && arr2[i - 1] == 0 &&
          arr2[i] == 0) {
        arr[flag] = 0;
        flag++;
        continue;
      }
      if (arr2[i - 3] == 0 && (arr2[i - 2] == 0 || arr2[i - 2] == 1) &&
          arr2[i - 1] == 1 && arr2[i] == 1) {
        if (i != 3 && arr2[i - 4] == 1) {
          arr2[i - 4] = 0;
          arr2[i - 3] = 1;
          arr2[i - 1] = 0;
          arr[flag] = 1;
          flag++;
          continue;
        } else {
          arr[flag] = 0;
          flag++;
          continue;
        }
      }
      if (arr2[i - 3] == 0 && arr2[i - 2] == 0 && arr2[i - 1] == 1 &&
          arr2[i] == 0) {
        if (i != 3 && arr2[i - 4] == 1) {
          arr2[i - 4] = 0;
          arr2[i - 3] = 1;
          arr2[i - 1] = 0;
          arr[flag] = 1;
          flag++;
          continue;
        } else {
          arr[flag] = 0;
          flag++;
          continue;
        }
      }
      if (arr2[i - 3] == 0 && arr2[i - 2] == 0 && arr2[i - 1] == 0 &&
          (arr2[i] == 1 || arr2[i] == 0)) {
        if (i != 3 && arr2[i - 4] == 1) {
          arr2[i - 2] = 1;
          arr2[i - 1] = 1;
          arr[flag] = 1;
          flag++;
          continue;
        } else {
          arr[flag] = 0;
          flag++;
          continue;
        }
      }
    }
    // записываем новое число в правильной форме
    for (int i = 95; i > -1; i--) {
      if (arr[i] != 2) {
        buff[flag2] = arr[i];
        flag2--;
      }
    }
    power--;
    divide(buff, result, power);
  }
  // если степень равна 0, записываем получившееся число
  else {
    for (int i = 0; i < 96; i++) {
      result[i] = before[i];
    }
  }
}

int correct_value(s21_decimal value) {
  int flag = 1;
  int bit3[32] = {0};
  bit_binary(value.bits[3], bit3);
  for (int i = 1; i < 32; i++) {
    if (i == 8) {
      i = 16;
    }
    if (bit3[i] == 1) {
      flag = 0;
      break;
    }
  }
  int power = get_power(value);
  if (power > 28) {
    flag = 0;
  }
  return flag;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int ERROR = 0;
  if (!result) {  // указатель на decimal is null
    ERROR = 1;
  } else if (!correct_value(value)) {
    ERROR = 1;
  } else {  // все нормально
    int bin_before[96];
    full_binary(value, bin_before);
    int power = get_power(value);
    int bin_after[96] = {0};
    divide(bin_before, bin_after, power);
    int bit0[32] = {0};
    int bit1[32] = {0};
    int bit2[32] = {0};
    int bit3[32] = {0};
    for (int i = 0; i < 32; i++) {
      bit2[i] = bin_after[i];
      bit1[i] = bin_after[i + 32];
      bit0[i] = bin_after[i + 64];
    }
    bit_binary(value.bits[3], bit3);
    for (int i = 1; i < 32; i++) {
      bit3[i] = 0;
    }
    // s21_decimal result;
    result->bits[0] = bit_to_unsigned(bit0);
    result->bits[1] = bit_to_unsigned(bit1);
    result->bits[2] = bit_to_unsigned(bit2);
    result->bits[3] = bit_to_unsigned(bit3);
  }
  return ERROR;
}

int chetno(s21_decimal value) {  // 1 если да, 0 если нет
  s21_decimal dva = {0}, clear, ostatok, copy;
  dva.bits[0] = 2;
  s21_truncate(value, &clear);
  s21_div(clear, dva, &copy);
  s21_truncate(copy, &clear);
  s21_sub(copy, clear, &ostatok);
  int bin_ostatok[96];
  full_binary(ostatok, bin_ostatok);
  int flag = 1;
  for (int i = 0; i < 96; i++) {
    if (bin_ostatok[i] == 1) {
      flag = 0;
      break;
    }
  }
  return flag;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int ERROR = 0;
  if (!result) {  // указатель на decimal is null
    ERROR = 1;
  } else if (!correct_value(value)) {
    ERROR = 1;
  } else {  // все нормально
    int bit3[32] = {0};
    bit_binary(value.bits[3], bit3);
    if (bit3[0] == 1) {
      bit3[0] = 0;
    } else {
      bit3[0] = 1;
    }
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = bit_to_unsigned(bit3);
  }
  return ERROR;
}

int s21_floor(s21_decimal value,
              s21_decimal *result) {  // Округляет указанное Decimal число до
                                      // ближайшего целого числа в сторону
                                      // отрицательной бесконечности
  int ERROR = 0;
  if (!result) {  // указатель на decimal is null
    ERROR = 1;
  } else if (!correct_value(value)) {
    ERROR = 1;
  } else {
    int sign = get_sign(value);
    s21_decimal copy, clear = {0};
    paste(&value, &copy);
    if (sign == 1) {
      s21_negate(copy, &copy);
    }
    s21_truncate(copy, &clear);
    if (sign == 1) {
      s21_decimal ostatok;
      s21_sub(copy, clear, &ostatok);
      int bin_ostatok[96];
      full_binary(ostatok, bin_ostatok);
      int flag = 0;
      for (int i = 0; i < 96; i++) {
        if (bin_ostatok[i] == 1) {
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        s21_decimal one = {0};
        one.bits[0] = 1;
        s21_add(clear, one, &clear);
      }
      s21_negate(clear, &clear);
    }
    paste(&clear, result);
  }
  return ERROR;
}

int s21_round(
    s21_decimal value,
    s21_decimal *result) {  // Округляет Decimal до ближайшего целого числа
  int ERROR = 0;
  if (!result) {  // указатель на decimal is null
    ERROR = 1;
  } else if (!correct_value(value)) {
    ERROR = 1;
  } else {
    s21_decimal porog = {0}, copy, clear = {0}, ostatok = {0}, one = {0};
    porog.bits[0] = 5;
    porog.bits[3] = 65536;
    one.bits[0] = 1;
    int sign = get_sign(value);
    int chet = chetno(value);
    paste(&value, &copy);
    if (sign == 1) {
      s21_negate(copy, &copy);
    }
    s21_truncate(copy, &clear);
    s21_sub(copy, clear, &ostatok);
    int flag1 = s21_is_equal(ostatok, porog);
    int flag2 = s21_is_greater(ostatok, porog);
    if (flag1 == 1 && chet == 0) {
      s21_add(clear, one, &clear);
    }
    if (flag2 == 1) {
      s21_add(clear, one, &clear);
    }
    if (sign == 1) {
      s21_negate(clear, &clear);
    }
    paste(&clear, result);
  }
  return ERROR;
}