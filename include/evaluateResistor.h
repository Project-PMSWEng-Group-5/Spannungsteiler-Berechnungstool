#ifndef evaluateResistor_H
#define evaluateResistor_H

/*!
\brief evaluateResistor Class
 
 this class is a helper Class for the findClosest() method.
*/
class evaluateResistor
{
 public:
  evaluateResistor() = delete;

  static const double E3[];
  static const double E6[];
  static const double E12[];
  static const double E24[];

    /*!
    \brief find best matching E-Series value for parameter value

    \param value represents the value for which the best maching E-Series value should be evaluated
    \param eSerie represents the choosen E-Serie
    \return best matching E-Serie value for value
    returned */
  static double findClosest(double value, const double* eSerie);

 private:
};

#endif  // evaluateResistor_H
