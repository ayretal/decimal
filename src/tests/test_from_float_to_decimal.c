#include "testiks.h"

START_TEST(test_float_to_dec_0) {
  float float_number = 2;
  s21_decimal *answer = NULL;
  int ERROR_marker = s21_from_float_to_decimal(float_number, answer);
  ck_assert_ptr_eq(answer, NULL);
  ck_assert_int_eq(ERROR_marker, 1);
}
END_TEST
START_TEST(test_float_to_dec_1) {
  float float_number = 2;
  s21_decimal answer = {{0, 0, 0, 0}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00000002, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_2) {
  float float_number = -321.2;
  s21_decimal answer = {{0, 0, 0, 0}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00000C8C, 0, 0, 0x80010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_3) {
  float float_number = 321.2;
  s21_decimal answer = {{0, 0, 0, 0}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00000C8C, 0, 0, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_4) {
  float float_number = 73.329959999;
  s21_decimal answer = {{3211, 123145, 231, 312441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x006FE484, 0, 0, 0x00050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_5) {
  float float_number = 0.003;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00000003, 0, 0, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_6) {
  float float_number = 0.00000000000000000000000000016929383838292;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00000002, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_7) {
  float float_number = 0.00312345;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x0004C419, 0, 0, 0x00080000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_8) {
  float float_number = 0.00000003123959595945;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x0004C44C, 0, 0, 0x000D0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_9) {
  float float_number = 0.0000000000000000093929383838292;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x008F532B, 0, 0, 0x00180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_10) {
  float float_number = 0.00000000000000000000000000013929383838292;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00000001, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_11) {
  float float_number = .00000000000000000000000000000000193929383838292;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  ck_assert_int_eq(ERROR_marker, 1);
}
END_TEST

START_TEST(test_float_to_dec_12) {
  float float_number = 0.00000000000000000000000005646473736464;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00000235, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_13) {
  float float_number = 0.00000000000000000000000073736361612636;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00001CCE, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_14) {
  float float_number = 0.000000000000000000000099999999999;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00000001, 0, 0, 0x00160000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST
START_TEST(test_float_to_dec_15) {
  float float_number = 0.00000000000000000000073766666662636;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00708F1B, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST
START_TEST(test_float_to_dec_16) {
  float float_number = 0.0000000000000000000073736361612636;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00708344, 0, 0, 0x001B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST
START_TEST(test_float_to_dec_17) {
  float float_number = 0.00000000000000000000000073736361612636;
  s21_decimal answer = {{32131, 1231435, 2311, 3121441}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00001CCE, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_18) {
  float float_number = -1.307818E+07;
  s21_decimal answer = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00C78EA4, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_19) {
  float float_number = -30914.76;
  s21_decimal answer = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x002F2C14, 0x00000000, 0x00000000, 0x80020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_20) {
  float float_number = 1.965111E-26;
  s21_decimal answer = {{0}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x000000C5, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

START_TEST(test_float_to_dec_21) {
  float float_number = -750.9904;
  s21_decimal answer = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int ERROR_marker = s21_from_float_to_decimal(float_number, &answer);
  s21_decimal result = {{0x00729790, 0x00000000, 0x00000000, 0x80040000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(answer.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR_marker, 0);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_FLOAT_TO_DECIMAL=-\033[0m");
  TCase *tc = tcase_create("s21_from_float_to_decimal_tc");

  tcase_add_test(tc, test_float_to_dec_0);
  tcase_add_test(tc, test_float_to_dec_1);
  tcase_add_test(tc, test_float_to_dec_2);
  tcase_add_test(tc, test_float_to_dec_3);
  tcase_add_test(tc, test_float_to_dec_4);
  tcase_add_test(tc, test_float_to_dec_5);
  tcase_add_test(tc, test_float_to_dec_6);
  tcase_add_test(tc, test_float_to_dec_7);
  tcase_add_test(tc, test_float_to_dec_8);
  tcase_add_test(tc, test_float_to_dec_9);
  tcase_add_test(tc, test_float_to_dec_10);
  tcase_add_test(tc, test_float_to_dec_11);
  tcase_add_test(tc, test_float_to_dec_12);
  tcase_add_test(tc, test_float_to_dec_13);
  tcase_add_test(tc, test_float_to_dec_14);
  tcase_add_test(tc, test_float_to_dec_15);
  tcase_add_test(tc, test_float_to_dec_16);
  tcase_add_test(tc, test_float_to_dec_17);
  tcase_add_test(tc, test_float_to_dec_18);
  tcase_add_test(tc, test_float_to_dec_19);
  tcase_add_test(tc, test_float_to_dec_20);
  tcase_add_test(tc, test_float_to_dec_21);

  suite_add_tcase(s, tc);
  return s;
}