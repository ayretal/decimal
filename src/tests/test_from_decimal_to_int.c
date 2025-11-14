#include "testiks.h"

START_TEST(test_decimal_to_int_1) {
  int answer = 1;
  s21_decimal dec_number = {{0x14096470, 0x8024B17B, 0x3E85A728, 0x80040000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST

START_TEST(test_decimal_to_int_2) {
  int answer = 0;
  s21_decimal dec_number = {{0xE2866114, 0x2C7841C4, 0x02A4DCC9, 0x801A0000}};
  int result = -8;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST

START_TEST(test_decimal_to_int_3) {
  int answer = 0;
  s21_decimal dec_number = {{0xF727D298, 0x2BF7BCA3, 0xBD7D4DD8, 0x00170000}};
  int result = 586441;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_4) {
  int answer = 0;
  s21_decimal dec_number = {{0x704D5EDF, 0x973F341E, 0x6FA88855, 0x801A0000}};
  int result = -345;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_5) {
  int answer = 1;
  s21_decimal dec_number = {{0x5328C40D, 0xE79BFCDF, 0xAA9896CB, 0x00060000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_6) {
  int answer = 1;
  s21_decimal dec_number = {{0x4D9F3E1B, 0xDBCEC234, 0xF5F8BDFC, 0x800D0000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_7) {
  int answer = 0;
  s21_decimal dec_number = {{0x7693C708, 0x1CA65A79, 0xC44C4203, 0x80170000}};
  int result = -607512;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_8) {
  int answer = 1;
  s21_decimal dec_number = {{0x8B5036C6, 0x2BF300CF, 0xF79E4287, 0x000A0000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_9) {
  int answer = 1;
  s21_decimal dec_number = {{0xF19F4BF7, 0x6DC18597, 0x4538F642, 0x800A0000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_10) {
  int answer = 1;
  s21_decimal dec_number = {{0xF67DCC50, 0x7D8D44A3, 0xF2DD1F9A, 0x000C0000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_11) {
  int answer = 0;
  s21_decimal dec_number = {{0x3A2A58C9, 0x004CB47B, 0xE6B33F52, 0x00140000}};
  int result = 713982490;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_12) {
  int answer = 1;
  s21_decimal dec_number = {{0xDBA2C5D3, 0xFF7CA645, 0x7B54257E, 0x00080000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_13) {
  int answer = 0;
  s21_decimal dec_number = {{0x7E85626B, 0xCE0FBFB4, 0xFF7975A6, 0x80160000}};
  int result = -7906551;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_14) {
  int answer = 1;
  s21_decimal dec_number = {{0xFC800D0E, 0xC5B947E0, 0xD83244A8, 0x00130000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_15) {
  int answer = 1;
  s21_decimal dec_number = {{0xF133367C, 0x8510180A, 0x75C16349, 0x00050000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_16) {
  int answer = 1;
  s21_decimal dec_number = {{0xC4D963A4, 0x0880015F, 0x67A59830, 0x80010000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_17) {
  int answer = 0;
  s21_decimal dec_number = {{0x99F98123, 0x511E77FD, 0x6D748CC4, 0x00160000}};
  int result = 3387476;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_18) {
  int answer = 1;
  s21_decimal dec_number = {{0xFE0F47C4, 0x02226767, 0x9F122BB0, 0x00030000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_19) {
  int answer = 1;
  s21_decimal dec_number = {{0x89ACD0D9, 0xF6BF2936, 0x27863DC7, 0x00080000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_20) {
  int answer = 1;
  s21_decimal dec_number = {{0xD42872F6, 0x1A9CA8A4, 0xF2372AD7, 0x000A0000}};
  int result = 0;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST
START_TEST(test_decimal_to_int_21) {
  int answer = 0;
  s21_decimal dec_number = {{0xF8392764, 0xB3294340, 0x221CFD5B, 0x00150000}};
  int result = 10557536;
  int our_int = 0;
  int res_for_compare = s21_from_decimal_to_int(dec_number, &our_int);
  ck_assert_int_eq(result, our_int);
  ck_assert_int_eq(res_for_compare, answer);
}
END_TEST

Suite *test_from_decimal_to_int(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_DECIMAL_TO_INT=-\033[0m");
  TCase *tc = tcase_create("test_decimal_to_int_tc");

  tcase_add_test(tc, test_decimal_to_int_1);
  tcase_add_test(tc, test_decimal_to_int_2);
  tcase_add_test(tc, test_decimal_to_int_3);
  tcase_add_test(tc, test_decimal_to_int_4);
  tcase_add_test(tc, test_decimal_to_int_5);
  tcase_add_test(tc, test_decimal_to_int_6);
  tcase_add_test(tc, test_decimal_to_int_7);
  tcase_add_test(tc, test_decimal_to_int_8);
  tcase_add_test(tc, test_decimal_to_int_9);
  tcase_add_test(tc, test_decimal_to_int_10);
  tcase_add_test(tc, test_decimal_to_int_11);
  tcase_add_test(tc, test_decimal_to_int_12);
  tcase_add_test(tc, test_decimal_to_int_13);
  tcase_add_test(tc, test_decimal_to_int_14);
  tcase_add_test(tc, test_decimal_to_int_15);
  tcase_add_test(tc, test_decimal_to_int_16);
  tcase_add_test(tc, test_decimal_to_int_17);
  tcase_add_test(tc, test_decimal_to_int_18);
  tcase_add_test(tc, test_decimal_to_int_19);
  tcase_add_test(tc, test_decimal_to_int_20);
  tcase_add_test(tc, test_decimal_to_int_21);

  suite_add_tcase(s, tc);
  return s;
}
