#include "testiks.h"

START_TEST(add_test_1) {
  int answer = 0;
  int int_result = 0;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_decimal number_2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_2) {
  int answer = 19;
  int int_result = 0;
  s21_decimal number_1 = {{19, 0, 0, 0}};
  s21_decimal number_2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_3) {
  int answer = 5;
  int int_result = 0;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_decimal number_2 = {{5, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_4) {
  int answer = -67;
  int int_result = 0;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_decimal number_2 = {{67, 0, 0, 2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_5) {
  int answer = -890;
  int int_result = 0;
  s21_decimal number_1 = {{890, 0, 0, 2147483648}};
  s21_decimal number_2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_6) {
  int answer = 75;
  int int_result = 0;
  s21_decimal number_1 = {{44, 0, 0, 0}};
  s21_decimal number_2 = {{31, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_7) {
  int answer = 7100;
  int int_result = 0;
  s21_decimal number_1 = {{1200, 0, 0, 0}};
  s21_decimal number_2 = {{5900, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_8) {
  int answer = -123;
  int int_result = 0;
  s21_decimal number_1 = {{13, 0, 0, 2147483648}};   //-13
  s21_decimal number_2 = {{110, 0, 0, 2147483648}};  //-110
  s21_decimal res = {{0, 0, 0, 0}};
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_9) {
  int answer = 1234567890;
  s21_decimal number_1 = {{1234567800, 0, 0, 0}};
  s21_decimal number_2 = {{90, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int int_result = 0;
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_10) {
  int answer = -2000;
  s21_decimal number_1 = {{2564, 0, 0, 2147483648}};  //-2564
  s21_decimal number_2 = {{564, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int int_result = 0;
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_11) {
  int answer = 900;
  s21_decimal number_1 = {{950, 0, 0, 0}};
  s21_decimal number_2 = {{50, 0, 0, 2147483648}};  //-50
  s21_decimal res = {{0, 0, 0, 0}};
  int int_result = 0;
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

START_TEST(add_test_12) {
  float answer = 9.999;
  s21_decimal number_1 = {{3333, 0, 0, 196608}};  // 3.333
  s21_decimal number_2 = {{6666, 0, 0, 196608}};  // 6.666
  s21_decimal res = {{0, 0, 0, 0}};
  float float_result = 0;
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_float(res, &float_result);
  ck_assert_float_eq(float_result, answer);
}
END_TEST

START_TEST(add_test_13) {
  float answer = -123.999;
  s21_decimal number_1 = {{33333, 0, 0, 2147680256}};  //-33.333
  s21_decimal number_2 = {{90666, 0, 0, 2147680256}};  //-90.666
  s21_decimal res = {{0, 0, 0, 0}};
  float float_result = 0;
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_float(res, &float_result);
  ck_assert_float_eq(float_result, answer);
}
END_TEST

START_TEST(add_test_14) {
  float answer = 873.267;
  s21_decimal number_1 = {{33333, 0, 0, 2147680256}};  //-33.333
  s21_decimal number_2 = {{9066, 0, 0, 65536}};        // 906.6
  s21_decimal res = {{0, 0, 0, 0}};
  float float_result = 0;
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_float(res, &float_result);
  ck_assert_float_eq(float_result, answer);
}
END_TEST

START_TEST(add_test_15) {
  float answer = -452.4119;
  s21_decimal number_1 = {{452523, 0, 0, 2147680256}};  //-452.523
  s21_decimal number_2 = {{1111, 0, 0, 262144}};        // 0.1111
  s21_decimal res = {{0, 0, 0, 0}};
  float float_result = 0;
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_float(res, &float_result);
  ck_assert_float_eq(float_result, answer);
}
END_TEST

// ERROR 1
START_TEST(add_test_16) {
  s21_decimal number_1 = {{U_MAX_INT, U_MAX_INT, U_MAX_INT, 0}};
  s21_decimal number_2 = {{1, 0, 0, 0}};
  s21_decimal res;
  int ret_s21 = s21_add(number_1, number_2, &res);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

// ERROR 2
START_TEST(add_test_17) {
  s21_decimal number_1 = {{U_MAX_INT, U_MAX_INT, U_MAX_INT, 2147483648}};
  s21_decimal number_2 = {{1, 0, 0, 2147483648}};
  s21_decimal res;
  int ret_dec = s21_add(number_1, number_2, &res);
  ck_assert_int_eq(2, ret_dec);
}
END_TEST

START_TEST(add_test_18) {
  int answer = 0;
  s21_decimal answer_dec = {{0, 1, 0, 0}};
  s21_decimal number_1 = {{U_MAX_INT, 0, 0, 0}};
  s21_decimal number_2 = {{1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int int_result = 0;
  s21_add(number_1, number_2, &res);
  s21_from_decimal_to_int(res, &int_result);
  s21_from_decimal_to_int(answer_dec, &answer);
  ck_assert_int_eq(int_result, answer);
}
END_TEST

Suite* suite_add(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("\033[45m-=S21_ADD=-\033[0m");
  tc = tcase_create("case_add");
  tcase_add_test(tc, add_test_1);
  tcase_add_test(tc, add_test_2);
  tcase_add_test(tc, add_test_3);
  tcase_add_test(tc, add_test_4);
  tcase_add_test(tc, add_test_5);
  tcase_add_test(tc, add_test_6);
  tcase_add_test(tc, add_test_7);
  tcase_add_test(tc, add_test_8);
  tcase_add_test(tc, add_test_9);
  tcase_add_test(tc, add_test_10);
  tcase_add_test(tc, add_test_11);
  tcase_add_test(tc, add_test_12);
  tcase_add_test(tc, add_test_13);
  tcase_add_test(tc, add_test_14);
  tcase_add_test(tc, add_test_15);
  tcase_add_test(tc, add_test_16);
  tcase_add_test(tc, add_test_17);
  tcase_add_test(tc, add_test_18);

  suite_add_tcase(s, tc);
  return s;
}
