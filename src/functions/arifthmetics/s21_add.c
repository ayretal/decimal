#include "../../s21_addition.h"

int s21_add(s21_decimal val_1, s21_decimal val_2, s21_decimal *result) {
  decimal_null(result);
  int ERROR = 0;
  // if (!is_correct(&val_1) || !is_correct(&val_2))
  //   ERROR = 1;
  // else
  if (zero(val_1)) {
    paste(&val_2, result);  ///
  } else if (zero(val_2)) {
    paste(&val_1, result);
  } else {
    int sing_1 = get_sign(val_1);
    int sign_2 = get_sign(val_2);
    if (sing_1 != sign_2) {
      if (sign_2 == 1) {
        set_sign(&val_2, 0);
        ERROR = s21_sub(val_1, val_2, result);
      } else {
        set_sign(&val_1, 0);
        ERROR = s21_sub(val_2, val_1, result);
      }
    } else {
      s21_big_decimal *val_big_1 = init_big();
      s21_big_decimal *val_big_2 = init_big();
      s21_big_decimal *result_big = init_big();
      to_big(&val_1, val_big_1);  //
      to_big(&val_2, val_big_2);  //
      s21_add_big(*val_big_1, *val_big_2, result_big);
      ERROR = is_there_overflow(result_big, result);
      free(val_big_1);
      free(val_big_2);
      free(result_big);
    }
  }
  return ERROR;
}

// сложение двух положительных чисел
int s21_add_big(s21_big_decimal val1, s21_big_decimal val2,
                s21_big_decimal *res) {
  if (get_sign_big(&val1) == get_sign_big(&val2)) {
    make_normal(&val1, &val2);
    bit_add(val1, val2, res);
  } else
    return 1;
  return 0;
}
