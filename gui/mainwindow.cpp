#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../src/parser.h"
#include "../src/helpers.h"
#include "aboutdialog.h"

#include <QClipboard>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("QalculaTory");

    QClipboard* clipboard = QApplication::clipboard();

    // PushButton Implementations
    for (auto button : findChildren<QPushButton*>()) {
        QString name = button->objectName();
        if (name == "pushDEL" || name == "pushEqual" || name == "pushAC") {
            connect(button, &QPushButton::clicked, this, [this, button, name]() {
                implementButton(name); // specific implementation
            });
            continue;
        }
        connect(button, &QPushButton::clicked, this, [this, button]() {
            insertText(button->text()); // insert text inside of button to line edit
        });
    }

    // RadioButton Implementations
    for (auto radio : findChildren<QRadioButton*>()) {
        QString name = radio->objectName();
        connect(radio, &QRadioButton::toggled, this, [this, radio, name](bool checked) {
            if (checked) implementRadio(name); // handle specific radio
        });
    }


    // MenuBar Implementations
    for (auto action : findChildren<QAction*>()) {
        QString name = action->objectName();
        connect(action, &QAction::triggered, this, [this, name, clipboard]() {
            implementMenuAction(name, clipboard); // handle specific menu
        });
    }

    // Font rendering
    QFont font;
    font.setPointSize(32);
    ui->lineEdit->setFont(font);
    ui->lineEdit->setStyleSheet("font-size: 32pt;");
    ui->resultLabel->setFont(font);
    ui->resultLabel->setStyleSheet("font-size: 36pt;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertText(const QString &text)
{
    int pos = ui->lineEdit->cursorPosition();
    QString current = ui->lineEdit->text();
    current.insert(pos, text);
    ui->lineEdit->setText(current);
    ui->lineEdit->setCursorPosition(pos + text.length());
}

void MainWindow::implementMenuAction(QString name, QClipboard* clipboard)
{
    if (name == "actionExit")
    {
        QCoreApplication::quit();
    }
    else if (name == "actionCopy")
    {
        clipboard->setText(ui->resultLabel->text());
    }
    else if (name == "actionCut")
    {
        clipboard->setText(ui->resultLabel->text());
        ui->lineEdit->setText("");
        ui->resultLabel->setText("");
        set_ans(0.0f);
    }
    else if (name == "actionPaste")
    {
        ui->lineEdit->setText(clipboard->text());
    }
    else if (name == "actionAbout")
    {
        AboutDialog dlg(this);
        dlg.exec();
    }
}

void MainWindow::implementButton(QString name)
{
    if (name == "pushDEL")
    {
        QString current = ui->lineEdit->text();
        current.chop(1);
        ui->lineEdit->setText(current);
    }
    else if (name == "pushEqual")
    {
        QString text = ui->lineEdit->text();           // turn into QString
        std::string expr = text.toStdString();         // turn into String
        const char* c_expr = expr.c_str();             // turn into char*

        const char* result = parser(c_expr);
        ui->resultLabel->setText(QString::fromUtf8(result));
    }
    else if (name == "pushAC")
    {
        ui->lineEdit->setText("");
    }
}

void MainWindow::implementRadio(QString name)
{
    if (name == "setDeg")
    {
        set_mode(MODE_DEG);
    }
    else if (name == "setRad")
    {
        set_mode(MODE_RAD);
    }
    else if (name == "setGrad")
    {
        set_mode(MODE_GRAD);
    }
}
