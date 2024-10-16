#include "testiks.h"

START_TEST(is_less_0) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

Suite *suite_is_less(void) {
  Suite *s = suite_create("\033[45m-=S21_IS_LESS=-\033[0m");
  TCase *tc = tcase_create("case_is_less");
  tcase_add_test(tc, is_less_0);
  tcase_add_test(tc, is_less_1);
  tcase_add_test(tc, is_less_2);
  tcase_add_test(tc, is_less_3);
  suite_add_tcase(s, tc);
  return s;
}