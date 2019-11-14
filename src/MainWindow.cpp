#include "../include/MainWindow.h"
#include "ui_MainWindow.h"
#include <QButtonGroup>
#include <cmath>        // std::abs

//Lookup tables for E-Series
const double E3[] = {1.0, 2.2, 4.7,0.0};
const double E6[] = {1.0, 1.5, 2.2, 3.3, 4.7, 6.8,0.0};
const double E12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2,0.0};
const double E24[] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1,0.0};

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
    QButtonGroup* group = new QButtonGroup(this);           // To get checked button easier
    group->addButton(ui->rb_E3,0);
    group->addButton(ui->rb_E6,1);
    group->addButton(ui->rb_E12,2);
    group->addButton(ui->rb_E24,3);
    const double* eSerie;
    eSerie = E3;
    switch(group->checkedId()) {                            // Evaluate the chosen E-Serie
        case 1: eSerie = E6; break;
        case 2: eSerie = E12; break;
        case 3: eSerie = E24; break;
        default: printf("Wrong Id\n"); break;
    }
    double uIn = ui->txt_inputVoltage->text().toDouble();
    double uOut = ui->txt_outputVoltage->text().toDouble();
    double diff = uIn - uOut;                               // voltage over R2
    double R1 = findClosest(diff, eSerie);
    double R2 = findClosest(uOut, eSerie);
    ui->lbl_R1value->setText(QString::number(R1) + " * 10<sup>x</sup> Ω");
    ui->lbl_R2value->setText(QString::number(R2) + " * 10<sup>x</sup> Ω");
}

double MainWindow::findClosest(double value, const double* eSerie)
{
        double delta = abs(eSerie[0]-value);
        double d = 0;
        int index = 0;
        int exponent = 0;                                   // to scale the E-Series value to the correct number
        double num = value;

        while (num < 1) {
            num = num * 10;
            exponent = exponent - 1;
        }
        while (num >= 10) {
            num = num / 10;
            exponent = exponent + 1;
        }
        int n = 1;
        while (eSerie[n] != 0.0){                           // find E-Series value with smallest delta till last value of array ("0.0") reached
            d = abs( eSerie[n] - num);
            if(d <= delta) {
                delta = d;
                index = n;
            }
            ++n;
        }
        num = eSerie[index] * pow(10, double(exponent));
        num = double(round(100*num)/100);                   // round to 2 decimals
        return num;
 }
