#ifndef HEADER_MATH_H
#define HEADER_MATH_H

#define S21_PI 3.141592653589793238462
#define POS_INF 1.0 / 0.0
#define NEG_INF -1.0 / 0.0
#define S21_EPS 1e-17
#define S21_NAN 0.0 / 0.0
#define S21_INF 1 / 0.0
#define S21_LN10 2.3025850929940456
#define S21_LN2 0.6931471805599453
#define S21_ISNAN(x) (!(x >= 0) && !(x < 0))
#define S21_ISINF(x) ((x == S21_INF) || (x == -S21_INF))
//#define TAYLOR_LIMIT 5000

int s21_abs(int x);                        // 1
long double s21_ceil(double x);            // 2
long double s21_cos(double x);             // 3
long double s21_fabs(double x);            // 4
long double s21_fmod(double x, double y);  // 5
long double s21_sin(double x);             // 6
long double s21_exp(double x);             // 7
long double s21_floor(double x);           // 8
long double s21_sqrt(double x);            // 9

long double s21_asin(double z);  // 10
long double coeff_for_asin(int num);
long double pow_for_asin(long double base, int exp);
long double s21_acos(double z);  // 11
long double s21_atan(double z);  // 12

long double s21_exp(double z);  // 7.1
long double pow_for_exp(long double x, int exp);
long double s21_log(double z);  // 13
long double s21_taylor_log(double x);
long double s21_pow(double base, double exp);  // 14
long double s21_tan(double x);                 // 15

#endif  // HEADER_MATH_H
