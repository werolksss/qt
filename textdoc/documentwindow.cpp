#include "documentwindow.h"
#include "ui_documentwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

DocumentWindow::DocumentWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DocumentWindow)
{
    ui->setupUi(this);

    connect(ui->btnCreate, &QPushButton::clicked,
            this, &DocumentWindow::createDocument);

    connect(ui->btnOpen, &QPushButton::clicked,
            this, &DocumentWindow::openDocument);

    connect(ui->btnSave, &QPushButton::clicked,
            this, &DocumentWindow::saveDocument);

    connect(ui->btnSaveAs, &QPushButton::clicked,
            this, &DocumentWindow::saveDocumentAs);

    connect(ui->btnPrint, &QPushButton::clicked,
            this, &DocumentWindow::printDocument);

    connect(ui->btnClose, &QPushButton::clicked,
            this, &DocumentWindow::closeDocument);
}

DocumentWindow::~DocumentWindow()
{
    delete ui;
}

void DocumentWindow::createDocument()
{
    ui->textEdit->clear();
    currentFileName = "";
}

void DocumentWindow::openDocument()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", "", "Text Files (*.txt)");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    ui->textEdit->append(in.readAll());

    currentFileName = fileName;
    file.close();
}

void DocumentWindow::saveDocument()
{
    if (currentFileName.isEmpty()) {
        saveDocumentAs();
        return;
    }

    QFile file(currentFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();

    file.close();
}

void DocumentWindow::saveDocumentAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить как", "", "Text Files (*.txt)");

    if (fileName.isEmpty())
        return;

    currentFileName = fileName;
    saveDocument();
}

void DocumentWindow::printDocument()
{
    QMessageBox::information(this, "Печать", "Начать печать!");
}

void DocumentWindow::closeDocument()
{
    this->close();
}
