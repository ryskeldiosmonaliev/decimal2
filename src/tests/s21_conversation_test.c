#include "s21_test.h"

START_TEST(s21_from_decimal_to_float_1) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147680256;
  src.bits[0] = 18122;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147483648;
  src.bits[0] = 1812;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 0XFFFFFF;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147745792;
  src.bits[0] = 23450987;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 4294967295;
  src.bits[0] = c;
  src.bits[1] = c;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_7) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 2147483648;
  dec.bits[0] = 1812;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = c;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_8) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;

  dec.bits[0] = 0XFFFFFF;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_9) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 2147745792;
  dec.bits[0] = 23450987;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = c;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_10) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 4294967295;
  dec.bits[0] = c;
  dec.bits[1] = c;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST

// START_TEST(s21_from_decimal_to_floatTest1) {
//   s21_decimal src1;

//   float src2;
//   float *srcp = &src2;

//   src1.bits[0] = 0b00000000000000000110001101111001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   s21_from_decimal_to_float(src1, srcp);
//   char var3str[1000];
//   char result[1000];
//   snprintf(var3str, sizeof(var3str), "%.6f", 2546.5);
//   snprintf(result, sizeof(result), "%f", src2);
//   ck_assert_str_eq(result, var3str);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_floatTest2) {
//   s21_decimal src1;

//   float src2;
//   float *srcp = &src2;

//   src1.bits[0] = 0b00000000000000001011010101110101;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000001010000000000000000;
//   s21_from_decimal_to_float(src1, srcp);
//   char var3str[1000];
//   char result[1000];
//   snprintf(var3str, sizeof(var3str), "%.6f", -0.46453);
//   snprintf(result, sizeof(result), "%f", src2);
//   ck_assert_str_eq(result, var3str);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_floatTest3) {
//   s21_decimal src1;

//   float src2;
//   float *srcp = &src2;

//   src1.bits[0] = 0b00000000000000000000000000100011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   s21_from_decimal_to_float(src1, srcp);
//   char var3str[1000];
//   char result[1000];
//   snprintf(var3str, sizeof(var3str), "%.6f", 3.5);
//   snprintf(result, sizeof(result), "%f", src2);
//   ck_assert_str_eq(result, var3str);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_floatTest4) {
//   s21_decimal src1;

//   float src2;
//   float *srcp = &src2;

//   src1.bits[0] = 0b00000000000000000000000000101101;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   s21_from_decimal_to_float(src1, srcp);
//   char var3str[1000];
//   char result[1000];
//   snprintf(var3str, sizeof(var3str), "%.6f", 4.5);
//   snprintf(result, sizeof(result), "%f", src2);
//   ck_assert_str_eq(result, var3str);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_floatTest5) {
//   s21_decimal src1;

//   float src2;
//   float *srcp = &src2;

//   src1.bits[0] = 0b00000000000000000000000000101101;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000010000000000000000;
//   s21_from_decimal_to_float(src1, srcp);
//   char var3str[1000];
//   char result[1000];
//   snprintf(var3str, sizeof(var3str), "%.6f", -4.5);
//   snprintf(result, sizeof(result), "%f", src2);
//   ck_assert_str_eq(result, var3str);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_floatTest6) {
//   s21_decimal src1;

//   float src2;
//   float *srcp = &src2;

//   src1.bits[0] = 0b00000000000010000110000110010001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000001010000000000000000;
//   s21_from_decimal_to_float(src1, srcp);
//   char var3str[1000];
//   char result[1000];
//   snprintf(var3str, sizeof(var3str), "%.6f", -5.49265);
//   snprintf(result, sizeof(result), "%f", src2);
//   ck_assert_str_eq(result, var3str);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_floatTest7) {
//   s21_decimal src1;

//   float src2;
//   float *srcp = &src2;

//   src1.bits[0] = 0b01100101111011101101100101011111;
//   src1.bits[1] = 0b01011100001001010100001101000110;
//   src1.bits[2] = 0b00000000000000000000000000000001;
//   src1.bits[3] = 0b00000000000100110000000000000000;
//   s21_from_decimal_to_float(src1, srcp);
//   char var3str[1000];
//   char result[1000];
//   snprintf(var3str, sizeof(var3str), "%.6f", 2.50865312689741);
//   snprintf(result, sizeof(result), "%f", src2);
//   ck_assert_str_eq(result, var3str);
// }
// END_TEST

