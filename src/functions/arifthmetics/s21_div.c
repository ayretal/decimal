#include "../../s21_addition.h"

int non_integer_div(s21_decimal val1, s21_decimal val2, s21_decimal *result) {
  s21_big_decimal helping = {0}, val_1, val_2, res = {0};
  int scale = 0, error = 0;
  to_big(&val1, &val_1);
  to_big(&val2, &val_2);

  while (!zero_big(&val_1) && scale < 29) {
    int shift = 0;
    level_up_scale(&res, 1);
    decimall_null_big(&helping);
    to_big(&val2, &val_2);
    set_sign_big(&val_1, 0);
    set_sign_big(&val_2, 0);
    while (compare_big(&val_2, &val_1) != 1) {
      shift_left_big(&val_2, 1);
      shift++;
    }
    while (shift > 0 && !zero_big(&val_1)) {
      shift_right_big(&val_2, 1);
      shift_left_big(&helping, 1);
      shift--;
      if (compare_big(&val_2, &val_1) != 1) {
        bit_sub(val_1, val_2, &val_1);
        set_bit_big(&helping, 0, 1);
      } else
        set_bit_big(&helping, 224, 0);
    }
    while (shift) {
      shift_left_big(&helping, 1);
      shift--;
    }
    s21_add_big(helping, res, &res);
    scale++;
    level_up_scale(&val_1, 1);
  }
  set_scale_big(&res, scale - 1);
  if ((get_sign(val1) != get_sign(val2)) && !zero_big(&res))
    set_sign_big(&res, 1);
  error = is_there_overflow(&res, result);
  return error;
}

int s21_div(s21_decimal val1, s21_decimal val2, s21_decimal *result) {
  int error = 0;
  if (zero(val2)) return ERROR_DIV_ZERO;
  decimal_null(result);
  if (zero(val1)) return OK;
  error = non_integer_div(val1, val2, result);
  return error;
}