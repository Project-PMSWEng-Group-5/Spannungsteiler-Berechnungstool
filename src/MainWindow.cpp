#include "../include/MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  this->setFixedSize(850, 490);

  ui->lbl_inputVoltage->setToolTip("Eingangsspannung");
  ui->lbl_outputVoltage->setToolTip("Ausgangsspannung");
}

MainWindow::~MainWindow()
{
  delete ui;
}
