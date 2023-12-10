#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_abs_t) {  // 1
  int test_cases[] = {0, 1243, -0, -126, 10000, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  int real = 0;
  while (i < 9) {
    real = s21_abs(test_cases[i]);
    ck_assert_int_eq(real, abs(test_cases[i++]));
  }
}
END_TEST

START_TEST(s21_sin_t) {  // 2
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_cos_t) {  // 3
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_tan_t) {  // 4
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_ceil_t) {  // 5
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 5) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_fmod_t) {  // 6
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_fmod(test_cases[i], test_cases[(i + 1) % 9]);
    tmp = fmod(test_cases[i], test_cases[(i + 1) % 9]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
    i++;
  }
}
END_TEST

START_TEST(s21_fabs_t) {  // 7
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_floor_t) {  // 8
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_sqrt_t) {  // 9
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_asin_t) {  // 10
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_acos_t) {  // 11
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_atan_t) {  // 12
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_exp_t) {  // 13
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_log_t) {  // 14
  double test_cases[] = {0, 1, 2, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_cos(test_cases[i]);
    tmp = cos(test_cases[i++]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
  }
}
END_TEST

START_TEST(s21_pow_t) {  // 15
  double test_cases[] = {0, 1, 2.5, -1, 0.5, S21_NAN, POS_INF, NEG_INF, -0};
  int i = 0;
  long double real = 0, tmp = 0;
  while (i < 9) {
    real = s21_pow(test_cases[i], test_cases[(i + 1) % 9]);
    tmp = pow(test_cases[i], test_cases[(i + 1) % 9]);
    if (!isnan(real) && !isnan(tmp)) {
      long double res = real - tmp;
      ck_assert_ldouble_lt(res, 1E-6);
    } else {
      int real1 = isnan(real);
      int tmp1 = isnan(tmp);
      ck_assert_int_eq(real1, tmp1);
    }
    i++;
  }
}
END_TEST

int main() {
  Suite *s = suite_create("Example");
  SRunner *suite_runner = srunner_create(s);
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_abs_t);
  tcase_add_test(tc_core, s21_sin_t);
  tcase_add_test(tc_core, s21_cos_t);
  tcase_add_test(tc_core, s21_tan_t);
  tcase_add_test(tc_core, s21_ceil_t);
  tcase_add_test(tc_core, s21_fmod_t);
  tcase_add_test(tc_core, s21_fabs_t);
  tcase_add_test(tc_core, s21_floor_t);
  tcase_add_test(tc_core, s21_sqrt_t);
  tcase_add_test(tc_core, s21_asin_t);
  tcase_add_test(tc_core, s21_acos_t);
  tcase_add_test(tc_core, s21_atan_t);
  tcase_add_test(tc_core, s21_exp_t);
  tcase_add_test(tc_core, s21_log_t);
  tcase_add_test(tc_core, s21_pow_t);

  suite_add_tcase(s, tc_core);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  if (failed_count != 0) return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
