#ifndef CALCULATECONTROLLER_H
#define CALCULATECONTROLLER_H

#include "calculator.h"


class CalculateController
{
    QVector<QString> inputValues;
    Calculator calculator;
    size_t numInputValues_ = 0;

    void preparationInputValues(QString* enterData)
    {
        inputValues.resize(1);
        inputValues.fill("");
        numInputValues_ = 0;

        for(QString enterSymbol : *enterData)
        {
            if(enterSymbol == "+" or enterSymbol == "-" or enterSymbol == "*" or enterSymbol == "/")
            {
                inputValues.append(enterSymbol);
                inputValues.append("");
                numInputValues_ += 2;
            }
            else
                inputValues[inputValues.size() - 1].append(enterSymbol);
        }
    }


public:
    CalculateController()
    {
        inputValues.reserve(15);
    }

    template <typename T> T calculateResult(QString* enterData, T value)
    {
        preparationInputValues(enterData);

        value = (T)inputValues[0].toDouble();
        for(int i = 2; i <= numInputValues_; i += 2)
        {
            if(inputValues[i - 1] == "+")
                value = calculator.add(value, (T)inputValues[i].toDouble());
            else if(inputValues[i - 1] == "-")
                value = calculator.substract(value, (T)inputValues[i].toDouble());
            else if(inputValues[i - 1] == "*")
                value = calculator.multiply(value, (T)inputValues[i].toDouble());
            else if(inputValues[i - 1] == "/")
                value = calculator.divide(value, (T)inputValues[i].toDouble());
        }

        return value;

        //! Вот это удалить!
        /*for(QString enterSymbol : *enterValues)
        {
            if(enterSymbol == "+")
            {
                value = calculator.add(value, (T)stringValue_.toDouble());
                stringValue_ = "";
            }
            else if(enterSymbol == "-")
            {
                value = calculator.substract(value, (T)stringValue_.toDouble());
                qDebug() << "TEST: " << value;
                qDebug() << "stringValue_.toDouble(): " << stringValue_.toDouble();
                qDebug() << "(T)stringValue_.toDouble(): " << (T)stringValue_.toDouble();
                stringValue_ = "";
            }
            else if(enterSymbol == "*")
            {
                value = calculator.multiply(value, (T)stringValue_.toDouble());
                stringValue_ = "";
            }
            else if(enterSymbol == "/")
            {
                value = calculator.divide(value, (T)stringValue_.toDouble());
                stringValue_ = "";
            }
            else
                stringValue_.append(enterSymbol);
        }

        stringValue_ = "";
        return value;*/
    }

};

#endif // CALCULATECONTROLLER_H
