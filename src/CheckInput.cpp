#include "../include/CheckInput.h"

int Test::checkInputfromKeyboard(QString* str1, QString* str2)
{
  static QString strTestInput;
  static QString strTestOutput;

  // Convert String to UTF8-Set
  strTestInput = str1->toUtf8();
  strTestOutput = str2->toUtf8();

  // Get String lenght
  int str1Lenght = str1->size();
  int str2Lenght = str2->size();

  // Check if Input/Output has values
  if (str1Lenght == 0 || str2Lenght == 0)
  {
    return NoValues;
  }

  // Check Input Voltage for invalid Characters
  for (int i = 0; i < str1Lenght; ++i)
  {
    if (!(((strTestInput[i] >= ("0")) && (strTestInput[i] <= ("9"))) ||
          (strTestInput[i] == ("."))))
      return InputVoltageNotOk;  // Unknown Character
  }

  // Check Output Voltage for invalid Characters
  for (int i = 0; i < str2Lenght; ++i)
  {
    if (!(((strTestOutput[i] >= ("0")) && (strTestOutput[i] <= ("9"))) ||
          (strTestOutput[i] == ("."))))
      return OutputVoltageNotOk;  // Unknown Character
  }

  // Check if Output Voltage is higher than Input Voltage
  double InputVoltage = str1->toDouble();
  double Outputvoltage = str2->toDouble();

  if (Outputvoltage >= InputVoltage)
    return OutputVoltageHigherThanInputVoltage;  // Output greather or equal
                                                 // than Input

  return NoError;  // Everything OK
}

void Test::replaceInvalidChar(QString& str1, QString& str2)
{
  for (int i = 0; i < (str1.size()); ++i)
  {
    if (str1[i] == ",")
      str1.replace(",", ".");
  }

  for (int i = 0; i < (str2.size()); ++i)
  {
    if (str2[i] == ",")
      str2.replace(",", ".");
  }
}
