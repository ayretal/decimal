#include "../../s21_addition.h"

int s21_mul_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  int ERROR = 0, count = 0;
  for (int i = 0; i < 256 && !ERROR; i++) {
    if (get_bit_big(value_2, i)) {
      ERROR = s21_shift_big_dec_left(&value_1, i - count);
      s21_add_big(value_1, *result, result);
      count = i;
    }
  }
  return ERROR;
}

int degr_num(s21_decimal value) {
  return (value.bits[3] - MINUS * (value.bits[3] / MINUS)) / pow(2, 16);
}

void if_it_full(long long *save_value, s21_decimal *result) {
  if ((long)result->bits[1] + 1 >= 2 * MINUS) {
    if ((long)result->bits[2] + 1 >= 2 * MINUS) {
      (*save_value) += 1;
    }
    result->bits[2] += 1;
  }
  result->bits[1] += 1;
}

void work_with_rounding(long long *save_value, s21_decimal value_1,
                        s21_decimal value_2, s21_decimal *result) {
  while ((*save_value || degr_num(*result) > 28) && degr_num(*result) > 0) {
    int mod_save_value = *save_value % 10;
    *save_value /= 10;
    for (int bits_part = 2; bits_part != -1; bits_part--) {
      long long sub = result->bits[bits_part] + (mod_save_value)*pow(2, 32);
      if (bits_part == 0 &&
          ((sub % 10 == 5 && ((sub / 10) % 10) % 2 == 1) || sub % 10 > 5)) {
        sub += 10;
      }
      mod_save_value = sub % 10;
      result->bits[bits_part] = sub / 10;
      if (sub / 10 >= 2 * MINUS) {
        if_it_full(save_value, result);
      }
    }
    result->bits[3] -= pow(2, 16);
  }
  if (value_1.bits[3] / MINUS == 1 && value_2.bits[3] / MINUS == 1) {
    if (*save_value >= 0) {
      result->bits[3] += MINUS;
    }
    if (*save_value >= 1) {
      *save_value = -1;
    }
  }
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  initt_decimal(result);
  long long save_value = 1;
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = (value_1.bits[3] - MINUS * (value_1.bits[3] / MINUS) +
                     value_2.bits[3] - MINUS * (value_2.bits[3] / MINUS)) +
                    ((1 - 2 * (value_1.bits[3] / MINUS)) *
                                 (1 - 2 * (value_2.bits[3] / MINUS)) <
                             0
                         ? MINUS
                         : 0);
  save_value = 0;
  for (int bits_part_2 = 0; bits_part_2 != 3 && save_value == 0;
       bits_part_2++) {
    for (int bits_part_1 = 0;
         bits_part_1 != 3 && bits_part_1 + bits_part_2 <= 2; bits_part_1++) {
      result->bits[bits_part_1 + bits_part_2] +=
          (long long)(value_1.bits[bits_part_1]) *
              (long long)(value_2.bits[bits_part_2]) -
          ((long long)(value_1.bits[bits_part_1]) *
           (long long)(value_2.bits[bits_part_2]) / (2 * MINUS)) *
              (2 * MINUS) +
          save_value;
      save_value = (long long)(value_1.bits[bits_part_1]) *
                   (long long)(value_2.bits[bits_part_2]) / (2 * MINUS);
    }
  }
  work_with_rounding(&save_value, value_1, value_2, result);
  int saving_value = save_value ? 1 - 2 * (result->bits[3] / MINUS) : 0;
  int error_znach = 0;
  if (saving_value >= 1) {
    error_znach = 1;
  }
  if (saving_value <= -1) {
    error_znach = 2;
  }
  return error_znach;
}