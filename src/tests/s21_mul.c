#include "testiks.h"

START_TEST(test_mul_1) {
  int answer = 0;
  int int_result = 0;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_decimal number_2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_mul(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(test_mul_2) {
  int answer = -180;
  int int_result = 0;
  s21_decimal number_1 = {{45, 0, 0, 2147483648}};
  s21_decimal number_2 = {{4, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_mul(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(test_mul_3) {
  int answer = 180;
  int int_result = 0;
  s21_decimal number_1 = {{45, 0, 0, 0}};
  s21_decimal number_2 = {{4, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_mul(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(test_mul_4) {
  s21_decimal number_1 = {{0, 0, 0, 0}};  // 0.0
  set_scale(&number_1, 1);
  s21_decimal number_2 = {{123456, 0, 0, 0}};  // 1234.56
  set_scale(&number_2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  ;
  s21_mul(number_1, number_2, &result);
  int int_result;
  s21_from_decimal_to_int(result, &int_result);
  float resik = (float)int_result * pow(10, -get_exp(result));
  ck_assert_float_eq(resik, 0.0);
}
END_TEST

START_TEST(test_mul_5) {
  s21_decimal number_1 = {{1234567, 0, 0, 0}};  // 123456.7
  set_scale(&number_1, 1);
  s21_decimal number_2 = {{0, 0, 0, 0}};  // 0.0
  set_scale(&number_2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  ;
  s21_mul(number_1, number_2, &result);
  int int_result;
  s21_from_decimal_to_int(result, &int_result);
  float resik = (float)int_result * pow(10, -get_exp(result));
  ck_assert_float_eq(resik, 0.0);
}
END_TEST

// START_TEST(test_mul_6) {
//   s21_decimal number_1 = {55, 0, 0, 0};  // -5.5
//   set_scale(&number_1, 1);
//   set_bit(&number_1, 127, 1);
//   s21_decimal number_2 = {777756, 0, 0, 0};  // 7777.56
//   set_scale(&number_2, 2);
//   s21_decimal result = {0, 0, 0, 0};;
//   s21_mul(number_1, number_2, &result);
//   int int_result;
//   s21_from_decimal_to_int(result, &int_result);
//   float resik = (float)int_result * pow(10, -get_exp(result));
//   ck_assert_float_eq(resik, -42776.58);
// }
// END_TEST

// START_TEST(test_mul_7) {
//  s21_decimal number_1 = {127, 0, 0, 0};  // 12.7
//   set_scale(&number_1, 1);
//   s21_decimal number_2 = {3367897, 0, 0, 0};  // -3367.897
//   set_scale(&number_2, 3);
//   set_bit(&number_2, 127, 1);
//   s21_decimal result = {0, 0, 0, 0};;
//   s21_mul(number_1, number_2, &result);
//   int int_result;
//   s21_from_decimal_to_int(result, &int_result);
//   float resik = (float)int_result * pow(10, -get_exp(result));
//   ck_assert_float_eq(resik, -42772.2919);
// }
// END_TEST

// START_TEST(test_mul_8) {
//  s21_decimal number_1 = {12, 0, 0, 0};  // -1.2
//   set_scale(&number_1, 1);
//   set_bit(&number_1, 127, 1);
//   s21_decimal number_2 = {5674, 0, 0, 0};  // 0.00005674
//   set_scale(&number_2, 8);
//   s21_decimal result = {0, 0, 0, 0};;
//   s21_mul(number_1, number_2, &result);
//   int int_result;
//   s21_from_decimal_to_int(result, &int_result);
//   float resik = (float)int_result * pow(10, -get_exp(result));
//   ck_assert_float_eq(resik, -0.0000680928);
// }
// END_TEST

START_TEST(test_mul_9) {
  s21_decimal number_1 = {{0, 0, 0, 0}};  // 0.0
  set_scale(&number_1, 1);
  s21_decimal number_2 = {{0, 0, 0, 0}};  // 0.00
  set_scale(&number_2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  ;
  s21_mul(number_1, number_2, &result);
  int int_result;
  s21_from_decimal_to_int(result, &int_result);
  float resik = (float)int_result * pow(10, -get_exp(result));
  ck_assert_float_eq(resik, 0.0);
}
END_TEST

// ERROR 1
START_TEST(test_mul_10) {
  s21_decimal number_1 = {{U_MAX_INT, U_MAX_INT, U_MAX_INT, 0}};
  s21_decimal number_2 = {{2, 0, 0, 0}};
  s21_decimal res;
  int ret_s21 = s21_mul(number_1, number_2, &res);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

// ERROR 2
START_TEST(test_mul_11) {
  s21_decimal number_1 = {{U_MAX_INT, U_MAX_INT, U_MAX_INT, 2147483648}};
  s21_decimal number_2 = {{2, 0, 0, 0}};
  s21_decimal res;
  int ret_dec = s21_mul(number_1, number_2, &res);
  ck_assert_int_eq(2, ret_dec);
}
END_TEST

// ERROR 1
START_TEST(test_mul_12) {
  s21_decimal number_1 = {{U_MAX_INT, U_MAX_INT, U_MAX_INT, 2147483648}};
  s21_decimal number_2 = {{2, 0, 0, 2147483648}};
  s21_decimal res;
  int ret_s21 = s21_mul(number_1, number_2, &res);
  ck_assert_int_eq(2, ret_s21);
}
END_TEST

// ERROR 2
START_TEST(test_mul_13) {
  s21_decimal number_1 = {{U_MAX_INT, U_MAX_INT, U_MAX_INT, 0}};
  s21_decimal number_2 = {{2, 0, 0, 2147483648}};
  s21_decimal res;
  int ret_dec = s21_mul(number_1, number_2, &res);
  ck_assert_int_eq(2, ret_dec);
}
END_TEST

START_TEST(test_mul_14) {
  int answer = 0;
  int int_result = 0;
  s21_decimal number_1 = {{58921, 0, 0, 0}};
  s21_decimal number_2 = {{58921, 0, 0, 2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  set_scale(&number_1, 20);
  set_scale(&number_2, 20);
  s21_mul(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(test_mul_15) {
  int int_result = 0;
  int answer = 0;
  s21_decimal answer_dec = {{0, 2, 0, 2147483648}};
  s21_decimal number_1 = {{0, 1, 0, 0}};
  s21_decimal number_2 = {{2, 0, 0, 2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_mul(number_1, number_2, &res);
  s21_from_decimal_to_int(answer_dec, &answer);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(test_mul_16) {
  int int_result = 0;
  int answer = 0;
  s21_decimal answer_dec = {{0, 2, 0, 0}};
  s21_decimal number_1 = {{0, 1, 0, 0}};
  s21_decimal number_2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_mul(number_1, number_2, &res);
  s21_from_decimal_to_int(answer_dec, &answer);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

Suite *suite_mul(void) {
  Suite *s;
  TCase *tc;
  // s = suite_create("s21_mul");
  s = suite_create("\033[45m-=S21_MUL=-\033[0m");
  tc = tcase_create("case_mul");

  tcase_add_test(tc, test_mul_1);
  tcase_add_test(tc, test_mul_2);
  tcase_add_test(tc, test_mul_3);
  tcase_add_test(tc, test_mul_4);
  tcase_add_test(tc, test_mul_5);
  // tcase_add_test(tc, test_mul_6);
  // tcase_add_test(tc, test_mul_7);
  // tcase_add_test(tc, test_mul_8);
  tcase_add_test(tc, test_mul_9);
  tcase_add_test(tc, test_mul_10);
  tcase_add_test(tc, test_mul_11);
  tcase_add_test(tc, test_mul_12);
  tcase_add_test(tc, test_mul_13);
  tcase_add_test(tc, test_mul_14);
  tcase_add_test(tc, test_mul_15);
  tcase_add_test(tc, test_mul_16);

  suite_add_tcase(s, tc);
  return s;
}