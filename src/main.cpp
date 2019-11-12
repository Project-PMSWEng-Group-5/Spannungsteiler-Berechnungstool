#include <QApplication>
#include "../include/MainWindow.h"
#include <cmath>        // std::abs

const double E3[] = {1.0, 2.2, 4.7};
const double E6[] = {1.0, 1.5, 2.2, 3.3, 4.7, 6.8};
const double E12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};
const double E24[] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1};


/* DESCRIPTION :    Evaluates number of choosen E-Series which matches the best the given value
* INPUTS :          double value    -> value of which closest E-Series number should be evaluated
*                   double* eSeries -> Pointer to the choosen E-Series
*                   int size        -> Size of the choosen E-Series-Array
* OUTPUTS :         double number   -> evaluated E-Series number
*/
double findClosest( double value, double* eSeries, int size);

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}

double findClosest( double value, double* eSeries)
{
        double delta = abs(eSeries[0]-value);
        double d = 0;
        int index = 0;
        int exponent = 0;
        double num = value;

        while (num < 1) {
            num = num * 10;
            exponent = exponent - 1;
        }
        while (num >= 10) {
            num = num / 10;
            exponent = exponent + 1;
        }
        for (int n = 1; n < sizeof(eSeries)/sizeof(eSeries[0]); ++n){
            d = abs( eSeries[n] - num);
            if(d <= delta) {
                delta = d;
                index = n;
            }
        }
        num = eSeries[index] * pow(10, double(exponent));
        num = double(round(100*num)/100); //round to 2 decimals
        return num;
 }
