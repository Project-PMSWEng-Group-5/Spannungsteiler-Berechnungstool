#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

/*! \brief Qt MainWindow
 *  Builds the GUI for the "Spannungsteiler-Berechnungstool".
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  /*! \brief Creates the main window object.
   *  \param parent parent object */
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void on_btnCalculate_clicked();

 private:
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
