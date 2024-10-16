#include "testiks.h"

START_TEST(other_round_1) {
  int itog = 0, answer = 1234;
  s21_decimal test = {0}, result;
  test.bits[0] = 123450000;
  test.bits[3] = 327680;
  s21_round(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_round_2) {
  int itog = 0, answer = -1234;
  s21_decimal test = {0}, result;
  test.bits[0] = 123450000;
  test.bits[3] = 2147811328;
  s21_round(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_round_3) {
  int itog = 0, answer = 1234;
  s21_decimal test = {0}, result;
  test.bits[0] = 123350000;
  test.bits[3] = 327680;
  s21_round(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_round_4) {
  int itog = 0, answer = -1234;
  s21_decimal test = {0}, result;
  test.bits[0] = 123350000;
  test.bits[3] = 2147811328;
  s21_round(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_round_5) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 123350000;
  test.bits[3] = 2031616;
  itog = s21_round(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_round_6) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 123350000;
  test.bits[3] = 2149515264;
  itog = s21_round(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_round_7) {
  int itog = 0, answer = 0;
  s21_decimal test = {0}, result;
  test.bits[0] = 123350000;
  test.bits[3] = 327680;
  itog = s21_round(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_round_8) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 123350000;
  test.bits[3] = 1;
  itog = s21_round(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_round_9) {
  int itog = 0, answer = 1;
  s21_decimal test = {0};
  test.bits[0] = 123350000;
  test.bits[3] = 327680;
  itog = s21_round(test, NULL);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_round_10) {
  int itog = 0, answer = 1235;
  s21_decimal test = {0}, result;
  test.bits[0] = 123456000;
  test.bits[3] = 327680;
  s21_round(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

Suite *suite_round(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[45m-=S21_round=-\033[0m");
  tc = tcase_create("case_round");

  tcase_add_test(tc, other_round_1);
  tcase_add_test(tc, other_round_2);
  tcase_add_test(tc, other_round_3);
  tcase_add_test(tc, other_round_4);
  tcase_add_test(tc, other_round_5);
  tcase_add_test(tc, other_round_6);
  tcase_add_test(tc, other_round_7);
  tcase_add_test(tc, other_round_8);
  tcase_add_test(tc, other_round_9);
  tcase_add_test(tc, other_round_10);

  suite_add_tcase(s, tc);
  return s;
}