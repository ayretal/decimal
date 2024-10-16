#include "testiks.h"

START_TEST(test_int_to_decimal_1) {
  int int_number = -1113505110;
  s21_decimal our_dec;
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x425EBD56, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_2) {
  int int_number = 1985697117;
  s21_decimal *our_dec = NULL;
  int ERROR = s21_from_int_to_decimal(int_number, our_dec);
  ck_assert_int_eq(ERROR, 1);
}
END_TEST

START_TEST(test_int_to_decimal_3) {
  int int_number = INT_MAX;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x7FFFFFFF, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_4) {
  int int_number = INT_MIN;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x80000000, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_5) {
  int int_number = -516363763;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x1EC715F3, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_6) {
  int int_number = -1738750530;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x67A33A42, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_7) {
  int int_number = 1808559587;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x6BCC6DE3, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_8) {
  int int_number = -569703402;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x21F4FBEA, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_9) {
  int int_number = 642518603;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x264C0E4B, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_10) {
  int int_number = 879304798;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x3469205E, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_11) {
  int int_number = 875434235;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x342E10FB, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_12) {
  int int_number = -1061716943;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x3F4883CF, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_13) {
  int int_number = 356646416;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x1541FE10, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_14) {
  int int_number = 1027557455;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x3D3F484F, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_15) {
  int int_number = -1056545713;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x3EF99BB1, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_16) {
  int int_number = -1633771678;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x6161609E, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_17) {
  int int_number = -1116871923;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x42921CF3, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_18) {
  int int_number = -651659745;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x26D789E1, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_19) {
  int int_number = -1424961110;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x54EF2E56, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_20) {
  int int_number = -1384633449;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x5287D469, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_int_to_decimal_21) {
  int int_number = 1962032;
  s21_decimal our_dec = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int ERROR = s21_from_int_to_decimal(int_number, &our_dec);
  s21_decimal result = {{0x001DF030, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(our_dec.bits[i], result.bits[i]);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

Suite *test_from_int_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=s21_FROM_INT_TO_DECIMAL=-\033[0m");
  TCase *tc = tcase_create("test_int_to_decimal_tc");

  tcase_add_test(tc, test_int_to_decimal_1);
  tcase_add_test(tc, test_int_to_decimal_2);
  tcase_add_test(tc, test_int_to_decimal_3);
  tcase_add_test(tc, test_int_to_decimal_4);
  tcase_add_test(tc, test_int_to_decimal_5);
  tcase_add_test(tc, test_int_to_decimal_6);
  tcase_add_test(tc, test_int_to_decimal_7);
  tcase_add_test(tc, test_int_to_decimal_8);
  tcase_add_test(tc, test_int_to_decimal_9);
  tcase_add_test(tc, test_int_to_decimal_10);
  tcase_add_test(tc, test_int_to_decimal_11);
  tcase_add_test(tc, test_int_to_decimal_12);
  tcase_add_test(tc, test_int_to_decimal_13);
  tcase_add_test(tc, test_int_to_decimal_14);
  tcase_add_test(tc, test_int_to_decimal_15);
  tcase_add_test(tc, test_int_to_decimal_16);
  tcase_add_test(tc, test_int_to_decimal_17);
  tcase_add_test(tc, test_int_to_decimal_18);
  tcase_add_test(tc, test_int_to_decimal_19);
  tcase_add_test(tc, test_int_to_decimal_20);
  tcase_add_test(tc, test_int_to_decimal_21);

  suite_add_tcase(s, tc);
  return s;
}
