#ifndef S21_ADDITION
#define S21_ADDITION

#include "s21_decimal.h"
#define OK 0
#define ERROR_INF 1
#define ERROR_NEGINF 2
#define ERROR_DIV_ZERO 3
#define MAX_BIT 2147483648

// побитовое сложение
int bit_add(s21_big_decimal value1, s21_big_decimal value2,
            s21_big_decimal *res);
// вычитание соотвественно двух положительных чисел одинакового порядка, v1 > v2
int bit_sub(s21_big_decimal v1, s21_big_decimal v2, s21_big_decimal *result);

// увеличиваем число в заданном масштабе
void level_up_scale(s21_big_decimal *val1, int scale2);

int inf_checking(s21_big_decimal *trunc, int sign);
void help_to_overf1(s21_big_decimal trunc, s21_big_decimal big_result);
void help_to_overf2(s21_big_decimal *mode, int sign, s21_big_decimal *trunc,
                    s21_big_decimal *big_result);
int is_there_overflow(s21_big_decimal *big_dec, s21_decimal *dec);

void to_big(s21_decimal *dst, s21_big_decimal *big_dst);

int to_small(s21_big_decimal *big_dst, s21_decimal *dst);

void make_normal(s21_big_decimal *val_1, s21_big_decimal *val_2);

// LITTLE
s21_decimal *init_decimal();

void decimal_null(s21_decimal *result);

int zero(s21_decimal value);

int if_correct(s21_decimal *value);

void paste(s21_decimal *what, s21_decimal *into_what);

int compare(s21_decimal *first, s21_decimal *second);

// BIG
s21_big_decimal *init_big();
void decimall_null_big(s21_big_decimal *result);
int if_big_correct(s21_big_decimal a);
int zero_big(s21_big_decimal *a);

void paste_big(s21_big_decimal *what, s21_big_decimal *into_what);

// LITTLE
int get_sign(s21_decimal value);
void set_sign(s21_decimal *value, int sign);

int get_scale(s21_decimal dec);
int set_scale(s21_decimal *dec, int exp);

unsigned get_bit(s21_decimal dec, int place);
void set_bit(s21_decimal *value, int position, unsigned bit_val);

// BIG
int get_sign_big(s21_big_decimal *value);
void set_sign_big(s21_big_decimal *value, unsigned sign_value);

int get_scale_big(s21_big_decimal *dec);
int set_scale_big(s21_big_decimal *dec, int exp);

unsigned get_bit_big(s21_big_decimal value, int place);
void set_bit_big(s21_big_decimal *value, int position, unsigned bit_val);

int compare_big(s21_big_decimal *pi, s21_big_decimal *vo);

int shift_left_big(s21_big_decimal *value, int shift_value);
int shift_right_big(s21_big_decimal *value, int shift_value);

void integer_div(s21_big_decimal val1, s21_big_decimal val2,
                 s21_big_decimal *res);
int non_integer_div(s21_decimal v1, s21_decimal v2, s21_decimal *result);

int s21_shift_big_dec_left(s21_big_decimal *dst, int num);
void s21_shift_big_dec_right(s21_big_decimal *dst, int num);

void print_binary(int num);
void print_decimal(s21_decimal num);
void set_sign(s21_decimal *num, int sign);
int s21_get_bit(s21_decimal num, int pos);
void s21_set_bit(s21_decimal *num, int pos, int bit);
void set_minus(s21_decimal *num);
void set_plus(s21_decimal *num);
int get_scale(s21_decimal dec);

s21_decimal binary_xor(s21_decimal num1, s21_decimal num2);
s21_decimal binary_and(s21_decimal num1, s21_decimal num2);
s21_decimal shift_left_one(s21_decimal num);
s21_decimal shif_left(s21_decimal num, int shift);
int binary_equal_zero(s21_decimal num);
s21_decimal binary_addition(s21_decimal num1, s21_decimal num2);

void s21_set_sign(s21_decimal *dst);
void s21_zero_decimal(s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
void s21_copy_decimal(s21_decimal *d1, s21_decimal d2);

int s21_get_bit_big(s21_big_decimal dst, int index);
void s21_set_bit_big(s21_big_decimal *dst, int index, int bit);
void s21_add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result);
int s21_shift_big_dec_left(s21_big_decimal *dst, int num);
int s21_mul_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);
int s21_s21_get_bit_big(s21_big_decimal dst, int index);
void s21_s21_set_bit_big(s21_big_decimal *dst, int index, int bit);
void s21_import_to_big_decimal(s21_decimal value_1, s21_big_decimal *value_2);
void s21_import_to_small_decimal(s21_decimal *value_1, s21_big_decimal value_2);
void s21_find_highest_bit_big_decimal(s21_big_decimal v1, s21_big_decimal v2,
                                      int *bit_1, int *bit_2);
int s21_is_big_decimal_not_empty(s21_big_decimal dst);
void s21_increase_scale_big_decimal(s21_big_decimal *dst, int n);
void s21_shift_big_dec_right(s21_big_decimal *dst, int num);
void s21_zero_big_decimal(s21_big_decimal *dst);
int s21_is_greater_big_decimal(s21_big_decimal value_1,
                               s21_big_decimal value_2);
int s21_is_greater_or_equal_big_decimal(s21_big_decimal value_1,
                                        s21_big_decimal value_2);
int s21_equation_bits_big_decimal(s21_big_decimal *value_1,
                                  s21_big_decimal *value_2);
void s21_sub_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result);
int s21_div_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);

void s21_decreace_scale_big_decimal(s21_big_decimal *dst, int n);
int s21_post_normalization(s21_big_decimal *result, int scale);
void s21_normalize_scale_upper(s21_decimal *d, int norm);
void s21_normalize(s21_decimal *d1, s21_decimal *d2);

void s21_comparison_reverse(int *flag);
int s21_greater_num(int a, int b);
int s21_comparison_bits(s21_decimal d1, s21_decimal d2);
int s21_comparison(s21_decimal d1, s21_decimal d2);

int s21_add_big(s21_big_decimal value_big_1, s21_big_decimal value_big_2,
                s21_big_decimal *result_big);

int get_first_bit(s21_big_decimal value);

int s21_mul_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);

int get_exp(s21_decimal d);
void initt_decimal(s21_decimal *d);
int s21_get_bitt(int num, int ind);
int s21_count_exp(float src);
int s21_get_sign_from_float(float src);
int s21_divide_10_float(s21_decimal *dst);
int s21_10_division(s21_decimal *dst);

#endif