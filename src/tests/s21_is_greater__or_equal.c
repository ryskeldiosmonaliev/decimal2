#include "s21_test.h"

START_TEST(greater_1) {
  float num1 = 1.375342323523;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_2) {
  float num1 = 1.39;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_3) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_7) {
  int num1 = -3;
  int num2 = 3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_8) {
  float num1 = -3.232446546;
  float num2 = -3.2;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_9) {
  float num1 = -345.232446546;
  float num2 = -3.2;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_10) {
  float num1 = -3.232323233232323233;
  float num2 = -34545124.232446543232446543;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

// START_TEST(s21_greater_11) {
//   s21_decimal dec5 = {
//       {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
//   s21_decimal dec6 = {
//       {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;
//   ck_assert_int_eq(s21_is_greater(dec5, dec6), 1);
//   ck_assert_int_eq(s21_is_greater(dec6, dec5), 0);

//   s21_decimal dec7 = {
//       {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
//   s21_decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};
//   //  1.2; ck_assert_int_eq(s21_is_greater(dec7, dec8), 0);
//   ck_assert_int_eq(s21_is_greater(dec8, dec7), 1);

//   s21_decimal dec1 = {
//       {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
//   s21_decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};
//   //  1.2 ck_assert_int_eq(s21_is_greater(dec1, dec2), 1);
//   ck_assert_int_eq(s21_is_greater(dec2, dec1), 0);

//   s21_decimal dec3 = {
//       {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
//   s21_decimal dec4 = {
//       {12, 0, 0, 0b10000000000000010000000000000000}};  //   -1.2
//   ck_assert_int_eq(s21_is_greater(dec3, dec4), 0);
//   ck_assert_int_eq(s21_is_greater(dec4, dec3), 1);
// }
// END_TEST

START_TEST(s21_test_is_greater_1) {
  s21_decimal a = {{2, 0, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_2) {
  s21_decimal a = {{-1, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_2i) {
  s21_decimal a = {{-1, 0, 0, 0}};
  s21_decimal b = {{-1 - 1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_3) {
  s21_decimal a = {{-1, 0, 0, 0}};
  s21_decimal b = {{-1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_test_is_greater_4) {
  s21_decimal a = {{-1, 0, 0, 0}};
  s21_decimal b = {{-1, 1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_test_is_greater_41) {
  s21_decimal a = {{-1, 1, 0, 0}};
  s21_decimal b = {{-1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_5) {
  s21_decimal a = {{-1, -1, 0, 0}};
  s21_decimal b = {{-1, -1 - 1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_51) {
  s21_decimal a = {{-1, -1, 0, 0}};
  s21_decimal b = {{-1, -1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_test_is_greater_6) {
  s21_decimal a = {{-1, -1, -1, 0}};
  s21_decimal b = {{-1, -1, -1 - 1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_7) {
  s21_decimal a = {{-1, -1, -1 - 1, 0}};
  s21_decimal b = {{-1, -1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_8) {
  s21_decimal a = {{0, -1, -1, 0}};
  s21_decimal b = {{0, -1, -1 - 1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_9) {
  s21_decimal a = {{0, 0, -1, 0}};
  s21_decimal b = {{0, 0, -1 - 1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_10) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, -1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

// START_TEST(s21_is_greaterTest1) {
//   s21_decimal src1, src2;

//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000011;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_greater(src1, src2);
//   int origin = 0;
//   ck_assert_int_eq(result, origin);
// }
// END_TEST

// START_TEST(s21_is_greaterTest2) {
//   // 3838
//   s21_decimal src1, src2;

//   src1.bits[0] = 0b00000000000000000000000000000011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000010;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_greater(src1, src2);
//   int origin = 1;
//   ck_assert_int_eq(result, origin);
// }
// END_TEST

Suite *suite_is_greater(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_greater");
  tc = tcase_create("case_greater");

  tcase_add_test(tc, greater_1);
  tcase_add_test(tc, greater_2);
  tcase_add_test(tc, greater_3);
  tcase_add_test(tc, greater_4);
  tcase_add_test(tc, greater_5);
  tcase_add_test(tc, greater_6);
  tcase_add_test(tc, greater_7);
  tcase_add_test(tc, greater_8);
  tcase_add_test(tc, greater_9);
  tcase_add_test(tc, greater_10);
  // tcase_add_test(tc, s21_greater_11);

  // tcase_add_test(tc, s21_is_greaterTest1);
  // tcase_add_test(tc, s21_is_greaterTest2);

  tcase_add_test(tc, s21_test_is_greater_1);
  tcase_add_test(tc, s21_test_is_greater_2);
  tcase_add_test(tc, s21_test_is_greater_3);
  tcase_add_test(tc, s21_test_is_greater_4);
  tcase_add_test(tc, s21_test_is_greater_5);
  tcase_add_test(tc, s21_test_is_greater_6);
  tcase_add_test(tc, s21_test_is_greater_7);
  tcase_add_test(tc, s21_test_is_greater_8);
  tcase_add_test(tc, s21_test_is_greater_9);
  tcase_add_test(tc, s21_test_is_greater_10);
  tcase_add_test(tc, s21_test_is_greater_51);
  tcase_add_test(tc, s21_test_is_greater_41);
  tcase_add_test(tc, s21_test_is_greater_2i);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(greater_or_equal_1) {
  float num1 = 1.375323;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_or_equal_2) {
  int num1 = 2;
  int num2 = 1;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_or_equal_3) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_or_equal_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_or_equal_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_or_equal_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_or_equal_7) {
  int num1 = 10;
  int num2 = 3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_or_equal_8) {
  float num1 = 10423546.34534534;
  float num2 = 3.34534534;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_or_equal_9) {
  float num1 = -3.34534534;
  float num2 = 3.34534534;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_or_equal_10) {
  float num1 = 1042634.34534534;
  float num2 = 10424546.34534534;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_or_equal_11) {
  float num1 = 10426.34534534;
  float num2 = 104234.345345;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_or_equal_12) {
  float num1 = 1042.5667777;
  float num2 = 1042.345345;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

// START_TEST(s21_greater_or_equal_13) {
//   s21_decimal dec5 = {
//       {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
//   s21_decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //
//   ck_assert_int_eq(s21_is_greater_or_equal(dec5, dec6), 1);
//   ck_assert_int_eq(s21_is_greater_or_equal(dec6, dec5), 0);

//   s21_decimal dec7 = {
//       {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
//   s21_decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};
//   ck_assert_int_eq(s21_is_greater_or_equal(dec7, dec8), 0);
//   ck_assert_int_eq(s21_is_greater_or_equal(dec8, dec7), 1);

//   s21_decimal dec1 = {
//       {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
//   s21_decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};
//   ck_assert_int_eq(s21_is_greater_or_equal(dec1, dec2), 1);
//   ck_assert_int_eq(s21_is_greater_or_equal(dec2, dec1), 0);

//   s21_decimal dec3 = {
//       {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
//   s21_decimal dec4 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //

//   ck_assert_int_eq(s21_is_greater_or_equal(dec3, dec4), 0);
//   ck_assert_int_eq(s21_is_greater_or_equal(dec4, dec3), 1);

//   s21_decimal dec9 = {{12345, 0, 0, 0}};
//   s21_decimal dec10 = {{12345, 0, 0, 0}};
//   ck_assert_int_eq(s21_is_greater_or_equal(dec9, dec10), 1);
//   ck_assert_int_eq(s21_is_greater_or_equal(dec10, dec9), 1);

//   s21_decimal dec11 = {{0, 0, 0, 0}};
//   s21_decimal dec12 = {{0, 0, 0, 0}};
//   ck_assert_int_eq(s21_is_greater_or_equal(dec11, dec12), 1);
//   ck_assert_int_eq(s21_is_greater_or_equal(dec12, dec11), 1);
// }
// END_TEST

Suite *suite_is_greater_or_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_greater_or_equal");
  tc = tcase_create("case_greater_or_equal");

  tcase_add_test(tc, greater_or_equal_1);
  tcase_add_test(tc, greater_or_equal_2);
  tcase_add_test(tc, greater_or_equal_3);
  tcase_add_test(tc, greater_or_equal_4);
  tcase_add_test(tc, greater_or_equal_5);
  tcase_add_test(tc, greater_or_equal_6);
  tcase_add_test(tc, greater_or_equal_7);
  tcase_add_test(tc, greater_or_equal_8);
  tcase_add_test(tc, greater_or_equal_9);
  tcase_add_test(tc, greater_or_equal_10);
  tcase_add_test(tc, greater_or_equal_11);
  tcase_add_test(tc, greater_or_equal_12);
  // tcase_add_test(tc, s21_greater_or_equal_13);
  suite_add_tcase(s, tc);
  return s;
}
