#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "scatterhierarchy.h"


template<typename T>
struct SingleValue
{
    SingleValue(T X1): x1(X1) {}

    T x1;
};

template <typename T> //Simple addition
T operator + (const SingleValue<T> &firstArg, const SingleValue<T> &secondArg)
{
    return (firstArg.x1 + secondArg.x1);
}
template <typename T>
T operator - (const SingleValue<T> &firstArg, SingleValue<T> &secondArg)
{
    return (firstArg.x1 - secondArg.x1);
}
template <typename T>
T operator * (const SingleValue<T> &firstArg, SingleValue<T> &secondArg)
{
    return (firstArg.x1 * secondArg.x1);
}
template <typename T>
T operator / (const SingleValue<T> &firstArg, SingleValue<T> &secondArg)
{
    return (secondArg.x1 == 0 ? secondArg.x1 : (firstArg.x1 / secondArg.x1));
}


class Calculator
{
public:
    template <typename T> T add(T argLeft, T argRight)
    {
        SingleValue<T> argLeft_(argLeft), argRight_(argRight);

        return argLeft_ + argRight_;
    }
    template <typename T> T substract(T argLeft, T argRight)
    {
        SingleValue<T> argLeft_(argLeft), argRight_(argRight);

        return argLeft_ - argRight_;
    }
    template <typename T> T multiply(T argLeft, T argRight)
    {
        SingleValue<T> argLeft_(argLeft), argRight_(argRight);

        return argLeft_ * argRight_;
    }
    template <typename T> T divide(T argLeft, T argRight)
    {
        SingleValue<T> argLeft_(argLeft), argRight_(argRight);

        return argLeft_ / argRight_;
    }
};



#endif // CALCULATOR_H
