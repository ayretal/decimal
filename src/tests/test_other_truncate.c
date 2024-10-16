#include "testiks.h"

START_TEST(other_truncate_1) {
  int itog = 0, answer = 123456789;
  s21_decimal test = {0}, result;
  test.bits[0] = 2899336981;
  test.bits[1] = 28744523;
  test.bits[3] = 589824;
  s21_truncate(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_truncate_2) {
  int itog = 0, answer = -123456789;
  s21_decimal test = {0}, result;
  test.bits[0] = 2899336981;
  test.bits[1] = 28744523;
  test.bits[3] = 2148073472;
  s21_truncate(test, &result);
  s21_from_decimal_to_int(result, &itog);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_truncate_3) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 2899336981;
  test.bits[1] = 28744523;
  test.bits[3] = 2031616;
  itog = s21_truncate(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_truncate_4) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 2899336981;
  test.bits[1] = 28744523;
  test.bits[3] = 2149515264;
  itog = s21_truncate(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_truncate_5) {
  int itog = 0, answer = 0;
  s21_decimal test = {0}, result;
  test.bits[0] = 2899336981;
  test.bits[1] = 28744523;
  test.bits[3] = 589824;
  itog = s21_truncate(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_truncate_6) {
  int itog = 0, answer = 1;
  s21_decimal test = {0}, result;
  test.bits[0] = 2899336981;
  test.bits[1] = 28744523;
  test.bits[3] = 1;
  itog = s21_truncate(test, &result);
  ck_assert_int_eq(itog, answer);
}
END_TEST

START_TEST(other_truncate_7) {
  int itog = 0, answer = 1;
  s21_decimal test = {0};
  test.bits[0] = 2899336981;
  test.bits[1] = 28744523;
  test.bits[3] = 589824;
  itog = s21_truncate(test, NULL);
  ck_assert_int_eq(itog, answer);
}
END_TEST

Suite *suite_truncate(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[45m-=S21_truncate=-\033[0m");
  tc = tcase_create("case_truncate");

  tcase_add_test(tc, other_truncate_1);
  tcase_add_test(tc, other_truncate_2);
  tcase_add_test(tc, other_truncate_3);
  tcase_add_test(tc, other_truncate_4);
  tcase_add_test(tc, other_truncate_5);
  tcase_add_test(tc, other_truncate_6);
  tcase_add_test(tc, other_truncate_7);

  suite_add_tcase(s, tc);
  return s;
}