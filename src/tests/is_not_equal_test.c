#include "testiks.h"

START_TEST(is_not_equal_0) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val1, 127, 1);
  set_bit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val2, 3, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

// START_TEST(is_not_equal_2) {
//   s21_decimal val1 = {{0}};
//   s21_decimal val2 = {{0}};
//   set_bit(&val2, 127, 1);
//   set_bit(&val1, 33, 1);
//   set_bit(&val2, 33, 1);
//   ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
// }
// END_TEST

START_TEST(is_not_equal_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val1, 3, 1);
  set_bit(&val2, 3, 1);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val1, 3, 1);
  set_bit(&val2, 4, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_scale(&val1, 3);
  set_scale(&val2, 3);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val1, 3, 1);
  set_bit(&val2, 4, 1);
  set_scale(&val1, 3);
  set_scale(&val2, 3);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_scale(&val1, 3);
  set_scale(&val2, 2);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

Suite *suite_is_not_equal(void) {
  Suite *s = suite_create("\033[45m-=S21_IS_NOT_EQUAL=-\033[0m");
  TCase *tc = tcase_create("case_is_not_equal");

  tcase_add_test(tc, is_not_equal_0);
  tcase_add_test(tc, is_not_equal_1);
  // tcase_add_test(tc, is_not_equal_2);
  tcase_add_test(tc, is_not_equal_3);
  tcase_add_test(tc, is_not_equal_4);
  tcase_add_test(tc, is_not_equal_5);
  tcase_add_test(tc, is_not_equal_6);
  tcase_add_test(tc, is_not_equal_7);
  tcase_add_test(tc, is_not_equal_8);

  suite_add_tcase(s, tc);
  return s;
}