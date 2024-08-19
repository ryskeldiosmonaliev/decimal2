#include "s21_decimal.h"

// Comparison Functions --------------------------------

int s21_is_equal(s21_decimal a, s21_decimal b) { return s21_cmp(&a, &b) == 0; }

int s21_is_not_equal(s21_decimal a, s21_decimal b) {
  return s21_cmp(&a, &b) != 0;
}

int s21_is_less(s21_decimal a, s21_decimal b) { return s21_cmp(&a, &b) == -1; }

int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
  return s21_cmp(&a, &b) != 1;
}

int s21_is_greater(s21_decimal a, s21_decimal b) {
  return s21_cmp(&a, &b) == 1;
}

int s21_is_greater_or_equal(s21_decimal a, s21_decimal b) {
  return s21_cmp(&a, &b) != -1;
}

// Arithmetic Functions --------------------------------

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  if (result) {
    *result = value_1;
    flag = s21_add_handler(result, &value_2);
  }
  return flag;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  if (result) {
    *result = value_1;
    flag = s21_sub_handler(result, &value_2);
  }
  return flag;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  if (result) {
    *result = value_1;
    flag = s21_mul_handler(result, &value_2);
  }
  return flag;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  if (result) {
    *result = value_1;
    s21_decimal zero = {{0}};
    if (s21_is_equal(value_2, zero))
      flag = 3;
    else
      flag = s21_div_handler(result, &value_2);
  }
  return flag;
}

// Conversion Functions --------------------------------
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;
  if (dst) {
    for (int i = 0; i < 4; ++i) dst->bits[i] = 0;
    int sign = src < 0;
    s21_set_sign(dst, sign);
    dst->bits[0] = (sign ? -src : src);
  } else
    flag = 1;
  return flag;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0;
  if (!dst)
    flag = 1;
  else {
    for (int i = 0; i < 4; ++i) dst->bits[i] = 0;
    if (isinf(src) || isnan(src) || fabsf(src) > MAX_FLOAT_TO_CONVERT ||
        fabsf(src) < MIN_FLOAT_TO_CONVERT)
      flag = 1;
    else if (src == 0.0)
      s21_set_sign(dst, signbit(src));
    else {
      char flt[16];
      sprintf(flt, "%.6E", fabsf(src));
      int exp = s21_get_exp_from_string(flt);
      if (exp <= -23) {
        int float_precision = exp + 28;
        sprintf(flt, "%.*E", float_precision, fabsf(src));
      }
      s21_float_string_to_decimal(flt, dst);
      if (src < 0) {
        s21_set_sign(dst, 1);
      }
    }
  }

  return flag;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int flag = 0;
  if (!dst)
    flag = 1;
  else {
    double res;
    s21_decimal zero = {{0}};
    if (s21_is_equal(src, zero))
      res = s21_get_sign(&src) ? -0.0 : 0.0;
    else {
      res = 0.0;
      int sign = s21_get_sign(&src);
      int power = s21_get_pow(&src);
      for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 31; j++) {
          if (s21_bit(src.bits[i], j) != 0) {
            res += pow(2.0, i * 32 + j);
          }
        }
      }
      double power_ten = pow(10, power);
      res /= power_ten;
      if (sign == 1) {
        res *= -1.0;
      }
    }
    *dst = (float)res;
  }
  return flag;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  if (!dst)
    flag = 1;
  else {
    s21_truncate(src, &src);
    s21_decimal min = {{-2147483648, 0, 0, NEGATIVE}};
    s21_decimal max = {{2147483647, 0, 0, POSITIVE}};
    if (s21_is_less(src, min) || s21_is_greater(src, max))
      flag = 1;
    else
      *dst = s21_get_sign(&src) ? -src.bits[0] : src.bits[0];
  }
  return flag;
}

// Other Functions --------------------------------
int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (!result)
    flag = 1;
  else {
    *result = value;
    s21_set_sign(result, !s21_get_sign(result));
  }
  return flag;
}

int s21_truncate(s21_decimal src, s21_decimal *result) {
  int flag = 0;
  if (!result)
    flag = 1;
  else {
    int power = s21_get_pow(&src);
    s21_big_num bn;
    s21_from_decimal_to_big_num(&src, &bn);
    s21_bn_div_10_n_times(&bn, power);
    s21_from_big_num_to_decimal(&bn, result);
    s21_set_pow(result, 0);
    s21_set_sign(result, s21_get_sign(&src));
  }
  return flag;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (!result)
    flag = 1;
  else {
    int power = s21_get_pow(&value);
    s21_big_num bn;
    s21_from_decimal_to_big_num(&value, &bn);
    int rest = s21_bn_div_10_n_times(&bn, power);
    s21_from_big_num_to_decimal(&bn, result);
    s21_set_pow(result, 0);
    s21_set_sign(result, s21_get_sign(&value));
    if (rest > 5 || (rest == 5 && s21_bit(result->bits[0], 0))) {
      s21_decimal tmp = {{1, 0, 0, 0}};
      s21_set_sign(&tmp, s21_get_sign(result));
      s21_add(*result, tmp, result);
    }
  }
  return flag;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (!result)
    flag = 1;
  else {
    s21_truncate(value, result);
    if (s21_get_sign(&value)) {
      s21_decimal one = {{1, 0, 0, 0}};
      s21_sub(*result, one, result);
    }
  }
  return flag;
}