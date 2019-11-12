#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCalculate_clicked();

private:
    Ui::MainWindow *ui;

    /* DESCRIPTION :    Evaluates number of choosen E-Series which matches the best the given value
    * INPUTS :          double value    -> value of which closest E-Series number should be evaluated
    *                   double* eSerie  -> Pointer to the choosen E-Series
    * OUTPUTS :         double number   -> evaluated E-Series number
    */
    double findClosest(double value, const double* eSerie);

};

#endif // MAINWINDOW_H