Suite *suite_from_decimal_to_float(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_float");
  tc = tcase_create("case_from_decimal_to_float");

  tcase_add_test(tc, s21_from_decimal_to_float_1);
  tcase_add_test(tc, s21_from_decimal_to_float_2);
  tcase_add_test(tc, s21_from_decimal_to_float_3);
  tcase_add_test(tc, s21_from_decimal_to_float_4);
  tcase_add_test(tc, s21_from_decimal_to_float_5);

  tcase_add_test(tc, s21_from_decimal_to_float_7);
  tcase_add_test(tc, s21_from_decimal_to_float_8);
  tcase_add_test(tc, s21_from_decimal_to_float_9);
  tcase_add_test(tc, s21_from_decimal_to_float_10);
  // tcase_add_test(tc, s21_from_decimal_to_floatTest1);
  // tcase_add_test(tc, s21_from_decimal_to_floatTest2);
  // tcase_add_test(tc, s21_from_decimal_to_floatTest3);
  // tcase_add_test(tc, s21_from_decimal_to_floatTest4);
  // tcase_add_test(tc, s21_from_decimal_to_floatTest5);
  // tcase_add_test(tc, s21_from_decimal_to_floatTest6);
  // tcase_add_test(tc, s21_from_decimal_to_floatTest7);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(s21_from_decimal_to_int_1) {
  s21_decimal src;
  int result = 0, number = 0;
  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_float_eq(number, 2147483647);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  s21_decimal src;
  int result = 0, number = 0;
  src.bits[0] = 133141;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 133141);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  s21_decimal src;
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 123451234;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -123451234);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_5) {
  s21_decimal src;
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 18;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -18);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_6) {
  s21_decimal src;
  int result = 0, number = 0;
  long int c = 4294967295;
  src.bits[0] = c;
  src.bits[1] = c;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0);
  ck_assert_int_eq(result, 1);
}
END_TEST

int check, result, code;

