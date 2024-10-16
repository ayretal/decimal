#include "testiks.h"

int main(void) {
  run_tests();
  // int failed = 0;
  // Suite *s21_string_test[] = {
  //     test_from_int_to_decimal(), test_from_decimal_to_int(),
  //     test_from_decimal_to_float(), test_from_float_to_decimal(),

  //     NULL};

  // for (int i = 0; s21_string_test[i] != NULL; i++) {
  //   SRunner *sr = srunner_create(s21_string_test[i]);

  //   srunner_set_fork_status(sr, CK_NOFORK);
  //   srunner_run_all(sr, CK_NORMAL);

  //   failed += srunner_ntests_failed(sr);
  //   srunner_free(sr);
  // }
  // printf("Failed: %d\n", failed);

  // return failed == 0 ? 0 : 1;
  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1) counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_add(),
                         suite_sub(),
                         suite_div(),
                         suite_mul(),
                         suite_is_equal(),
                         suite_is_greater(),
                         suite_is_greater_or_equal(),
                         suite_is_less(),
                         suite_is_less_or_equal(),
                         suite_is_not_equal(),
                         suite_floor(),
                         suite_negate(),
                         suite_round(),
                         suite_truncate(),
                         test_from_int_to_decimal(),
                         test_from_decimal_to_int(),
                         test_from_decimal_to_float(),
                         test_from_float_to_decimal(),
                         NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
