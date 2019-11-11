#include "../include/MainWindow.h"
#include "ui_MainWindow.h"

const double E3[] = {1.0, 2.2, 4.7};
const double E6[] = {1.0, 1.5, 2.2, 3.3, 4.7, 6.8};
const double E12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};
const double E24[] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1};

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
    const double* eSeries[] = {E3, E6, E12, E24};


    ui->statusBar->showMessage(
        "Status: Hallo");

}
