#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//1
void MainWindow::on_pushButton_1_clicked()
{
    int a = ui->lineEdit_1->text().toInt();
    int b = ui->lineEdit_2->text().toInt();
    int c = ui->lineEdit_3->text().toInt();

    int min = a;

    if (b < min) min = b;
    if (c < min) min = c;

    int result;

    if (min == a)
        result = b + c;
    else if (min == b)
        result = a + c;
    else
        result = a + b;

    ui->label_1->setText("Результат: " + QString::number(result));
}

//2
void MainWindow::on_pushButton_2_clicked()
{
    int A = ui->lineEdit_A->text().toInt();
    int B = ui->lineEdit_B->text().toInt();

    if (A != B) {
        int sum = A + B;
        A = sum;
        B = sum;
    } else {
        A = 0;
        B = 0;
    }

    ui->label_2->setText("A = " + QString::number(A) +
                         "  B = " + QString::number(B));
}
