#include "mainwindow.h"
#include "ui_mainwindow.h"


QString MainWindow::PossibleValues::button_0 = "0";
QString MainWindow::PossibleValues::button_1 = "1";
QString MainWindow::PossibleValues::button_2 = "2";
QString MainWindow::PossibleValues::button_3 = "3";
QString MainWindow::PossibleValues::button_4 = "4";
QString MainWindow::PossibleValues::button_5 = "5";
QString MainWindow::PossibleValues::button_6 = "6";
QString MainWindow::PossibleValues::button_7 = "7";
QString MainWindow::PossibleValues::button_8 = "8";
QString MainWindow::PossibleValues::button_9 = "9";
QString MainWindow::PossibleValues::button_dot = ".";
QString MainWindow::PossibleValues::button_plus = "+";
QString MainWindow::PossibleValues::button_minus = "-";
QString MainWindow::PossibleValues::button_division = "/";
QString MainWindow::PossibleValues::button_multiplication = "*";
QString MainWindow::PossibleValues::button_currentValues = "";
QString MainWindow::PossibleValues::button_clear = "0";
QString MainWindow::PossibleValues::inputValues = "";

baseTypesValue MainWindow::resultValue;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fieldsInit();
    startConfigurate();
}
void MainWindow::fieldsInit()
{
    printer = new Printer(ui);
}
void MainWindow::startConfigurate()
{
    ui->TextEdit_Values->setStyleSheet("font: 85 24pt 'Times New Roman';");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_1_clicked()
{
    printer->printValue(&PossibleValues::button_1);
}
void MainWindow::on_Button_2_clicked()
{
    printer->printValue(&PossibleValues::button_2);
}
void MainWindow::on_Button_3_clicked()
{
    printer->printValue(&PossibleValues::button_3);
}
void MainWindow::on_Button_4_clicked()
{
    printer->printValue(&PossibleValues::button_4);
}
void MainWindow::on_Button_5_clicked()
{
    printer->printValue(&PossibleValues::button_5);
}
void MainWindow::on_Button_6_clicked()
{
    printer->printValue(&PossibleValues::button_6);
}
void MainWindow::on_Button_7_clicked()
{
    printer->printValue(&PossibleValues::button_7);
}
void MainWindow::on_Button_8_clicked()
{
    printer->printValue(&PossibleValues::button_8);
}
void MainWindow::on_Button_9_clicked()
{
    printer->printValue(&PossibleValues::button_9);
}
void MainWindow::on_Button_Plus_clicked()
{
    printer->printSign(&PossibleValues::button_plus);
}
void MainWindow::on_Button_Minus_clicked()
{
    printer->printSign(&PossibleValues::button_minus);
}
void MainWindow::on_Button_Multiplication_clicked()
{
    printer->printSign(&PossibleValues::button_multiplication);
}
void MainWindow::on_Button_Division_clicked()
{
    printer->printSign(&PossibleValues::button_division);
}
void MainWindow::on_Button_DeleteLastSymb_clicked()
{
    PossibleValues::button_currentValues = ui->TextEdit_Values->toPlainText();
    printer->printDeleteLastElement(&PossibleValues::button_currentValues);
}
void MainWindow::on_Button_Clear_clicked()
{
    printer->printStartValue(&PossibleValues::button_clear);
}
void MainWindow::on_Button_equally_clicked()
{
    TYPE_CONVERTION_RESULT(resultValue) = receiveResult();

    printer->printResult(&resultValue);
}
void MainWindow::on_Button_Zero_clicked()
{
    printer->printValue(&PossibleValues::button_0);
}
void MainWindow::on_Button_Dot_clicked()
{
    usingDouble = true;
    printer->printValue(&PossibleValues::button_dot);
}

QString MainWindow::receiveResult()
{
    PossibleValues::inputValues = ui->TextEdit_Values->toPlainText();

    if(usingDouble)
        return QString::number(calculator.calculateResult(&PossibleValues::inputValues, double()));
    else
        return QString::number(calculator.calculateResult(&PossibleValues::inputValues, int()));
}


Printer::Printer(Ui::MainWindow *currentMainWin): currentUI_(currentMainWin)
{
    currentAlign.setFlag(Qt::AlignmentFlag::AlignRight, true);
}

void Printer::printValue(QString* value)
{
    if(currentUI_->TextEdit_Values->toPlainText() == "0")
        currentUI_->TextEdit_Values->setText(*value);
    else
        currentUI_->TextEdit_Values->setText(currentUI_->TextEdit_Values->toPlainText().append(*value));

    adjustAlignment();
}
void Printer::printSign(QString* sign)
{
    currentUI_->TextEdit_Values->append(*sign);
    currentUI_->TextEdit_Values->append(""); //switching to a new line

    adjustAlignment();
}
void Printer::printResult(baseTypesValue* result)
{
    currentUI_->TextEdit_Values->setText(TYPE_CONVERTION_RESULT(*result));

    adjustAlignment();
}
void Printer::printDeleteLastElement(QString* currentText)
{
    QString bufferText;
    for(int i = 0; i < currentText->size() - 1; i++)
        bufferText[i] = currentText->at(i);

    currentUI_->TextEdit_Values->setText(bufferText);

    adjustAlignment();
}
void Printer::printStartValue(QString* startValue)
{
    currentUI_->TextEdit_Values->setText(*startValue);
    adjustAlignment();
}
void Printer::adjustAlignment()
{
    currentUI_->TextEdit_Values->setAlignment(currentAlign);
}
