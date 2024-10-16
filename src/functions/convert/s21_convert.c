#include "../../s21_addition.h"
#include "../../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if (dst) {
    initt_decimal(dst);
    if (src < 0) {
      set_sign(dst, 1);
    }
    dst->bits[0] = src > 0 ? src : ~(src - 1);
  } else
    error++;
  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0, expo = get_exp(src);
  s21_decimal mn_d = {{4294967295u, 4294967295u, 4294967295u, 0}};
  set_sign(&mn_d, 1);
  if (expo > 28) error = 1;
  if (dst && !error) {
    int sign = (get_sign(src) ? -1 : 1);
    int mantiss = get_exp(src);
    double_t temp = 0.0;
    for (int a = 0; a <= 95; a++) {
      if (get_bit(src, a) == 1) temp += pow(2, a);
    }
    *dst = (float)(temp / pow(10, mantiss) * sign);
  } else
    error = 1;
  return error;
}

// int s21_from_decimal_to_int(s21_decimal src, int *dst) {
//   int error = 0;
//   if (dst && src.bits[1] == 0 && src.bits[2] == 0 && get_bit(src, 31) == 0) {
//     int expo = get_exp(src);
//     if (expo <= 28) {
//       int divisor = pow(10, expo);
//       *dst = src.bits[0] / divisor;
//       *dst *= get_sign(src) ? -1 : 1;
//     } else {
//       error = 1;
//     }
//   } else {
//     error = 1;
//   }
//   return error;
// }

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int code = 0;
  if (dst == NULL || !if_correct(&src)) return 1;
  s21_decimal *tmp = init_decimal();
  s21_truncate(src, tmp);
  if (tmp->bits[1] != 0 || tmp->bits[2] != 0) {
    code = 1;
  } else {
    int sign = get_sign(*tmp) ? -1 : 1;
    *dst = tmp->bits[0] * sign;
  }
  free(tmp);
  return code;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int to_return = 1;
  if (dst && src != INF) {
    double temp = (double)src;
    to_return = 0;
    int sign = s21_get_sign_from_float(src);
    initt_decimal(dst);
    int count_exp = s21_count_exp(src);
    if (count_exp < 256) {
      if (src != 0) {
        int scale = 0;
        temp = fabs(temp);
        while (!floor(temp)) {  // если что-то меньше 1
          temp *= 10;
          scale++;
        }
        if (scale < 29) {
          while (!floor(temp / NUM_AFTER_POINT) && scale < 28) {
            temp *= 10;
            scale += 1;
          }
          double ost = 0;
          if (modf(temp, &ost) > 0.5) {
            temp++;
          }
          dst->bits[0] = temp;
          while (s21_divide_10_float(dst) && scale > 0) {
            s21_10_division(dst);
            scale--;
          }
          dst->bits[3] = scale << 16;
          if (sign)
            set_bit(dst, 127, 1);
          else
            set_bit(dst, 127, 0);
        } else
          to_return = 1;
      }
    } else
      to_return = 1;
  }
  return to_return;
}
