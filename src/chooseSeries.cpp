#include "../include/chooseSeries.h"
#include <cmath>  // std::abs

// Lookup tables for E-Series
const double chooseSeries::E3[] = {1.0, 2.2, 4.7, 0.0};
const double chooseSeries::E6[] = {1.0, 1.5, 2.2, 3.3, 4.7, 6.8, 0.0};
const double chooseSeries::E12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3,
                                    3.9, 4.7, 5.6, 6.8, 8.2, 0.0};
const double chooseSeries::E24[] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2,
                                    2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1,
                                    5.6, 6.2, 6.8, 7.5, 8.2, 9.1, 0.0};

double chooseSeries::findClosest(double value, const double* eSerie)
{
  double delta = abs(eSerie[0] - value);
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
    d = abs(eSerie[n] - num);
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
