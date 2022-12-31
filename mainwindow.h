#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculatecontroller.h"


namespace Ui {
class MainWindow;
}

class Printer
{
    Ui::MainWindow* currentUI_;
    Qt::Alignment currentAlign;

    void adjustAlignment();


public:
    Printer(Ui::MainWindow *currentMainWin);

    void printValue(QString*);
    void printSign(QString*);
    void printResult(baseTypesValue*);
    void printDeleteLastElement(QString*);
    void printStartValue(QString*);
};


class MainWindow : public QMainWindow
{
    Q_OBJECT


    Ui::MainWindow* ui;
    Printer* printer;
    CalculateController calculator;
    bool usingDouble = false;
    static baseTypesValue resultValue;

    void fieldsInit();
    void startConfigurate();
    QString receiveResult();

    struct PossibleValues
    {
        static QString button_0;
        static QString button_1;
        static QString button_2;
        static QString button_3;
        static QString button_4;
        static QString button_5;
        static QString button_6;
        static QString button_7;
        static QString button_8;
        static QString button_9;
        static QString button_dot;
        static QString button_plus;
        static QString button_minus;
        static QString button_division;
        static QString button_multiplication;
        static QString button_currentValues;
        static QString button_clear;
        static QString inputValues;
    };


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_5_clicked();
    void on_Button_6_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();
    void on_Button_Plus_clicked();
    void on_Button_Minus_clicked();
    void on_Button_Multiplication_clicked();
    void on_Button_Division_clicked();
    void on_Button_DeleteLastSymb_clicked();
    void on_Button_Clear_clicked();
    void on_Button_equally_clicked();
    void on_Button_Zero_clicked();
    void on_Button_Dot_clicked();
};

#endif // MAINWINDOW_H
