#ifndef DOCUMENTWINDOW_H
#define DOCUMENTWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class DocumentWindow;
}
QT_END_NAMESPACE

class DocumentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DocumentWindow(QWidget *parent = nullptr);
    ~DocumentWindow();

private slots:
    void createDocument();
    void openDocument();
    void saveDocument();
    void saveDocumentAs();
    void printDocument();
    void closeDocument();

private:
    Ui::DocumentWindow *ui;
    QString currentFileName;
};

#endif // DOCUMENTWINDOW_H
