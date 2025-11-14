#include "testiks.h"

START_TEST(test_dec_to_float_0) {
  s21_decimal dec_number = {{0x154338CA, 0x75E94EA2, 0xDD7ECF07, 0x00000000}};
  float *answer = NULL;
  int ERROR = s21_from_decimal_to_float(dec_number, answer);
  ck_assert_ptr_eq(answer, NULL);
  ck_assert_int_eq(ERROR, 1);
}
END_TEST

START_TEST(test_dec_to_float_1) {
  s21_decimal dec_number = {{0x154338CA, 0x75E94EA2, 0xDD7ECF07, 0x00000000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {207, 126, 93, 111};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_2) {
  s21_decimal dec_number = {{0x1DA363EE, 0x7A4A49B5, 0x2A2C83FF, 0x000B0000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {121, 218, 231, 91};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_3) {
  s21_decimal dec_number = {{0x67615BA3, 0x942E9B7D, 0xBA45D1F3, 0x00000000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {210, 69, 58, 111};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_4) {
  s21_decimal dec_number = {{0x9987CE65, 0x14B2E8A1, 0x1B36CEE8, 0x00110000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {234, 224, 156, 81};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_5) {
  s21_decimal dec_number = {{0x62C9E79C, 0xE00EBE0C, 0x04F8C04C, 0x00140000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {250, 199, 106, 75};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_6) {
  s21_decimal dec_number = {{0xC167D281, 0x01D5E2EE, 0x6F82D26D, 0x00000000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {165, 5, 223, 110};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_7) {
  s21_decimal dec_number = {{0x09A79296, 0xB395EE0F, 0x8BE96429, 0x80180000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {146, 36, 41, 199};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_8) {
  s21_decimal dec_number = {{0xB64B6D36, 0xC4417425, 0xB16C969C, 0x000D0000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {95, 16, 156, 89};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_9) {
  s21_decimal dec_number = {{0x238C5D69, 0x30336A8C, 0xC038B4E5, 0x00090000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {114, 101, 78, 96};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_10) {
  s21_decimal dec_number = {{0x737EF23F, 0x799FA1A0, 0x97C2A84F, 0x00050000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {85, 234, 198, 102};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_11) {
  s21_decimal dec_number = {{0xC6DF8668, 0x3766B116, 0xF77B0405, 0x80130000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {176, 66, 228, 207};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_12) {
  s21_decimal dec_number = {{0xB71AC026, 0x4A13D3E3, 0x8BFD8104, 0x80150000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {117, 69, 37, 204};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_13) {
  s21_decimal dec_number = {{0xC9C43E26, 0xF2F7B2F9, 0xBD1A240F, 0x80130000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {121, 106, 174, 207};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_14) {
  s21_decimal dec_number = {{0x69A906B9, 0xC4A864D4, 0x4E050321, 0x001B0000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {200, 42, 193, 65};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_15) {
  s21_decimal dec_number = {{0xB232F23A, 0x84D26424, 0xDDBB5AC2, 0x00180000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {88, 7, 134, 71};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_16) {
  s21_decimal dec_number = {{0x79566370, 0x54EA07AB, 0xB8DCA7AA, 0x800C0000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {2, 66, 75, 219};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_17) {
  s21_decimal dec_number = {{0x8C923DBD, 0xDFFC1B6F, 0x87B9269C, 0x80100000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {77, 127, 116, 212};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_18) {
  s21_decimal dec_number = {{0x72FCCC98, 0x060FC735, 0xB73720BC, 0x801A0000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {138, 193, 13, 196};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_19) {
  s21_decimal dec_number = {{0x907C0B42, 0xE67916DA, 0x35F3FFD2, 0x800B0000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {34, 78, 20, 220};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_20) {
  s21_decimal dec_number = {{0x242C0340, 0xB250CA7F, 0x89FE8E95, 0x80180000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {48, 211, 38, 199};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

START_TEST(test_dec_to_float_21) {
  s21_decimal dec_number = {{0x014EA220, 0xB7AD051C, 0x0D508701, 0x80080000}};
  float answer;
  float result;
  unsigned const char massivchik[] = {201, 246, 14, 224};
  memcpy(&result, &massivchik, 4);
  int ERROR = s21_from_decimal_to_float(dec_number, &answer);
  ck_assert_float_eq(answer, result);
  ck_assert_int_eq(ERROR, 0);
}
END_TEST

Suite *test_from_decimal_to_float(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_DECIMAL_TO_FLOAT=-\033[0m");
  TCase *tc = tcase_create("test_dec_to_float_tc");

  tcase_add_test(tc, test_dec_to_float_0);
  tcase_add_test(tc, test_dec_to_float_1);
  tcase_add_test(tc, test_dec_to_float_2);
  tcase_add_test(tc, test_dec_to_float_3);
  tcase_add_test(tc, test_dec_to_float_4);
  tcase_add_test(tc, test_dec_to_float_5);
  tcase_add_test(tc, test_dec_to_float_6);
  tcase_add_test(tc, test_dec_to_float_7);
  tcase_add_test(tc, test_dec_to_float_8);
  tcase_add_test(tc, test_dec_to_float_9);
  tcase_add_test(tc, test_dec_to_float_10);
  tcase_add_test(tc, test_dec_to_float_11);
  tcase_add_test(tc, test_dec_to_float_12);
  tcase_add_test(tc, test_dec_to_float_13);
  tcase_add_test(tc, test_dec_to_float_14);
  tcase_add_test(tc, test_dec_to_float_15);
  tcase_add_test(tc, test_dec_to_float_16);
  tcase_add_test(tc, test_dec_to_float_17);
  tcase_add_test(tc, test_dec_to_float_18);
  tcase_add_test(tc, test_dec_to_float_19);
  tcase_add_test(tc, test_dec_to_float_20);
  tcase_add_test(tc, test_dec_to_float_21);

  suite_add_tcase(s, tc);
  return s;
}
