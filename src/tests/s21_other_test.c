#include "s21_test.h"

START_TEST(s21_negate_1) {
  int a = 15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(-15, res_a);
}
END_TEST

START_TEST(s21_negate_2) {
  float a = 10.12345;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.12345, res_a);
}
END_TEST

START_TEST(s21_negate_3) {
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

START_TEST(s21_negate_4) {
  float a = -10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(10.1234e5, res_a);
}
END_TEST

START_TEST(s21_negate_5) {
  int a = -15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(15, res_a);
}
END_TEST

START_TEST(s21_test_negate_0) {
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  int negate = s21_negate(b, &etalon);
  ck_assert_int_eq(negate, 0);
}
END_TEST

START_TEST(s21_test_negate_1) {
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_2) {
  s21_decimal a = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{1, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_3) {
  s21_decimal a = {{100, 0, 0, 0}};
  s21_decimal etalon = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_4) {
  s21_decimal a = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{100, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_5) {
  s21_decimal a = {{-1, 0, 0, 0}};
  s21_decimal etalon = {{-1, 0, 0, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_6) {
  s21_decimal a = {{-1, -1, -1, 0}};
  s21_decimal etalon = {{-1, -1, -1, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_test_negate_7) {
  s21_decimal a = {{-1, -1, -1, 0}};
  s21_decimal etalon = {{-1, -1, -1, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_8) {
  s21_decimal a = {{-1, -1, -1, ~(INT_MAX)}};
  s21_decimal etalon = {{-1, -1, -1, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_1) {
  s21_decimal val = {{2, 0, 0, ~(-1 / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_2) {
  s21_decimal val = {{0, 0, 0, ~(-1 / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_3) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

Suite *suite_negate(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_negate");
  tc = tcase_create("case_negate");
  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  tcase_add_test(tc, s21_negate_5);

  tcase_add_test(tc, s21_test_negate_0);
  tcase_add_test(tc, s21_test_negate_1);
  tcase_add_test(tc, s21_test_negate_2);
  tcase_add_test(tc, s21_test_negate_3);
  tcase_add_test(tc, s21_test_negate_4);
  tcase_add_test(tc, s21_test_negate_5);
  tcase_add_test(tc, s21_test_negate_6);
  tcase_add_test(tc, s21_test_negate_7);
  tcase_add_test(tc, s21_test_negate_8);

  tcase_add_test(tc, negate_0);
  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_3);
  suite_add_tcase(s, tc);
  return s;
}

// START_TEST(s21_round_1) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10010011111100000001110001010010;
//   dec1.bits[1] = 0b00000000000000000000000100100000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000010100000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000001111100;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_3) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b11111111111111111111111111111111;
//   dec1.bits[1] = 0b00000000001111111111111111111111;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000110000000000000000;
//   s21_decimal result;

//   result.bits[0] = 0b01001101110100101111000110101001;
//   result.bits[1] = 0b00000000000000000001000001100010;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_4) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b00000000000011110111001001110100;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000000110000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000001111110100;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_5) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10000000000000000000001111110100;
//   dec1.bits[1] = 0b00000000000001000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000001110000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000110101101011111110101111101;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_6) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10000000000000000000001111110100;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b10000000000000000000001111110100;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_7) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b01100011000011111111111111111111;
//   dec1.bits[1] = 0b01101011110001110101111000101101;
//   dec1.bits[2] = 0b00000000000000000000000000000101;
//   dec1.bits[3] = 0b10000000000010100000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b01010100000010111110010000000000;
//   result.bits[1] = 0b00000000000000000000000000000010;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_9) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b10010011111100000001110001010010;
//   dec1.bits[1] = 0b00000000000000000000000100100000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000010100000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000001111100;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_10) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b10010111011100111001111111111111;
//   dec1.bits[1] = 0b00111100000010000011000110001101;
//   dec1.bits[2] = 0b00000000000000000000000000000001;
//   dec1.bits[3] = 0b00000000000001110000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   s21_decimal result;
//   result.bits[0] = 0b00110110101101101000110001000000;
//   result.bits[1] = 0b00000000000000000000001000010010;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_11) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b10010111011100111001111111111111;
//   dec1.bits[1] = 0b00111100000010000011000110001101;
//   dec1.bits[2] = 0b00000000000000000000000000000001;
//   dec1.bits[3] = 0b10000000000001110000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   s21_decimal result;
//   result.bits[0] = 0b00110110101101101000110001000000;
//   result.bits[1] = 0b00000000000000000000001000010010;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;

//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_roundTest1) {
  s21_decimal src1 = {{2, 0, 0, 0}};
  s21_decimal result;
  s21_round(src1, &result);
  s21_decimal origin = {{2, 0, 0, 0}};
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

// START_TEST(s21_roundTest3) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000100011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000010000000000000000;
//   s21_decimal result = {0};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000100;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest4) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
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

// START_TEST(s21_roundTest5) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b11011110101101001010101001100001;
//   src1.bits[1] = 0b11110100111110000101111011101001;
//   src1.bits[2] = 0b00000000000000000000000000000010;
//   src1.bits[3] = 0b10000000000001010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b10000110011101001011101110010001;
//   origin.bits[1] = 0b00000000000000011111000000010110;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest6) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b01001110111001000011100101110110;
//   src1.bits[1] = 0b01001011001101011010000111011001;
//   src1.bits[2] = 0b00011001101110010111010010111111;
//   src1.bits[3] = 0b00000000000011110000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b10100100000111100100000000101110;
//   origin.bits[1] = 0b00000000000000000000011100111101;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest10) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b10101111110010001101100101011111;
//   src1.bits[1] = 0b01101000101000101011010010000001;
//   src1.bits[2] = 0b00000000000000000000000000000001;
//   src1.bits[3] = 0b00000000000100110000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest11) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000000001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
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

// START_TEST(s21_roundTest12) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000001011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
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

// START_TEST(s21_roundTest9) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000001011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
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

// START_TEST(s21_roundTest8) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000100110011000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000100000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000011000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest7) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000100001001100;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000110000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

Suite *suite_round(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_round");
  tc = tcase_create("case_round");
  // tcase_add_test(tc, s21_round_1);

  // tcase_add_test(tc, s21_round_3);
  // tcase_add_test(tc, s21_round_4);
  // tcase_add_test(tc, s21_round_5);
  // tcase_add_test(tc, s21_round_6);
  // tcase_add_test(tc, s21_round_7);
  // tcase_add_test(tc, s21_round_9);
  // tcase_add_test(tc, s21_round_10);
  // tcase_add_test(tc, s21_round_11);
  tcase_add_test(tc, s21_roundTest1);
  // tcase_add_test(tc, s21_roundTest3);
  // tcase_add_test(tc, s21_roundTest4);
  // tcase_add_test(tc, s21_roundTest5);
  // tcase_add_test(tc, s21_roundTest6);
  // tcase_add_test(tc, s21_roundTest7);
  // tcase_add_test(tc, s21_roundTest8);
  // tcase_add_test(tc, s21_roundTest9);
  // tcase_add_test(tc, s21_roundTest10);
  // tcase_add_test(tc, s21_roundTest11);
  // tcase_add_test(tc, s21_roundTest12);

  suite_add_tcase(s, tc);
  return s;
}

// START_TEST(s21_floor_1) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10010011111100000001110001010010;
//   dec1.bits[1] = 0b00000000000000000000000100100000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000010100000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000001111011;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_floor(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_floor_2) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b00000000000000000000000010100101;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000010000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000000010000;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_floor(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_floor_3) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10010011111111111111110001010010;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000110000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000001001011110001101010011;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_floor(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_floor_4) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10010011111111111111110001010011;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000000110000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000001001011110001101010100;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_floor(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_floor_6) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b00001111111111111111111111111111;
//   dec1.bits[1] = 0b00111110001001010000001001100001;
//   dec1.bits[2] = 0b00100000010011111100111001011110;
//   dec1.bits[3] = 0b10000000000010100000000000000000;
//   s21_decimal res1;
//   s21_floor(dec1, &res1);
//   s21_decimal result;
//   result.bits[0] = 0b10100111011001000000000000000000;
//   result.bits[1] = 0b00001101111000001011011010110011;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_floor_7) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b10111101001001111000010001010010;
//   dec1.bits[1] = 0b00000000000000000000000000011100;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000010010000000000000000;
//   s21_decimal res1;
//   s21_floor(dec1, &res1);
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000001111100;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_floor_9) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b01010101001110101110101110110001;
//   dec1.bits[1] = 0b00001101101101001101101001011111;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000100100000000000000000;
//   s21_decimal res1;
//   s21_floor(dec1, &res1);
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000000000001;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_floor_01) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10010011111100000001110001010010;
//   dec1.bits[1] = 0b00000000000000000000000100100000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000010100000000000000000;
//   float num = 0.0;
//   s21_from_decimal_to_float(dec1, &num);
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000001111011;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_floor(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_floor_02) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b00000000000000000000000010100101;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000010000000000000000;
//   float num = 0.0;
//   s21_from_decimal_to_float(dec1, &num);

//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000000010000;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_floor(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_floorTest1) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest2) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b00000000000000000000000000100011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   origin.bits[0] = 0b00000000000000000000000000000011;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest3) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b00000000000000000000000000100011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000010000000000000000;
//   origin.bits[0] = 0b00000000000000000000000000000100;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest4) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   origin.bits[0] = 0b00000000000000000000000000000000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest5) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b00000000000000000000000000001100;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000010000000000000000;
//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest6) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b10000010111000100101101011101101;
//   src1.bits[1] = 0b11111001111010000010010110101101;
//   src1.bits[2] = 0b10110000001111101111000010010100;
//   src1.bits[3] = 0b10000000000011100000000000000000;
//   origin.bits[0] = 0b10000110011101001011101110010010;
//   origin.bits[1] = 0b00000000000000011111000000010110;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest7) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b00000111100110110001111110011000;
//   src1.bits[1] = 0b01100110010010001001000110100011;
//   src1.bits[2] = 0b00000000000001001000101100011101;
//   src1.bits[3] = 0b10000000000110000000000000000000;
//   origin.bits[0] = 0b00000000000000000000000000000110;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest8) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b01001110111001000011100101110110;
//   src1.bits[1] = 0b01001011001101011010000111011001;
//   src1.bits[2] = 0b00011001101110010111010010111111;
//   src1.bits[3] = 0b00000000000011110000000000000000;
//   origin.bits[0] = 0b10100100000111100100000000101101;
//   origin.bits[1] = 0b00000000000000000000011100111101;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest9) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b01111000100010101111010011001010;
//   src1.bits[1] = 0b01100010000010101110010010000111;
//   src1.bits[2] = 0b00100111111001000001101011010101;
//   src1.bits[3] = 0b10000000000101010000000000000000;

//   origin.bits[0] = 0b00000000101111000110000101001110;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest10) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b00010010001110001101100101011111;
//   src1.bits[1] = 0b00110001000111111101100110110011;
//   src1.bits[2] = 0b00000000000000000000000000000001;
//   src1.bits[3] = 0b00000000000100110000000000000000;
//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_floorTest11) {
//   s21_decimal src1, origin, result = {{0, 0, 0, 0}};

//   src1.bits[0] = 0b00000000000000000000000000000001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   origin.bits[0] = 0b00000000000000000000000000000001;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   s21_floor(src1, &result);
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

Suite *suite_floor(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_floor");
  tc = tcase_create("case_floor");
  // tcase_add_test(tc, s21_floor_1);
  // tcase_add_test(tc, s21_floor_2);
  // tcase_add_test(tc, s21_floor_3);
  // tcase_add_test(tc, s21_floor_4);

  // tcase_add_test(tc, s21_floor_6);
  // tcase_add_test(tc, s21_floor_7);

  // tcase_add_test(tc, s21_floor_9);

  // tcase_add_test(tc, s21_floor_01);
  // tcase_add_test(tc, s21_floor_02);
  // tcase_add_test(tc, s21_floorTest1);
  // tcase_add_test(tc, s21_floorTest2);
  // tcase_add_test(tc, s21_floorTest3);
  // tcase_add_test(tc, s21_floorTest4);
  // tcase_add_test(tc, s21_floorTest5);
  // tcase_add_test(tc, s21_floorTest6);
  // tcase_add_test(tc, s21_floorTest7);
  // tcase_add_test(tc, s21_floorTest8);
  // tcase_add_test(tc, s21_floorTest9);
  // tcase_add_test(tc, s21_floorTest10);
  // tcase_add_test(tc, s21_floorTest11);
  suite_add_tcase(s, tc);
  return s;
}

// START_TEST(s21_trun_1) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b00000000000000000000000011010011;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000010000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000000010101;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_truncate(dec1, &res1);
//   ck_assert_int_eq(res1.bits[0], result.bits[0]);
//   ck_assert_int_eq(res1.bits[1], result.bits[1]);
//   ck_assert_int_eq(res1.bits[2], result.bits[2]);
//   ck_assert_int_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_trun_2) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b00000000000000000000000010100101;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000010000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000000010000;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_truncate(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_trun_3) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b11111111111111111111111111111111;
//   dec1.bits[1] = 0b11111111111111111111111111111111;
//   dec1.bits[2] = 0b11111111111111111111111111111111;
//   dec1.bits[3] = 0b00000000000000010000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b10011001100110011001100110011001;
//   result.bits[1] = 0b10011001100110011001100110011001;
//   result.bits[2] = 0b00011001100110011001100110011001;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_truncate(dec1, &res1);
//   ck_assert_int_eq(res1.bits[0], result.bits[0]);
//   ck_assert_int_eq(res1.bits[1], result.bits[1]);
//   ck_assert_int_eq(res1.bits[2], result.bits[2]);
//   ck_assert_int_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_trun_4) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10000000000000000000000010100101;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000001110000000000000000;
//   float num = 0.0;
//   s21_from_decimal_to_float(dec1, &num);
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000011010110;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_truncate(dec1, &res1);
//   ck_assert_int_eq(res1.bits[0], result.bits[0]);
//   ck_assert_int_eq(res1.bits[1], result.bits[1]);
//   ck_assert_int_eq(res1.bits[2], result.bits[2]);
//   ck_assert_int_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal dec1;

  dec1.bits[3] = 0x000A0000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x0;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x6DF37F67;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_truncate_2) {
//   s21_decimal dec1;

//   dec1.bits[3] = 0b10000000000011000000000000000000;
//   dec1.bits[2] = 0x0;
//   dec1.bits[1] = 0xFFFFFFFF;
//   dec1.bits[0] = 0xFFFFFFFF;
//   s21_decimal result;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   result.bits[2] = 0x0;
//   result.bits[1] = 0x0;
//   result.bits[0] = 0x1197998;
//   s21_decimal res1;
//   s21_truncate(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal dec1;

  dec1.bits[3] = 0x80000000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x80000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0xFFFFFFFF;
  result.bits[0] = 0xFFFFFFFF;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_truncate_4) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b00000000000000000000000001101101;
//   dec1.bits[1] = 0b00000000000011000110010101011011;
//   dec1.bits[2] = 0b00000000000000000011000000111001;
//   dec1.bits[3] = 0b00000000000011100000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b10000111101111000001011000011110;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_truncate(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_truncate_5) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b11011110101001001000000010110110;
//   dec1.bits[1] = 0b01011111101001011101111110100000;
//   dec1.bits[2] = 0b00011111111010011010111101100000;
//   dec1.bits[3] = 0b00000000000010010000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00110100101011011100000100111110;
//   result.bits[1] = 0b10001001000100001000011110111001;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_truncate(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal dec1;

  dec1.bits[3] = 0x80090000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xFFFFEA34;
  dec1.bits[0] = 0xFF837E4F;
  s21_decimal result;
  s21_truncate(dec1, &result);
  s21_decimal res1;

  res1.bits[3] = 0x80000000;
  res1.bits[2] = 0;
  res1.bits[1] = 0x4;
  res1.bits[0] = 0x4B829C70;
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
}
END_TEST

// START_TEST(s21_truncate_7) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b11010000101000110011000001101101;
//   dec1.bits[1] = 0b00011111100110100110101101011000;
//   dec1.bits[2] = 0;
//   dec1.bits[3] = 0b00000000000010010000000000000000;
//   s21_decimal result;
//   s21_truncate(dec1, &result);
//   s21_decimal result_origin;
//   result_origin.bits[3] = 0;
//   result_origin.bits[2] = 0;
//   result_origin.bits[1] = 0;
//   result_origin.bits[0] = 0b10000111101111000001011000011110;
//   ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_truncate_8) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b01111000101001111011110011000110;
//   dec1.bits[1] = 0b10011111111111001111101010000100;
//   dec1.bits[2] = 0b00011111111010011010111101101101;
//   dec1.bits[3] = 0b00000000000111000000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000000000000;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_truncate(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_truncateTest1) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_truncateTest2) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000100011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

//   origin.bits[0] = 0b00000000000000000000000000000011;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_truncateTest3) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

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

// START_TEST(s21_truncateTest4) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

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

// START_TEST(s21_truncateTest5) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b01001100110100101000000111000101;
//   src1.bits[1] = 0b00000000000000000000000000000010;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

//   origin.bits[0] = 0b01001100110100101000000111000101;
//   origin.bits[1] = 0b00000000000000000000000000000010;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_truncateTest6) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b10000010111000100101101011101101;
//   src1.bits[1] = 0b11111001111010000010010110101101;
//   src1.bits[2] = 0b10110000001111101111000010010100;
//   src1.bits[3] = 0b10000000000011100000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

//   origin.bits[0] = 0b10000110011101001011101110010001;
//   origin.bits[1] = 0b00000000000000011111000000010110;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_truncateTest7) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000111100110110001111110011000;
//   src1.bits[1] = 0b01100110010010001001000110100011;
//   src1.bits[2] = 0b00000000000001001000101100011101;
//   src1.bits[3] = 0b10000000000110000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

//   origin.bits[0] = 0b00000000000000000000000000000101;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_truncateTest8) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b01001110111001000011100101110110;
//   src1.bits[1] = 0b01001011001101011010000111011001;
//   src1.bits[2] = 0b00011001101110010111010010111111;
//   src1.bits[3] = 0b00000000000011110000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

//   origin.bits[0] = 0b10100100000111100100000000101101;
//   origin.bits[1] = 0b00000000000000000000011100111101;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_truncateTest9) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b01111000100010101111010011001010;
//   src1.bits[1] = 0b01100010000010101110010010000111;
//   src1.bits[2] = 0b00100111111001000001101011010101;
//   src1.bits[3] = 0b10000000000101010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

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

// START_TEST(s21_truncateTest10) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b01100101111011101101100101011111;
//   src1.bits[1] = 0b01011100001001010100001101000110;
//   src1.bits[2] = 0b00000000000000000000000000000001;
//   src1.bits[3] = 0b00000000000100110000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_truncateTest11) {
//   s21_decimal src1, origin;

//   src1.bits[0] = 0b00000000000000000000000000000001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_truncate(src1, &result);

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

Suite *suite_truncate(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_truncate");
  tc = tcase_create("case_truncate");
  // tcase_add_test(tc, s21_trun_1);
  // tcase_add_test(tc, s21_trun_2);
  // tcase_add_test(tc, s21_trun_3);
  // tcase_add_test(tc, s21_trun_4);
  tcase_add_test(tc, s21_truncate_1);
  // tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_3);
  // tcase_add_test(tc, s21_truncate_4);
  // tcase_add_test(tc, s21_truncate_5);
  tcase_add_test(tc, s21_truncate_6);
  // tcase_add_test(tc, s21_truncate_7);
  // tcase_add_test(tc, s21_truncate_8);
  // tcase_add_test(tc, s21_truncateTest1);
  // tcase_add_test(tc, s21_truncateTest2);
  // tcase_add_test(tc, s21_truncateTest3);
  // tcase_add_test(tc, s21_truncateTest4);
  // tcase_add_test(tc, s21_truncateTest5);
  // tcase_add_test(tc, s21_truncateTest6);
  // tcase_add_test(tc, s21_truncateTest7);
  // tcase_add_test(tc, s21_truncateTest8);
  // tcase_add_test(tc, s21_truncateTest9);
  // tcase_add_test(tc, s21_truncateTest10);
  // tcase_add_test(tc, s21_truncateTest11);

  suite_add_tcase(s, tc);
  return s;
}
