#include "testiks.h"

START_TEST(other_negate_1) {
  int itog = 0, answer = -123456789;
  s21_decimal test = {0}, result;
  test.bits[0] = 123456789;
  s21_negate(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_negate_2) {
  int itog = 0, answer = 123456789;
  s21_decimal test = {0}, result;
  test.bits[0] = 123456789;
  test.bits[3] = 2147483648;
  s21_negate(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_negate_3) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 123456789;
  test.bits[3] = 2031616;
  itog = s21_negate(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_negate_4) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 123456789;
  test.bits[3] = 2149515264;
  itog = s21_negate(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_negate_5) {
  int itog = 0, answer = 0;
  s21_decimal test = {0}, result;
  test.bits[0] = 123456789;
  test.bits[3] = 2147483648;
  itog = s21_negate(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_negate_6) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 123456789;
  test.bits[3] = 1;
  itog = s21_negate(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_negate_7) {
  int itog = 0, answer = 1;
  s21_decimal test = {0};
  test.bits[0] = 123456789;
  test.bits[3] = 2147483648;
  itog = s21_negate(test, NULL);
  ck_assert_int_eq(itog, answer);
}
END_TEST

Suite *suite_negate(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[45m-=S21_negate=-\033[0m");
  tc = tcase_create("case_negate");

  tcase_add_test(tc, other_negate_1);
  tcase_add_test(tc, other_negate_2);
  tcase_add_test(tc, other_negate_3);
  tcase_add_test(tc, other_negate_4);
  tcase_add_test(tc, other_negate_5);
  tcase_add_test(tc, other_negate_6);
  tcase_add_test(tc, other_negate_7);

  suite_add_tcase(s, tc);
  return s;
}