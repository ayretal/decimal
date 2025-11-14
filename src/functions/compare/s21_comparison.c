#include "../../s21_addition.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_comparison(value_1, value_2) == 0) ? 1 : 0;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_comparison(value_1, value_2) == 0) ? 0 : 1;
}

//
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = (compare(&value_1, &value_2) > 0) ? 1 : 0;
  return result;
}

//
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = (compare(&value_1, &value_2) >= 0) ? 1 : 0;
  return result;
}

//
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = (compare(&value_1, &value_2) < 0) ? 1 : 0;
  return result;
}

//
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = (compare(&value_1, &value_2) <= 0) ? 1 : 0;
  return result;
}

/// @brief изменение флага на противоложный
/// @param flag
void s21_comparison_reverse(int *flag) {
  if (*flag == 1) {
    *flag = 2;
  } else if (*flag == 2) {
    *flag = 1;
  }
}

/// @brief поиск наибольшего числа
/// @param a
/// @param b
/// @return возвращает 0, 1, 2, если a = b, a > b, a < b соответсвенно
int s21_greater_num(int a, int b) {
  int flag = 0;
  if (a > b) {
    flag = 1;
  } else if (a < b) {
    flag = 2;
  } else  // if (a == b) {
    flag = 0;
  return flag;
}

/// @brief побитовое сравнение двух decimal
/// @param value_1
/// @param value_2
/// @return
int s21_comparison_bits(s21_decimal value_1, s21_decimal value_2) {
  // int bit1 = 0;
  // int bit2 = 0;
  int flag = 0;
  for (int i = 95; i >= 0 && !flag; --i) {
    int bit1 = s21_get_bit(value_1, i);
    int bit2 = s21_get_bit(value_2, i);
    if (bit1 > bit2) {
      flag = 1;
    } else if (bit1 < bit2) {
      flag = 2;
    }
  }
  return flag;
}

/// @brief Преобразователи
/// @param value_1
/// @param value_2
/// @return 0, 1, 2, если value_1 = value_2, value_1 > value_2, value_1 <
/// value_2 соответсвенно
int s21_comparison(s21_decimal value_1, s21_decimal value_2) {
  float f1 = 0.0;
  float f2 = 0.0;
  s21_from_decimal_to_float(value_1, &f1);
  s21_from_decimal_to_float(value_2, &f2);
  s21_from_float_to_decimal(f1, &value_1);
  s21_from_float_to_decimal(f2, &value_2);
  int flag = 0;
  int scale_dif = (get_scale(value_1) - get_scale(value_2));
  s21_normalize(&value_1, &value_2);
  flag = s21_greater_num(!get_sign(value_1), !get_sign(value_2));
  if (flag == 0) {
    if (scale_dif >= 0) {
      flag = s21_comparison_bits(value_1, value_2);
    } else {
      // scale_dif = -scale_dif;
      flag = s21_comparison_bits(value_2, value_1);
      s21_comparison_reverse(&flag);
    }
    if (get_sign(value_1) && get_sign(value_2)) {
      s21_comparison_reverse(&flag);
    }
  } else {
    if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0 &&
        value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
      flag = 0;
    }
  }
  return flag;
}