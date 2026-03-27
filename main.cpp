#include <QCoreApplication> //запуск
#include <QVector> //дин массив
#include <QTextStream> //ввод
#include <QDebug> // вывож
#include <clocale>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "");
    QTextStream in(stdin);

    QVector<int> vec;

    qDebug() << "Введите количество элементов:";
    int n;
    in >> n;

    qDebug() << "Введите элементы массива:";

    for (int i = 0; i < n; i++) {
        int num;
        in >> num;
        vec.append(num);
    }

    qDebug() << "Результат:";

    //сначала четные
    for (int i = 0; i < vec.size(); i += 2) {
        qDebug() << vec[i];
    }

    //потом нечетные
    for (int i = 1; i < vec.size(); i += 2) {
        qDebug() << vec[i];
    }

    return a.exec();
}
