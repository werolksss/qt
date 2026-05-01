#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>

class Calculator
{
public:
    Calculator();
    double calculate(const QString& expression, bool &ok);
};

#endif // CALCULATOR_H