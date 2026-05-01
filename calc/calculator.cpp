#include "calculator.h"

Calculator::Calculator() {}

double Calculator::calculate(const QString& expr, bool &ok)
{
    QChar op;
    int pos = -1;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            op = expr[i];
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        ok = false;
        return 0;
    }

    QString left = expr.left(pos);
    QString right = expr.mid(pos + 1);

    double a = left.toDouble();
    double b = right.toDouble();

    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;

    if (op == '/') {
        if (b == 0) {
            ok = false;
            return 0;
        }
        return a / b;
    }

    ok = false;
    return 0;
}
