#ifndef chooseSeries_H
#define chooseSeries_H

class chooseSeries
{
 public:
  chooseSeries() = delete;

  static const double E3[];
  static const double E6[];
  static const double E9[];
  static const double E12[];

  /* DESCRIPTION :    Evaluates number of chosen E-Series which matches the best
   * the given value INPUTS :          double value    -> value of which closest
   * E-Series number should be evaluated double* eSerie  -> Pointer to the
   * chosen E-Series OUTPUTS :         double number   -> evaluated E-Series
   * number
   */
  static double findClosest(double value, const double* eSerie);

 private:
};

#endif  // chooseSeries_H
