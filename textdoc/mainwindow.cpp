#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "documentwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnCreateEditor, &QPushButton::clicked,
            this, &MainWindow::openEditor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openEditor()
{
    DocumentWindow *editor = new DocumentWindow(this);
    editor->show();
}
