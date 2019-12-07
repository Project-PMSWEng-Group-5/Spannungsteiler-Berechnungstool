#include "../include/evaluateResistor.h"
#include <float.h>  //DBL_MAX
#include <cassert>
#include <cmath>  // std::fabs

// Lookup tables for E-Series
const double evaluateResistor::E3[] = {1.0, 2.2, 4.7, 0.0};
const double evaluateResistor::E6[] = {1.0, 1.5, 2.2, 3.3, 4.7, 6.8, 0.0};
const double evaluateResistor::E12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3,
                                        3.9, 4.7, 5.6, 6.8, 8.2, 0.0};
const double evaluateResistor::E24[] = {
    1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3,
    3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1, 0.0};

double evaluateResistor::findClosest(double value, const double* eSerie)
{
  assert(value > 0);              // negative
  assert(value < DBL_MAX / 100);  // inf

  double delta = fabs(eSerie[0] - value);
  double d = 0;
  int index = 0;
  int exponent = 0;  // to scale the E-Series value to the correct number
  double num = value;

  while (num < 1)
  {
    num = num * 10;
    exponent = exponent - 1;
  }
  while (num >= 10)
  {
    num = num / 10;
    exponent = exponent + 1;
  }
  int n = 1;

  while (eSerie[n] != 0.0)
  {  // find E-Series value with smallest delta till last value of array ("0.0")
     // reached
    d = fabs(eSerie[n] - num);
    if (d <= delta)
    {
      delta = d;
      index = n;
    }
    ++n;
  }
  num = eSerie[index] * pow(10, double(exponent));
  num = double(round(100 * num) / 100);  // round to 2 decimals
  return num;
}
