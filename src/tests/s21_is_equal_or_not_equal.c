#include "s21_test.h"

START_TEST(equal_1) {
  float num1 = 1.375342323523;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_2) {
  float num1 = 1.39;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(equal_3) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(equal_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(equal_7) {
  float num1 = 7.0000003;
  float num2 = 1.1;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_8) {
  float num1 = 7.9e+28;
  float num2 = 1.342;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_9) {
  float num1 = 7.9e+25;
  float num2 = 1.342;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_10) {
  float num1 = NAN;
  float num2 = 2.3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

// START_TEST(s21_equal_11) {
//   s21_decimal dec1 = {
//       {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
//   s21_decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //
//   -1.2 ck_assert_int_eq(s21_is_equal(dec1, dec2), 0);

//   s21_decimal dec3 = {
//       {120000, 0, 0, 0b00000000000001000000000000000000}};  //  12.0000
//   s21_decimal dec4 = {{12, 0, 0, 0}};                       // 12
//   ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);

//   s21_decimal dec5 = {{0, 0, 0, 0}};                                    //  0
//   s21_decimal dec6 = {{00, 0, 0, 0b00000000000000010000000000000000}};  //
//   0.0 ck_assert_int_eq(s21_is_equal(dec5, dec6), 1);

//   s21_decimal dec7 = {{0, 0, 0, 0}};         //   0
//   s21_decimal dec8 = {{0, 0, 0, NEGATIVE}};  // -0;
//   ck_assert_int_eq(s21_is_equal(dec7, dec8), 1);
// }
// END_TEST

// START_TEST(s21_equal_null_12) {
//   s21_decimal dec1, dec2;
//   s21_from_int_to_decimal(0, &dec1);
//   s21_from_int_to_decimal(0, &dec2);
//   dec1.bits[3] = 0;
//   ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
// }
// END_TEST

// START_TEST(s21_is_equalTest1) {
//   s21_decimal src1, src2;
//   // src1 = 2;
//   // src2 = 3;

//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000011;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_equal(src1, src2);
//   int origin = 0;
//   ck_assert_int_eq(result, origin);
// }
// END_TEST

// START_TEST(s21_is_equalTest2) {
//   s21_decimal src1, src2;
//   // src1 = 3;
//   // src2 = 2;

//   src1.bits[0] = 0b00000000000000000000000000000011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;

//   src2.bits[0] = 0b00000000000000000000000000000010;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_equal(src1, src2);
//   int origin = 0;
//   ck_assert_int_eq(result, origin);
// }
// END_TEST

// START_TEST(s21_is_equalTest3) {
//   s21_decimal src1, src2;
//   // src1 = 3;
//   // src2 = 3;

//   src1.bits[0] = 0b00000000000000000000000000000011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;

//   src2.bits[0] = 0b00000000000000000000000000000011;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_equal(src1, src2);
//   int origin = 1;
//   ck_assert_int_eq(result, origin);
// }
// END_TEST

// START_TEST(s21_is_equalTest4) {
//   s21_decimal src1, src2;
//   // src1 = 2;
//   // src2 = 0;

//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;

//   src2.bits[0] = 0b00000000000000000000000000000000;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_equal(src1, src2);
//   int origin = 0;
//   ck_assert_int_eq(result, origin);
// }
// END_TEST

// START_TEST(s21_is_equalTest5) {
//   s21_decimal src1, src2;
//   // src1 = 0;
//   // src2 = 3;

//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;

//   src2.bits[0] = 0b00000000000000000000000000000011;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_equal(src1, src2);
//   int origin = 0;
//   ck_assert_int_eq(result, origin);
// }
// END_TEST

Suite *suite_is_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_is_equal");
  tc = tcase_create("case_is_equal");

  tcase_add_test(tc, equal_1);
  tcase_add_test(tc, equal_2);
  tcase_add_test(tc, equal_3);
  tcase_add_test(tc, equal_4);
  tcase_add_test(tc, equal_5);
  tcase_add_test(tc, equal_6);
  tcase_add_test(tc, equal_7);
  tcase_add_test(tc, equal_8);
  tcase_add_test(tc, equal_9);
  tcase_add_test(tc, equal_10);
  // tcase_add_test(tc, s21_equal_11);
  // tcase_add_test(tc, s21_equal_null_12);

  // tcase_add_test(tc, s21_is_equalTest1);
  // tcase_add_test(tc, s21_is_equalTest2);
  // tcase_add_test(tc, s21_is_equalTest3);
  // tcase_add_test(tc, s21_is_equalTest4);
  // tcase_add_test(tc, s21_is_equalTest5);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(not_equal_1) {
  float num1 = 1.375342323523;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(not_equal_2) {
  float num1 = 1.39;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(not_equal_3) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(not_equal_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(not_equal_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(not_equal_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

// START_TEST(s21_not_equal_7) {
//   s21_decimal dec1 = {
//       {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
//   s21_decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //
//   -1.2; ck_assert_int_eq(s21_is_not_equal(dec1, dec2), 1);

//   s21_decimal dec3 = {
//       {120000, 0, 0, 0b00000000000001000000000000000000}};  //  12.0000
//   s21_decimal dec4 = {{12, 0, 0, 0b00000000000000000000000000000000}};  //
//   ck_assert_int_eq(s21_is_not_equal(dec3, dec4), 0);

//   s21_decimal dec5 = {{0, 0, 0, 0}};                                    //  0
//   s21_decimal dec6 = {{00, 0, 0, 0b00000000000000010000000000000000}};  //
//   ck_assert_int_eq(s21_is_not_equal(dec5, dec6), 0);

//   s21_decimal dec7 = {{0, 0, 0, 0}};         //   0
//   s21_decimal dec8 = {{0, 0, 0, NEGATIVE}};  //  -0;
//   ck_assert_int_eq(s21_is_not_equal(dec7, dec8), 0);
// }
// END_TEST

Suite *suite_is_not_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_is_not_equal");
  tc = tcase_create("case_is_not_equal");

  tcase_add_test(tc, not_equal_1);
  tcase_add_test(tc, not_equal_2);
  tcase_add_test(tc, not_equal_3);
  tcase_add_test(tc, not_equal_4);
  tcase_add_test(tc, not_equal_5);
  tcase_add_test(tc, not_equal_6);
  // tcase_add_test(tc, s21_not_equal_7);

  suite_add_tcase(s, tc);
  return s;
}
