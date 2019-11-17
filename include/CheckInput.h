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

class Test
{
 public:
  /* DESCRIPTION:   Verifies the plausibility of the values entered by the user
   * INPUTS:        QString* str1 -> Pointer to the Input Voltage Value
   *                QString* str2 -> Pointer to the Output Voltage Value
   * OUTPUTS:       char -> 1: Everything OK and 0: An Error
   */
  int checkInputfromKeyboard(QString* str1, QString* str2);

  /* DESCRIPTION:   Replaces each "," sign with a "." sign so it can be
   *                converted to a double
   * INPUTS:        QString* str1 -> Pointer to the Input Voltage Value
   *                QString* str2 -> Pointer to the Output Voltage Value
   * OUTPUTS:       none
   */
  void replaceInvalidChar(QString& str1, QString& str2);

 private:
};

#endif  // CHECKINPUT_H
