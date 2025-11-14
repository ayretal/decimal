#include "../../s21_addition.h"

int s21_sub(s21_decimal v1, s21_decimal v2, s21_decimal *result) {
  int ERROR = 0;
  decimal_null(result);
  // if (is_correct(&v1) || is_correct(&v2)) //правильность записи
  //    ERROR = 1;
  // else {
  if (zero(v2))
    paste(&v1, result);
  else if (zero(v1)) {
    paste(&v2, result);
    set_sign(result, !get_sign(v2));
  } else if (!compare(&v1, &v2))
    decimal_null(result);
  else if (get_sign(v1) != get_sign(v2)) {
    set_sign(&v2, !get_sign(v2));
    ERROR = s21_add(v1, v2, result);
  } else {
    s21_big_decimal big_v1, big_v2, big_result = {0};
    to_big(&v1, &big_v1);
    to_big(&v2, &big_v2);
    make_normal(&big_v1, &big_v2);
    int sign_1 = get_sign_big(&big_v1);
    set_sign_big(&big_v1, 0);
    set_sign_big(&big_v2, 0);
    if (compare_big(&big_v1, &big_v2) > 0) {
      bit_sub(big_v1, big_v2, &big_result);
      if (sign_1 == 1) set_sign_big(&big_result, 1);
    } else {
      bit_sub(big_v2, big_v1, &big_result);
      if (sign_1 == 0) set_sign_big(&big_result, 1);
    }
    set_scale_big(&big_result, get_scale_big(&big_v1));
    ERROR = is_there_overflow(&big_result, result);
  }
  // }
  return ERROR;
}

// ищет первый ненулевой бит
int get_first_bit(s21_big_decimal value) {
  int place = 0;
  for (int i = 223; i >= 0; i--) {
    int bit = get_bit_big(value, i);
    if (bit == 1) {
      place = i;
      break;
    }
  }
  return place;
}
