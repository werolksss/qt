#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringList>
#include <QSet>
#include <QMessageBox>
#include <QRandomGenerator>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEdit_inAll->setReadOnly(true);
    ui->textEdit_inAny->setReadOnly(true);
    ui->textEdit_notInAny->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//превращение строк в множествоо
QSet<QString> MainWindow::stringToSet(const QString &text)
{
    QSet<QString> result;

    QStringList items = text.split(",", Qt::SkipEmptyParts);

    for (QString item : items) {
        item = item.trimmed();
        if (!item.isEmpty())
            result.insert(item);
    }

    return result;
}

QString MainWindow::setToString(const QSet<QString> &set)
{
    QStringList list = set.values();
    list.sort();

    if(list.isEmpty())
        return "Пусто";

    return list.join("\n");
}

//кн пример
void MainWindow::on_pushButton_example_clicked()
{
    QStringList all = {
        "Хлеб", "Молоко", "Сыр", "Мясо", "Яблоки",
        "Сахар", "Чай", "Кофе", "Рис", "Макароны"
    };

    std::shuffle(all.begin(), all.end(), *QRandomGenerator::global());

    int count = QRandomGenerator::global()->bounded(5, 10);

    QStringList allProducts;
    for(int i = 0; i < count; i++) {
        allProducts.append(all[i]);
    }

    ui->lineEdit_allProducts->setText(allProducts.join(", "));

    QStringList shop1, shop2, shop3;

    for(const QString &item : allProducts) {

        if(QRandomGenerator::global()->bounded(2))
            shop1.append(item);

        if(QRandomGenerator::global()->bounded(2))
            shop2.append(item);

        if(QRandomGenerator::global()->bounded(2))
            shop3.append(item);
    }

    ui->lineEdit_shop1->setText(shop1.join(", "));
    ui->lineEdit_shop2->setText(shop2.join(", "));
    ui->lineEdit_shop3->setText(shop3.join(", "));
}

// кн выполнить
void MainWindow::on_pushButton_process_clicked()
{
    QSet<QString> allProducts = stringToSet(ui->lineEdit_allProducts->text());
    QSet<QString> shop1 = stringToSet(ui->lineEdit_shop1->text());
    QSet<QString> shop2 = stringToSet(ui->lineEdit_shop2->text());
    QSet<QString> shop3 = stringToSet(ui->lineEdit_shop3->text());

    if(allProducts.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите товары");
        return;
    }

    // во всех
    QSet<QString> inAll = shop1;
    inAll.intersect(shop2);
    inAll.intersect(shop3);

    //в одном
    QSet<QString> inAny = shop1;
    inAny.unite(shop2);
    inAny.unite(shop3);

    // нигде
    QSet<QString> notInAny = allProducts;
    notInAny.subtract(inAny);

    ui->textEdit_inAll->setText(setToString(inAll));
    ui->textEdit_inAny->setText(setToString(inAny));
    ui->textEdit_notInAny->setText(setToString(notInAny));
}

//кн очистить
void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit_allProducts->clear();
    ui->lineEdit_shop1->clear();
    ui->lineEdit_shop2->clear();
    ui->lineEdit_shop3->clear();

    ui->textEdit_inAll->clear();
    ui->textEdit_inAny->clear();
    ui->textEdit_notInAny->clear();
}
