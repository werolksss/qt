#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

// ввод цифр
void MainWindow::on_pushButton_0_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "0"); }
void MainWindow::on_pushButton_1_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "1"); }
void MainWindow::on_pushButton_2_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "2"); }
void MainWindow::on_pushButton_3_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "3"); }
void MainWindow::on_pushButton_4_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "4"); }
void MainWindow::on_pushButton_5_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "5"); }
void MainWindow::on_pushButton_6_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "6"); }
void MainWindow::on_pushButton_7_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "7"); }
void MainWindow::on_pushButton_8_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "8"); }
void MainWindow::on_pushButton_9_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "9"); }

// точка
void MainWindow::on_pushButton_dot_clicked()
{
    if (!ui->lineEdit->text().contains("."))
        ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

// очистка
void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

// операции
void MainWindow::on_pushButton_plus_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "+"); }
void MainWindow::on_pushButton_minus_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "-"); }
void MainWindow::on_pushButton_mul_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "*"); }
void MainWindow::on_pushButton_div_clicked(){ ui->lineEdit->setText(ui->lineEdit->text() + "/"); }

// равно
void MainWindow::on_pushButton_equal_clicked()
{
    QString expr = ui->lineEdit->text();

    bool ok = true;
    double result = calc.calculate(expr, ok);

    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Неверное выражение или деление на 0");
        return;
    }

    ui->lineEdit_2->setText(QString::number(result));
}