START_TEST(s21_test_from_decimal_to_int_0) {
  s21_decimal a = {{100, 0, 0, 0}};
  check = 100;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_1) {
  s21_decimal a = {{INT_MAX, 0, 0, 0}};
  check = INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_3) {
  s21_decimal a = {{INT_MAX, INT_MAX, INT_MAX, 0}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_4) {
  s21_decimal a = {{INT_MAX, INT_MAX, INT_MAX, 0}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_6) {
  s21_decimal a = {{-1, -1, 0, 0}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST
START_TEST(s21_test_from_decimal_to_int_7) {
  s21_decimal a = {{-1, -1, -1, 0}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_9) {
  s21_decimal a = {{INT_MAX, 0, 0, NEGATIVE}};
  check = -INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_11) {
  s21_decimal a = {{INT_MAX, 0, 0, 65536}};
  check = 214748364;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

// START_TEST(s21_test_from_decimal_to_int_12) {
//   s21_decimal a = {{INT_MAX, 0, 0, 0b10000000000111000000000000000000}};
//   check = 0;
//   code = s21_from_decimal_to_int(a, &result);
//   ck_assert_int_eq(result, check);
//   ck_assert_int_eq(code, 0);
// }
// END_TEST

// START_TEST(s21_test_from_decimal_to_int_14) {
//   s21_decimal a = {{INT_MAX, 0, 0, 1835008}};
//   check = 0;
//   code = s21_from_decimal_to_int(a, &result);
//   ck_assert_int_eq(result, check);
//   ck_assert_int_eq(code, 0);
// }
// END_TEST

// START_TEST(s21_test_from_decimal_to_int_16) {
//   s21_decimal a;
//   a.bits[0] = 0b00000000000000000000000000000001;
//   a.bits[1] = 0b00000000000000000000000000000000;
//   a.bits[2] = 0b00000000000000000000000000000000;
//   a.bits[3] = 0b00000000000000000000000000000000;
//   check = 1;
//   code = s21_from_decimal_to_int(a, &result);
//   ck_assert_int_eq(result, check);
//   ck_assert_int_eq(code, 0);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest1) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, 2);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest3) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000000000000000000000000100011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, 3);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest4) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000000000000000000000000101101;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, 4);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest5) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000000000000000000000000101101;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000010000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, -4);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest6) {
//   s21_decimal src1;
//   int code = 0;

//   src1.bits[0] = 0b10110011000011000010101010010001;
//   src1.bits[1] = 0b00000000000000000000000000001100;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000001110000000000000000;
//   int result;

//   code = s21_from_decimal_to_int(src1, &result);
//   ck_assert_int_eq(result, -5454);
//   ck_assert_int_eq(code, 0);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest7) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000111100110110001111110011000;
//   src1.bits[1] = 0b01100110010010001001000110100011;
//   src1.bits[2] = 0b00000000000001001000101100011101;
//   src1.bits[3] = 0b10000000000110000000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, -5);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest8) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00011011110101100011100010001010;
//   src1.bits[1] = 0b00000000000000101101010000010100;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000001100000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, 796132784);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest9) {
//   s21_decimal src1;

//   src1.bits[0] = 0b01111000100010101111010011001010;
//   src1.bits[1] = 0b01100010000010101110010010000111;
//   src1.bits[2] = 0b00100111111001000001101011010101;
//   src1.bits[3] = 0b10000000000101010000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, -12345677);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest10) {
//   s21_decimal src1;

//   src1.bits[0] = 0b01100101111011101101100101011111;
//   src1.bits[1] = 0b01011100001001010100001101000110;
//   src1.bits[2] = 0b00000000000000000000000000000001;
//   src1.bits[3] = 0b00000000000100110000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, 2);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest11) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000000000000000000000000000001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, 1);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest12) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000000000000000000000001111101;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000100000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, 1);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest13) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000000000000000000000001111101;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000100000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, -1);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest14) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000000000000000000010011001001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000100000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, -12);
// }
// END_TEST

// START_TEST(s21_from_decimal_to_intTest15) {
//   s21_decimal src1;

//   src1.bits[0] = 0b00000000000000000000000000100011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000010000000000000000;
//   int result;
//   int *res = &result;
//   s21_from_decimal_to_int(src1, res);
//   ck_assert_int_eq(result, -3);
// }
// END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_int");
  tc = tcase_create("case_from_decimal_to_int");

  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);

  tcase_add_test(tc, s21_from_decimal_to_int_4);
  tcase_add_test(tc, s21_from_decimal_to_int_5);
  tcase_add_test(tc, s21_from_decimal_to_int_6);

  tcase_add_test(tc, s21_test_from_decimal_to_int_0);
  tcase_add_test(tc, s21_test_from_decimal_to_int_1);

  tcase_add_test(tc, s21_test_from_decimal_to_int_3);
  tcase_add_test(tc, s21_test_from_decimal_to_int_4);

  tcase_add_test(tc, s21_test_from_decimal_to_int_6);

  tcase_add_test(tc, s21_test_from_decimal_to_int_7);
  tcase_add_test(tc, s21_test_from_decimal_to_int_9);

  tcase_add_test(tc, s21_test_from_decimal_to_int_11);
  // tcase_add_test(tc, s21_test_from_decimal_to_int_12);
  // tcase_add_test(tc, s21_test_from_decimal_to_int_14);
  // tcase_add_test(tc, s21_test_from_decimal_to_int_16);
  // tcase_add_test(tc, s21_from_decimal_to_intTest1);
  // tcase_add_test(tc, s21_from_decimal_to_intTest3);
  // tcase_add_test(tc, s21_from_decimal_to_intTest4);
  // tcase_add_test(tc, s21_from_decimal_to_intTest5);
  // tcase_add_test(tc, s21_from_decimal_to_intTest6);
  // tcase_add_test(tc, s21_from_decimal_to_intTest7);
  // tcase_add_test(tc, s21_from_decimal_to_intTest8);
  // tcase_add_test(tc, s21_from_decimal_to_intTest9);
  // tcase_add_test(tc, s21_from_decimal_to_intTest10);
  // tcase_add_test(tc, s21_from_decimal_to_intTest11);
  // tcase_add_test(tc, s21_from_decimal_to_intTest12);
  // tcase_add_test(tc, s21_from_decimal_to_intTest13);
  // tcase_add_test(tc, s21_from_decimal_to_intTest14);
  // tcase_add_test(tc, s21_from_decimal_to_intTest15);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(s21_from_float_to_decimal_1) {
  s21_decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);

  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
  s21_decimal val;
  float fl1 = 22.36E+03;
  float fl2 = -2.1474E+09;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
  s21_decimal val;
  s21_from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_6) {
  s21_decimal val;
  float fl1 = -33.2222;
  float fl2 = -2.146E+20;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_7) {
  s21_decimal val;
  float a = 1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_8) {
  s21_decimal val;
  float a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_10) {
  s21_decimal val;
  float a = 1e-30;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_11) {
  s21_decimal dec;
  float tmp = 0;
  float tmp1 = 0.03;
  s21_from_float_to_decimal(tmp1, &dec);
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, tmp1, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_12) {
  s21_decimal dec;
  s21_from_float_to_decimal(-128.023, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -128.023, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_13) {
  s21_decimal dec;
  s21_from_float_to_decimal(-2.1474E+09, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -2.1474E+09, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_14) {
  s21_decimal dec;
  s21_from_float_to_decimal(22.14836E+03, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 22.14836E+03, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_15) {
  s21_decimal dec;
  s21_from_float_to_decimal(1.02E+08, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 1.02E+08, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_16) {
  s21_decimal dec;
  s21_from_float_to_decimal(-333.2222, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -333.2222, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
  s21_decimal dec;
  float a = 1.0 / 0.0;
  int ret = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  s21_decimal dec;
  float a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(dec.bits[0], 0);
  ck_assert_int_eq(dec.bits[1], 0);
  ck_assert_int_eq(dec.bits[2], 0);
  ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_float_to_decimal");
  tc = tcase_create("case_from_float_to_decimal");

  tcase_add_test(tc, s21_from_float_to_decimal_1);
  tcase_add_test(tc, s21_from_float_to_decimal_2);
  tcase_add_test(tc, s21_from_float_to_decimal_3);
  tcase_add_test(tc, s21_from_float_to_decimal_4);
  tcase_add_test(tc, s21_from_float_to_decimal_5);
  tcase_add_test(tc, s21_from_float_to_decimal_6);
  tcase_add_test(tc, s21_from_float_to_decimal_7);
  tcase_add_test(tc, s21_from_float_to_decimal_8);
  tcase_add_test(tc, s21_from_float_to_decimal_10);
  tcase_add_test(tc, s21_from_float_to_decimal_11);
  tcase_add_test(tc, s21_from_float_to_decimal_12);
  tcase_add_test(tc, s21_from_float_to_decimal_13);
  tcase_add_test(tc, s21_from_float_to_decimal_14);
  tcase_add_test(tc, s21_from_float_to_decimal_15);
  tcase_add_test(tc, s21_from_float_to_decimal_16);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(s21_from_int_to_decimal_1) {
  s21_decimal val;

  s21_from_int_to_decimal(0, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  s21_from_int_to_decimal(127, &val);
  ck_assert_int_eq(val.bits[0], 127);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  s21_from_int_to_decimal(-2147483645, &val);
  ck_assert_int_eq(val.bits[0], 2147483645);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], -2147483648);

  s21_from_int_to_decimal(2147483647, &val);
  ck_assert_int_eq(val.bits[0], 2147483647);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

int a, add, equal;

START_TEST(s21_test_from_int_to_decimal_0) {
  a = 100;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);
  s21_decimal etalon = {{100, 0, 0, 0}};
  ck_assert_int_eq(add, 0);

  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_from_int_to_decimal_1) {
  a = 100;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);
  s21_decimal etalon = {{1000, 0, 0, 0}};
  ck_assert_int_eq(add, 0);

  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_test_from_int_to_decimal_2) {
  a = INT_MAX;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);
  s21_decimal etalon = {{INT_MAX, 0, 0, 0}};
  ck_assert_int_eq(add, 0);

  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_from_int_to_decimal_3) {
  a = -INT_MAX;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);
  s21_decimal etalon = {{INT_MAX, 0, 0, 0}};
  ck_assert_int_eq(add, 0);

  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_test_from_int_to_decimal_4) {
  a = -INT_MAX;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);
  s21_decimal etalon = {{INT_MAX, 0, 0, ~(INT_MAX)}};
  ck_assert_int_eq(add, 0);

  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_from_int_to_decimal_5) {
  a = 0;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);
  s21_decimal etalon = {{INT_MAX, 0, 0, ~(INT_MAX)}};
  ck_assert_int_eq(add, 0);

  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(from_int_to_decimal_0) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_1) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

// START_TEST(s21_from_int_to_decimalTest1) {
//   int src1 = 1;
//   s21_decimal origin, result;
//   s21_decimal *res = &result;
//   s21_from_int_to_decimal(src1, res);

//   origin.bits[0] = 0b00000000000000000000000000000001;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_from_int_to_decimalTest2) {
//   int src1 = -1;
//   s21_decimal origin, result;
//   s21_decimal *res = &result;
//   s21_from_int_to_decimal(src1, res);

//   origin.bits[0] = 0b00000000000000000000000000000001;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_from_int_to_decimalTest3) {
//   int src1 = 0;
//   s21_decimal origin, result;
//   s21_decimal *res = &result;
//   s21_from_int_to_decimal(src1, res);

//   origin.bits[0] = 0b00000000000000000000000000000000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_from_int_to_decimalTest4) {
//   int src1 = 0;
//   s21_decimal origin, result;
//   s21_decimal *res = &result;
//   s21_from_int_to_decimal(src1, res);

//   origin.bits[0] = 0b00000000000000000000000000000000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_from_int_to_decimalTest5) {
//   int src1 = -987879878;
//   s21_decimal origin, result;
//   s21_decimal *res = &result;
//   s21_from_int_to_decimal(src1, res);

//   origin.bits[0] = 0b00111010111000011101100111000110;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_from_int_to_decimalTest6) {
//   int src1 = -2147483646;
//   s21_decimal origin, result;
//   s21_decimal *res = &result;
//   s21_from_int_to_decimal(src1, res);

//   origin.bits[0] = 0b01111111111111111111111111111110;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_from_int_to_decimalTest7) {
//   int src1 = 2147483646;
//   s21_decimal origin, result;
//   s21_decimal *res = &result;
//   s21_from_int_to_decimal(src1, res);

//   origin.bits[0] = 0b01111111111111111111111111111110;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_from_int_to_decimalTest8) {
//   int src1 = 796132784;
//   s21_decimal origin, result;
//   s21_decimal *res = &result;
//   s21_from_int_to_decimal(src1, res);

//   origin.bits[0] = 0b00101111011101000000010110110000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_from_int_to_decimalTest9) {
//   int src1 = -12345677;
//   s21_decimal origin, result;
//   s21_decimal *res = &result;
//   s21_from_int_to_decimal(src1, res);
//   origin.bits[0] = 0b00000000101111000110000101001101;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

Suite *suite_from_int_to_decimal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_int_to_decimal");
  tc = tcase_create("case_from_int_to_decimal");

  tcase_add_test(tc, s21_from_int_to_decimal_1);

  tcase_add_test(tc, s21_test_from_int_to_decimal_0);
  tcase_add_test(tc, s21_test_from_int_to_decimal_1);
  tcase_add_test(tc, s21_test_from_int_to_decimal_2);
  tcase_add_test(tc, s21_test_from_int_to_decimal_3);
  tcase_add_test(tc, s21_test_from_int_to_decimal_4);
  tcase_add_test(tc, s21_test_from_int_to_decimal_5);
  // tcase_add_test(tc, s21_from_int_to_decimalTest1);
  // tcase_add_test(tc, s21_from_int_to_decimalTest2);
  // tcase_add_test(tc, s21_from_int_to_decimalTest3);
  // tcase_add_test(tc, s21_from_int_to_decimalTest4);
  // tcase_add_test(tc, s21_from_int_to_decimalTest5);
  // tcase_add_test(tc, s21_from_int_to_decimalTest6);
  // tcase_add_test(tc, s21_from_int_to_decimalTest7);
  // tcase_add_test(tc, s21_from_int_to_decimalTest8);
  // tcase_add_test(tc, s21_from_int_to_decimalTest9);
  tcase_add_test(tc, from_int_to_decimal_0);
  tcase_add_test(tc, from_int_to_decimal_1);

  suite_add_tcase(s, tc);
  return s;
}
