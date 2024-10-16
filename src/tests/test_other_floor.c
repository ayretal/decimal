#include "testiks.h"

START_TEST(other_floor_1) {
  int itog = 0, answer = 1234;
  s21_decimal test = {0}, result;
  test.bits[0] = 123450000;
  test.bits[3] = 327680;
  s21_floor(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_floor_2) {
  int itog = 0, answer = -1235;
  s21_decimal test = {0}, result;
  test.bits[0] = 123450000;
  test.bits[3] = 2147811328;
  s21_floor(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_floor_3) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 123450000;
  test.bits[3] = 2031616;
  itog = s21_floor(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_floor_4) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 123450000;
  test.bits[3] = 2149515264;
  itog = s21_floor(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_floor_5) {
  int itog = 0, answer = 0;
  s21_decimal test = {0}, result;
  test.bits[0] = 123450000;
  test.bits[3] = 327680;
  itog = s21_floor(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_floor_6) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 123450000;
  test.bits[3] = 1;
  itog = s21_floor(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_floor_7) {
  int itog = 0, answer = 1;
  s21_decimal test = {0};
  test.bits[0] = 123450000;
  test.bits[3] = 327680;
  itog = s21_floor(test, NULL);
  ck_assert_int_eq(itog, answer);
}
END_TEST

Suite *suite_floor(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[45m-=S21_floor=-\033[0m");
  tc = tcase_create("case_floor");

  tcase_add_test(tc, other_floor_1);
  tcase_add_test(tc, other_floor_2);
  tcase_add_test(tc, other_floor_3);
  tcase_add_test(tc, other_floor_4);
  tcase_add_test(tc, other_floor_5);
  tcase_add_test(tc, other_floor_6);
  tcase_add_test(tc, other_floor_7);

  suite_add_tcase(s, tc);
  return s;
}
