#ifndef CHECKINPUT_H
#define CHECKINPUT_H

#include <QString>

class Test
{
 public:
  /* DESCRIPTION:   Verifies the plausibility of the values entered by the user
   * INPUTS:        QString* str1 -> Pointer to the Input Voltage Value
   *                QString* str2 -> Pointer to the Output Voltage Value
   * OUTPUTS:       char -> 1: Everything OK and 0: An Error
   */
  int checkInputfromKeyboard(QString* str1, QString* str2);

 private:
};

#endif  // CHECKINPUT_H
