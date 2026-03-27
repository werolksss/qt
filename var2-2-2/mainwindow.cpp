#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ctime>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(0));

    // создаём матрицу 4x5
    for (int i = 0; i < 4; i++) {
        QVector<int> row;
        for (int j = 0; j < 5; j++) {
            row.append(rand() % 100);
        }
        matrix.append(row);
    }

    // вывод матрицы
    ui->textEdit->clear();
    for (int i = 0; i < matrix.size(); i++) {
        QString str = "";
        for (int j = 0; j < matrix[i].size(); j++) {
            str += QString::number(matrix[i][j]) + " ";
        }
        ui->textEdit->append(str);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//КНОПКА
void MainWindow::on_pushButton_clicked()
{
    int sum = 0;

    int choice = ui->comboBox->currentIndex();

    for (int j = 0; j < matrix[0].size(); j++) {

        if ((choice == 0 && j % 2 == 0) ||   // чётные столбцы
            (choice == 1 && j % 2 != 0)) {  // нечётные

            for (int i = 0; i < matrix.size(); i++) {
                sum += matrix[i][j];
            }
        }
    }

    ui->label->setText("Сумма = " + QString::number(sum));
}
