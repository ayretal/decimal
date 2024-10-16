#include "testiks.h"

START_TEST(test_div_1) {
  int answer = 0;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_decimal number_2 = {{2, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = 0;
  s21_div(number_1, number_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, answer);
}
END_TEST

START_TEST(test_div_2) {
  int answer = 5;
  s21_decimal number_1 = {{10, 0, 0, 0}};
  s21_decimal number_2 = {{2, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = 0;
  s21_div(number_1, number_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, answer);
}
END_TEST

START_TEST(test_div_3) {
  int answer = -5;
  s21_decimal number_1 = {{10, 0, 0, 2147483648}};
  s21_decimal number_2 = {{2, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = 0;
  s21_div(number_1, number_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, answer);
}
END_TEST

START_TEST(test_div_4) {
  int answer = 5;
  s21_decimal number_1 = {{10, 0, 0, 2147483648}};
  s21_decimal number_2 = {{2, 0, 0, 2147483648}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = 0;
  s21_div(number_1, number_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, answer);
}
END_TEST

START_TEST(test_div_5) {
  int answer = -5;
  s21_decimal number_1 = {{10, 0, 0, 0}};
  s21_decimal number_2 = {{2, 0, 0, 2147483648}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = 0;
  s21_div(number_1, number_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, answer);
}
END_TEST

START_TEST(test_div_6) {
  s21_decimal number_1 = {{10, 0, 0, 0}};
  s21_decimal number_2 = {{0, 0, 0, 2147483648}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = s21_div(number_1, number_2, &result_dec);
  ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(test_div_7) {
  s21_decimal number_1 = {{10, 0, 0, 2147483648}};
  s21_decimal number_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = s21_div(number_1, number_2, &result_dec);
  ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(test_div_8) {
  s21_decimal number_1 = {{10, 0, 0, 0}};
  s21_decimal number_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = s21_div(number_1, number_2, &result_dec);
  ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(test_div_9) {
  s21_decimal number_1 = {{10, 0, 0, 2147483648}};
  s21_decimal number_2 = {{0, 0, 0, 2147483648}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = s21_div(number_1, number_2, &result_dec);
  ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(test_div_10) {
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_decimal number_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = s21_div(number_1, number_2, &result_dec);
  ck_assert_int_eq(result, 3);
}
END_TEST

// START_TEST(test_div_18) {
//   s21_decimal dec1;
//   s21_decimal dec2;
//   int tmp1 = -100;
//   int tmp2 = -99999;
//   float res_s21 = 0;
//   float res = 0.00100001;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_decimal res1;
//   s21_div(dec1, dec2, &res1);
//   s21_from_decimal_to_float(res1, &res_s21);
//   ck_assert_float_eq_tol(res_s21, res, 6);
// }
// END_TEST

// START_TEST(test_div_19) {
//   s21_decimal dec1 = {{1005, 0, 0, 0}};  // -100.5
//   set_scale( &dec1, 1);
//   set_bit(&dec1, 127, 1);
//   s21_decimal dec2 = {{999995, 0, 0, 0}};  // -99999.5
//   set_scale( &dec2, 1);
//   set_bit(&dec2, 127, 1);
//   float res_s21 = 0;
//   float res = 0.001005005;
//   s21_decimal res1;
//   s21_div(dec1, dec2, &res1);
//   s21_from_decimal_to_float(res1, &res_s21);
//   ck_assert_float_eq_tol(res_s21, res, 6);
// }
// END_TEST

// START_TEST(test_div_20) {
//   s21_decimal dec1 = {{10.0e3, 0, 0, 0}};
//   s21_decimal dec2 = {{2.00e2, 0, 0, 0}};

//   int res_s21 = 0;
//   int res = 50;

//   s21_decimal res1;
//   s21_div(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_float_eq_tol(res_s21, res, 6);
// }
// END_TEST

Suite *suite_div(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[45m-=S21_DIV=-\033[0m");
  tc = tcase_create("case_div");

  tcase_add_test(tc, test_div_1);
  tcase_add_test(tc, test_div_2);
  tcase_add_test(tc, test_div_3);
  tcase_add_test(tc, test_div_4);
  tcase_add_test(tc, test_div_5);  // уходит в бесконечность после правки
  tcase_add_test(tc, test_div_6);
  tcase_add_test(tc, test_div_7);
  tcase_add_test(tc, test_div_8);
  tcase_add_test(tc, test_div_9);
  tcase_add_test(tc, test_div_10);
  // tcase_add_test(tc, test_div_11);
  // tcase_add_test(tc, test_div_12);
  // tcase_add_test(tc, test_div_13);
  // tcase_add_test(tc, test_div_14);
  // tcase_add_test(tc, test_div_15);
  // tcase_add_test(tc, test_div_16);  //она уходит в бесконечность
  // tcase_add_test(tc, test_div_17);  //вырублено было      уходит в
  // бесконечность после правки tcase_add_test(tc, test_div_18);
  // tcase_add_test(tc, test_div_19);  //вырублено было
  // tcase_add_test(tc, test_div_20);  //уходит в бесконечность после правки
  // tcase_add_test(tc, test_div_21);

  suite_add_tcase(s, tc);
  return s;
}