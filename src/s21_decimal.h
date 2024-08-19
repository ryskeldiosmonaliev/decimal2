#ifndef C5_S21_DECIMAL_1_S21_DECIMAL_H
#define C5_S21_DECIMAL_1_S21_DECIMAL_H
#define NEGATIVE 0x80000000  // 2^32
#define POSITIVE 0
#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
  //  char scale;
} s21_big_num;

// Arithmetic Functions
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparison Functions
int s21_is_less(s21_decimal v1, s21_decimal v2);
int s21_is_less_or_equal(s21_decimal v1, s21_decimal v2);
int s21_is_greater(s21_decimal v1, s21_decimal v2);
int s21_is_greater_or_equal(s21_decimal v1, s21_decimal v2);
int s21_is_equal(s21_decimal v1, s21_decimal v2);
int s21_is_not_equal(s21_decimal v1, s21_decimal v2);

// Conversion Functions
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

// Other Functions
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);

// Helpers
int s21_get_sign(s21_decimal *d);
void s21_set_sign(s21_decimal *d, int sign);
int s21_get_pow(s21_decimal *d);
void s21_set_pow(s21_decimal *d, int power);
int s21_bit(int num, int idx);
void s21_set_bit(int *num, int idx, int value);
int s21_cmp(s21_decimal *a, s21_decimal *b);
int s21_add_handler(s21_decimal *value_1, s21_decimal *value_2);
int s21_sub_handler(s21_decimal *value_1, s21_decimal *value_2);
int s21_mul_handler(s21_decimal *value_1, s21_decimal *value_2);
int s21_div_handler(s21_decimal *value_1, s21_decimal *value_2);
int s21_get_exp_from_string(char *str);
void s21_float_string_to_decimal(char *str, s21_decimal *res);

// big_num functions
void s21_bn_shift_left(s21_big_num *b);
void s21_bn_shift_left_n_times(s21_big_num *b, int n);
void s21_bn_shift_right(s21_big_num *b);
int s21_bn_comp_parts(s21_big_num *ba, s21_big_num *bb, int i);
int s21_bn_comp_num(s21_big_num *ba, s21_big_num *bb);
void s21_bn_add(s21_big_num *a, s21_big_num *b);
int s21_bn_sub(s21_big_num *a, s21_big_num *b);
void s21_bn_mul(s21_big_num *a, s21_big_num *b);
int s21_bn_div(s21_big_num *a, s21_big_num *b);
void s21_bn_mul_10(s21_big_num *b);
void s21_bn_mul_10_n_times(s21_big_num *b, int n);
int s21_bn_len(s21_big_num *b);
int s21_bn_get_pow(s21_big_num *d);
void s21_bn_set_pow(s21_big_num *d, int power);
int s21_bn_digit_to_10_num_sys(unsigned int num);
int s21_bn_div_10(s21_big_num *b);
int s21_bn_div_10_n_times(s21_big_num *b, int n);
int s21_bn_round_or_fail(s21_big_num *b);
void s21_bn_set_bit(unsigned int *num, int idx, int value);
int s21_bn_bit(unsigned int num, int idx);
void s21_bn_equalize_pow(s21_big_num *ba, s21_big_num *bb);
// big_num conversation functions
void s21_from_decimal_to_big_num(s21_decimal *d, s21_big_num *b);
void s21_from_big_num_to_decimal(s21_big_num *b, s21_decimal *d);

// Print functions
// void print_decimal_binary(s21_decimal d);
// void print_bn_binary(s21_big_num bn);
// void print_decimal(s21_decimal d);

#endif  // C5_S21_DECIMAL_1_S21_DECIMAL_H
