#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        list1.append(rand() % 50);
        list2.append(rand() % 50);
    }

    for (int i = 0; i < 10; i++) {
        linkedList.append(rand() % 100);
    }

    updateListsDisplay();
    updateLinkedDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    int value = ui->lineEdit->text().toInt(&ok);

    if (!ok) {
        ui->textEditLists->append("\nОшибка: введите число!");
        return;
    }

    if (ui->checkBox->isChecked())
        list1.append(value);
    if (ui->checkBox_2->isChecked())
        list2.append(value);

    updateListsDisplay();

    ui->lineEdit->clear();
}

void MainWindow::on_pushButtonSort_clicked()
{
    sort(linkedList.begin(), linkedList.end());

    updateLinkedDisplay();
}

void MainWindow::updateListsDisplay()
{
    ui->textEditLists->clear();

    ui->textEditLists->append("Список 1:");
    for (const auto &x : list1)
        ui->textEditLists->append(QString::number(x));

    ui->textEditLists->append("\nСписок 2:");
    for (const auto &x : list2)
        ui->textEditLists->append(QString::number(x));
}

void MainWindow::updateLinkedDisplay()
{
    ui->textEditLinked->clear();

    ui->textEditLinked->append("Связный список:");
    for (const auto &x : linkedList)
        ui->textEditLinked->append(QString::number(x));
}
