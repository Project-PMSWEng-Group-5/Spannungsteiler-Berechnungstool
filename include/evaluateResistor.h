#ifndef evaluateResistor_H
#define evaluateResistor_H

class evaluateResistor
{
 public:
  evaluateResistor() = delete;

  static const double E3[];
  static const double E6[];
  static const double E12[];
  static const double E24[];

  /* DESCRIPTION : Evaluates number of chosen E-Series which matches the best
   *               the given value
   * INPUTS :  double value  -> value of which closest E-Series number should be
   *                            evaluated
   *           double* e Serie  -> Pointer to the chosen E-Series
   * OUTPUTS :
   *           double number   -> evaluated E-Series number
   */
  static double findClosest(double value, const double* eSerie);

 private:
};

#endif  // evaluateResistor_H
