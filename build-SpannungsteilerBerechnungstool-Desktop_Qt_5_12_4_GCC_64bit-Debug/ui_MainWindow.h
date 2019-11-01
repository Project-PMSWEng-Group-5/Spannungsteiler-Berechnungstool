/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_ber_Spannungsteiler_Berechnungstool;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *lbl_inputVoltage;
    QLabel *lbl_outputVoltage;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *txt_inputVoltage;
    QLineEdit *txt_outputVoltage;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *lbl_R1value;
    QLabel *lbl_R2value;
    QGroupBox *grb_ESeries;
    QRadioButton *rb_E3;
    QRadioButton *rb_E6;
    QRadioButton *rb_E12;
    QRadioButton *rb_E24;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(850, 490);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../pictures/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_ber_Spannungsteiler_Berechnungstool = new QAction(MainWindow);
        action_ber_Spannungsteiler_Berechnungstool->setObjectName(QString::fromUtf8("action_ber_Spannungsteiler_Berechnungstool"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 411, 381));
        label->setPixmap(QPixmap(QString::fromUtf8("../pictures/VoltageDivider.png")));
        label->setScaledContents(true);
        lbl_inputVoltage = new QLabel(centralWidget);
        lbl_inputVoltage->setObjectName(QString::fromUtf8("lbl_inputVoltage"));
        lbl_inputVoltage->setGeometry(QRect(40, 187, 71, 50));
        lbl_outputVoltage = new QLabel(centralWidget);
        lbl_outputVoltage->setObjectName(QString::fromUtf8("lbl_outputVoltage"));
        lbl_outputVoltage->setGeometry(QRect(310, 262, 71, 50));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 30, 170, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 80, 170, 20));
        txt_inputVoltage = new QLineEdit(centralWidget);
        txt_inputVoltage->setObjectName(QString::fromUtf8("txt_inputVoltage"));
        txt_inputVoltage->setGeometry(QRect(650, 30, 140, 25));
        txt_outputVoltage = new QLineEdit(centralWidget);
        txt_outputVoltage->setObjectName(QString::fromUtf8("txt_outputVoltage"));
        txt_outputVoltage->setGeometry(QRect(650, 80, 140, 25));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 130, 170, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(480, 180, 170, 20));
        lbl_R1value = new QLabel(centralWidget);
        lbl_R1value->setObjectName(QString::fromUtf8("lbl_R1value"));
        lbl_R1value->setGeometry(QRect(650, 130, 170, 20));
        lbl_R2value = new QLabel(centralWidget);
        lbl_R2value->setObjectName(QString::fromUtf8("lbl_R2value"));
        lbl_R2value->setGeometry(QRect(650, 180, 170, 20));
        grb_ESeries = new QGroupBox(centralWidget);
        grb_ESeries->setObjectName(QString::fromUtf8("grb_ESeries"));
        grb_ESeries->setGeometry(QRect(480, 230, 311, 151));
        rb_E3 = new QRadioButton(grb_ESeries);
        rb_E3->setObjectName(QString::fromUtf8("rb_E3"));
        rb_E3->setGeometry(QRect(10, 30, 211, 23));
        rb_E6 = new QRadioButton(grb_ESeries);
        rb_E6->setObjectName(QString::fromUtf8("rb_E6"));
        rb_E6->setGeometry(QRect(10, 60, 211, 23));
        rb_E12 = new QRadioButton(grb_ESeries);
        rb_E12->setObjectName(QString::fromUtf8("rb_E12"));
        rb_E12->setGeometry(QRect(10, 90, 211, 23));
        rb_E24 = new QRadioButton(grb_ESeries);
        rb_E24->setObjectName(QString::fromUtf8("rb_E24"));
        rb_E24->setGeometry(QRect(10, 120, 211, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, mainToolBar);
        MainWindow->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Spannungsteiler-Berechnungstool", nullptr));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        action_ber_Spannungsteiler_Berechnungstool->setText(QApplication::translate("MainWindow", "\303\234ber Spannungsteiler-Berechnungstool", nullptr));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        label->setText(QString());
#ifndef QT_NO_TOOLTIP
        lbl_inputVoltage->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lbl_inputVoltage->setText(QString());
#ifndef QT_NO_TOOLTIP
        lbl_outputVoltage->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lbl_outputVoltage->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Eingangsspannung [V]:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Ausgangsspannung [V]:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Widerstand R1:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Widerstand R2:", nullptr));
        lbl_R1value->setText(QString());
        lbl_R2value->setText(QString());
        grb_ESeries->setTitle(QApplication::translate("MainWindow", "E-Reihe", nullptr));
        rb_E3->setText(QApplication::translate("MainWindow", "E3, Toleranz > \302\261 20%", nullptr));
        rb_E6->setText(QApplication::translate("MainWindow", "E6, Toleranz \302\261 20%", nullptr));
        rb_E12->setText(QApplication::translate("MainWindow", "E12, Toleranz \302\261 10%", nullptr));
        rb_E24->setText(QApplication::translate("MainWindow", "E24, Toleranz \302\261 5%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
