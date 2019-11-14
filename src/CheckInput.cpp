#include "../include/CheckInput.h"

static QString strInput;
static QString strOutput;

char Test::checkInputfromKeyboard(QString* str1, QString* str2)
{
  // Convert String to UTF8-Set
  strInput = str1->toUtf8();
  strOutput = str2->toUtf8();

  // Get String lenght
  int str1Lenght = str1->size();
  int str2Lenght = str2->size();

  // Check Input Voltage for invalid Characters
  for (int i = 0; i < str1Lenght; ++i)
  {
    if (!(((strInput[i] >= ("0")) && (strInput[i] <= ("9"))) ||
          (strInput[i] == ("."))))
      return 0;  // Unknown Character
  }

  // Check Output Voltage for invalid Characters
  for (int i = 0; i < str2Lenght; ++i)
  {
    if (!(((strOutput[i] >= ("0")) && (strOutput[i] <= ("9"))) ||
          (strOutput[i] == ("."))))
      return 0;  // Unknown Character
  }

  // Check if Output Voltage is higher than Input Voltage
  double InputVoltage = str1->toDouble();
  double Outputvoltage = str2->toDouble();

  if (Outputvoltage >= InputVoltage)
    return 0;  // Output higher than Input

  return 1;  // Everything OK
}
