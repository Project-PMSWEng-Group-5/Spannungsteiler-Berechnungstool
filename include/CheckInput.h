#ifndef CHECKINPUT_H
#define CHECKINPUT_H

#include <QString>

typedef enum
{
  NoError,
  InputVoltageNotOk,
  OutputVoltageNotOk,
  OutputVoltageHigherThanInputVoltage,
  NoValues
} ErrorType;

/*! \brief A Test class
 *  Includes both functions for user input check.
 */
class Test
{
 public:
  /*! \brief Verifies the plausibility of the values entered by the user.
   * \param QString* str1 -> Pointer to the Input Voltage Value.
   * \param QString* str2 -> Pointer to the Output Voltage Value.
   * \return char -> 1: Everything OK and 0: An Error.
   */
  int checkInputfromKeyboard(QString* str1, QString* str2);

  /*! \brief Replaces each "," sign with a "." sign so it can be converted to a
   * double.
   * \param QString* str1 -> Pointer to the Input Voltage Value.
   * \param QString* str2 -> Pointer to the Output Voltage Value.
   */
  void replaceInvalidChar(QString& str1, QString& str2);

 private:
};

#endif  // CHECKINPUT_H
