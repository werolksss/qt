#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(0));

    // заполняем списки случайными числами
    for (int i = 0; i < 5; i++) {
        list1.append(rand() % 50);
        list2.append(rand() % 50);
    }

    // вывод в textEdit
    ui->textEdit->append("Список 1:");
    for (auto x : list1)
        ui->textEdit->append(QString::number(x));

    ui->textEdit->append("\nСписок 2:");
    for (auto x : list2)
        ui->textEdit->append(QString::number(x));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// обработка кнопки
void MainWindow::on_pushButton_clicked()
{
    int value = ui->lineEdit->text().toInt();

    if (ui->checkBox->isChecked()) {
        list1.append(value);
    }

    if (ui->checkBox_2->isChecked()) {
        list2.append(value);
    }

    // обновляем вывод
    ui->textEdit->clear();

    ui->textEdit->append("Список 1:");
    for (auto x : list1)
        ui->textEdit->append(QString::number(x));

    ui->textEdit->append("\nСписок 2:");
    for (auto x : list2)
        ui->textEdit->append(QString::number(x));
}
