#include "../include/MainWindow.h"
#include <QButtonGroup>
#include "../include/CheckInput.h"
#include "../include/evaluateResistor.h"
#include "ui_MainWindow.h"

// Objects for Strings
static QString strInput;
static QString strOutput;
static Test T;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  this->setFixedSize(850, 490);

  ui->statusBar->showMessage(
      "Status: Bitte E-Reihe wählen und gültige Spannungswerte eingeben!");

  ui->lbl_inputVoltage->setToolTip("Eingangsspannung");
  ui->lbl_outputVoltage->setToolTip("Ausgangsspannung");

  ui->rb_E3->setToolTipDuration(30000);
  ui->rb_E3->setToolTip(
      "Werte:\n"
      "- 1\n"
      "- 2,2\n"
      "- 4,7");

  ui->rb_E6->setToolTipDuration(30000);
  ui->rb_E6->setToolTip(
      "Werte:\n"
      "- 1\n"
      "- 1,5\n"
      "- 2,2\n"
      "- 3,3\n"
      "- 4,7\n"
      "- 6,8");

  ui->rb_E12->setToolTipDuration(30000);
  ui->rb_E12->setToolTip(
      "Werte:\n"
      "- 1\n"
      "- 1,2\n"
      "- 1,5\n"
      "- 1,8\n"
      "- 2,2\n"
      "- 2,7\n"
      "- 3,3\n"
      "- 3,9\n"
      "- 4,7\n"
      "- 5,6\n"
      "- 6,8\n"
      "- 8,2");

  ui->rb_E24->setToolTipDuration(30000);
  ui->rb_E24->setToolTip(
      "Werte:\n"
      "- 1\n"
      "- 1,1\n"
      "- 1,2\n"
      "- 1,3\n"
      "- 1,5\n"
      "- 1,6\n"
      "- 1,8\n"
      "- 2\n"
      "- 2,2\n"
      "- 2,4\n"
      "- 2,7\n"
      "- 3\n"
      "- 3,3\n"
      "- 3,6\n"
      "- 3,9\n"
      "- 4,3\n"
      "- 4,7\n"
      "- 5,1\n"
      "- 5,6\n"
      "- 6,2\n"
      "- 6,8\n"
      "- 7,5\n"
      "- 8,2\n"
      "- 9,1");
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_btnCalculate_clicked()
{
  QButtonGroup* group = new QButtonGroup(this);  // To get checked button easier
  group->addButton(ui->rb_E3, 0);
  group->addButton(ui->rb_E6, 1);
  group->addButton(ui->rb_E12, 2);
  group->addButton(ui->rb_E24, 3);
  const double* eSerie;
  eSerie = evaluateResistor::E3;
  switch (group->checkedId())
  {  // Evaluate the chosen E-Serie
    case 1:
      eSerie = evaluateResistor::E6;
      break;
    case 2:
      eSerie = evaluateResistor::E12;
      break;
    case 3:
      eSerie = evaluateResistor::E24;
      break;
    default:
      printf("Wrong Id\n");
      break;
  }

  // Read user input
  strInput = ui->txt_inputVoltage->text();
  strOutput = ui->txt_outputVoltage->text();

  // Replace comma with point for double conversion
  T.replaceInvalidChar(strInput, strOutput);

  // Verify input
  switch (T.checkInputfromKeyboard(&strInput, &strOutput))
  {
    case NoError:  // Input validated
    {
      double uIn = strInput.toDouble();
      double uOut = strOutput.toDouble();
      double diff = uIn - uOut;  // voltage over R2
      double R1 = evaluateResistor::findClosest(diff, eSerie);
      double R2 = evaluateResistor::findClosest(uOut, eSerie);
      ui->lbl_R1value->setText(QString::number(R1) + " * 10<sup>x</sup> Ω");
      ui->lbl_R2value->setText(QString::number(R2) + " * 10<sup>x</sup> Ω");
      ui->statusBar->setStyleSheet("color: black");
      ui->statusBar->showMessage("Fertig");
      break;
    }

    case InputVoltageNotOk:
    {
      ui->statusBar->setStyleSheet("color: red");
      ui->statusBar->showMessage(
          "Bitte gültigen Wert für die Eingangsspannung eingeben");
      break;
    }

    case OutputVoltageNotOk:
    {
      ui->statusBar->setStyleSheet("color: red");
      ui->statusBar->showMessage(
          "Bitte gültigen Wert für die Ausgangsspannung eingeben");
      break;
    }

    case OutputVoltageHigherThanInputVoltage:
    {
      ui->statusBar->setStyleSheet("color: red");
      ui->statusBar->showMessage(
          "Ausgangsspannung ist grösser oder gleich der Eingangsspannung");
      break;
    }

    case NoValues:
    {
      ui->statusBar->setStyleSheet("color: red");
      ui->statusBar->showMessage("Bitte zuerst Spannungswerte eingeben");
      break;
    }

    default:  // Unknown Error
    {
      ui->statusBar->setStyleSheet("color: red");
      ui->statusBar->showMessage("Ein unbekannter Fehler ist aufgetreten!");
      break;
    }
  }
}
