#include "s21_math.h"

int s21_abs(int x) {  // done
  int y = x;
  if (y < 0) y = -y;
  return y;
}

long double s21_sin(double x) {  // done
  x = s21_fmod(x, 2.0 * S21_PI);
  long double n = 2.0;
  long double s = x;
  long double sn = s;
  while (n < 35.0 && s != 0.0) {
    sn = sn * ((-(x * x)) / (n * (n + 1.0)));
    n += 2.0;
    s = s + sn;
  }
  return s;
}

long double s21_cos(double x) {  // done
  x = s21_fmod(x, 2.0 * S21_PI);
  long double cos = s21_sqrt(1.0 - s21_sin(x) * s21_sin(x));
  if (s21_fabs(x) > (S21_PI / 2) && s21_fabs(x) < (3 * S21_PI / 2)) cos = -cos;
  if (x == 0.0) cos = 1;
  if (x == POS_INF) cos = S21_NAN;
  return cos;
}

long double s21_tan(double x) {  // done
  x = s21_fmod(x, 2.0 * S21_PI);
  long double res = s21_sin(x) / s21_cos(x);

  return res;
}

long double s21_ceil(double x) {  // done
  long double y = 0;
  if (S21_ISNAN(x) || S21_ISINF(x) || x == 0.0)
    y = x;
  else if (x - (long long int)x >= 0.0000000000001) {
    y = (long long int)x + 1.0;
  } else {
    y = (long long int)x;
  }
  return y;
}

long double s21_fmod(double x, double y) {  // done
  if (x == 0.0 && y == y && y != 0.0)
    x = x;
  else if (x == 0.0)
    x = S21_NAN;
  else if (S21_ISINF(x) || y == 0 || S21_ISNAN(y))
    x = S21_NAN;
  else if (S21_ISINF(y) && !S21_ISINF(x))
    x = x;
  else if (x / y > 0 && s21_fabs(y) <= s21_fabs(x)) {
    x = x - s21_floor(x / y) * y;
  } else if (x / y < 0 && s21_fabs(y) <= s21_fabs(x)) {
    x = x - s21_ceil(x / y) * y;
  }
  return x;
}

long double s21_fabs(double x) {  // done
  if (x == 0)
    x = 0;
  else if (x < 0.0 && x != POS_INF)
    x = -x;
  return x;
}

long double s21_floor(double x) {  // done
  long double y = 0;
  if (x == 0 || S21_ISINF(x) || S21_ISNAN(x))
    y = x;
  else
    y = (long long int)x;
  return y;
}

long double s21_sqrt(double x) {  // done
  long double z = 1.0;
  if (x < 0)
    z = S21_NAN;
  else if (x == 0.0)
    z = x;
  else if (x == POS_INF)
    z = POS_INF;
  else {
    long double newX = x;
    for (int i = 1; i <= 1000; i++) {
      z -= (z * z - newX) / (2.0 * z);
    }
  }
  return z;
}

long double s21_asin(double z) {  // checked
  long double res = z;
  if (s21_fabs(res) > 1) {
    res = S21_NAN;
  } else {
    if (s21_fabs(res) > 0.9958) res = s21_sqrt(1 - z * z);
    long double base = res;
    int precision = 1;

    while (precision < 3000) {
      res += coeff_for_asin(precision) * pow_for_asin(base, precision * 2 + 1);
      precision++;
    }
    res = (s21_fabs(z) > 0.9958) ? S21_PI / 2 - res : res;
    res = (z < -0.9958) ? -res : res;
  }

  return res;
}

long double s21_acos(double z) {  // checked
  long double acocos = S21_PI / 2 - s21_asin(z);

  return acocos;
}

long double s21_atan(double z) {  // checked
  long double tmp = z / s21_sqrt(1 + z * z);
  long double atatan = s21_asin(tmp);

  return atatan;
}

long double coeff_for_asin(int num) {
  long double divident = 1.0;
  long double divisor = 1.0;
  for (int i = 1.0; i < 2 * num && i <= 1600; i += 2) divident *= i;

  for (int j = 2.0; j < 2 * num + 1 && j <= 1600; j += 2) divisor *= j;
  long double res = divident / divisor;

  if (num > 1600) {
    long double i = 1.0;
    while (i < num) {
      res *= i;
      res /= i++ + 1;
    }
  }

  return res;
}

long double pow_for_asin(long double base, int exp) {
  long double b = 1.0;
  for (long double i = 0.0; i < exp; i++) b *= base;
  long double div = exp;
  long double res = b / div;

  return res;
}

long double s21_exp(double z) {  // checked
  long double res = 1 + z;
  if (z < -25.209099) {
    res = 0.000000;
  } else if (z > 709.782712) {
    res = POS_INF;
  } else {
    int precision = 2;

    while (precision < 4000) res += pow_for_exp(z, precision++);
  }
  return res;
}

long double pow_for_exp(long double x, int exp) {
  long double res = 1.0;
  for (int i = 0; i < exp; i++) {
    res *= x;
    long double div = i + 1.0;
    res /= div;
  }

  return res;
}

long double s21_taylor_log(double x) {
  long double result = x, member = x;
  for (int flag = 2; s21_fabs(member) > S21_EPS; flag++) {
    member *= -((flag - 1) * (x / flag));
    result += member;
  }
  return result;
}

long double s21_log(double x) {
  long double result;
  if (x <= 0.0 || S21_ISNAN(x)) {
    result = S21_NAN;
  } else if (S21_ISINF(x)) {
    result = S21_INF;
  } else {
    int accuracy = 0;
    while ((int)x >= 2) {
      accuracy++;
      x /= 2;
    }
    result = accuracy * S21_LN2 + s21_taylor_log(x - 1);
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double retval = 1.0;
  if (exp != exp || base != base) {
    retval = S21_NAN;
  } else if (exp == -S21_INF && base != S21_NAN) {
    retval = 0;
  } else if (exp == S21_INF && base != S21_NAN) {
    retval = S21_INF;
  } else {
    if (exp > 0) {
      for (int i = 0; i < (long long int)exp; i++) {
        retval = retval * base;
      }
    } else if (exp < 0) {
      for (int i = 0; i > (long long int)exp; i--) {
        retval = retval / base;
      }
    }
    long double mantis_exp = s21_fabs(exp) - s21_fabs((long long int)exp);
    if (mantis_exp > 0) {
      if (exp > 0) {
        retval = retval * s21_exp(mantis_exp * s21_log(base));
      } else if (exp < 0) {
        retval = retval * s21_exp(mantis_exp * s21_log(1 / base));
      }
    }
  }

  return retval;
}
