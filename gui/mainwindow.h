#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // helper for inserting text into the QLineEdit
    void insertText(const QString &text);

    // helper for implementing specific button functions
    void implementButton(QString name);
    void implementRadio(QString name);
    void implementMenuAction(QString name, QClipboard* clipboard);
};

#endif // MAINWINDOW_H
