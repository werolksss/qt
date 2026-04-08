#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSet>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_process_clicked();
    void on_pushButton_example_clicked();
    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow *ui;

    QSet<QString> stringToSet(const QString &text);
    QString setToString(const QSet<QString> &set);
};

#endif
