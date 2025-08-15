/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *resultLabel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushSeven;
    QPushButton *pushMul;
    QPushButton *pushAC;
    QPushButton *pushOne;
    QPushButton *pushExp;
    QPushButton *pushEqual;
    QPushButton *pushZero;
    QPushButton *pushFive;
    QPushButton *pushDivide;
    QPushButton *pushAdd;
    QPushButton *pushMinus;
    QPushButton *pushTwo;
    QPushButton *pushFact;
    QPushButton *pushNine;
    QPushButton *pushSix;
    QPushButton *pushFour;
    QPushButton *pushThree;
    QPushButton *pushPeriod;
    QPushButton *pushDEL;
    QPushButton *pushButton;
    QPushButton *pushEight;
    QPushButton *pushPi;
    QPushButton *pushAns;
    QPushButton *pushSqrt;
    QPushButton *pushTan;
    QPushButton *pushCos;
    QPushButton *pushSin;
    QPushButton *pushAtan;
    QPushButton *pushAcos;
    QPushButton *pushAsin;
    QRadioButton *setGrad;
    QRadioButton *setRad;
    QRadioButton *setDeg;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(906, 560);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #292828;\n"
"	color: #ececec;\n"
"}\n"
"QPushButton {\n"
"    background-color: #525251;\n"
"	color: #ececec;\n"
"    border-radius: 12px;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton#pushAC {\n"
"    background-color: #ff9502;\n"
"}\n"
"QPushButton#pushDEL {\n"
"    background-color: #ff9502;\n"
"}\n"
"QPushButton#pushDivide {\n"
"    background-color: #ff9502;\n"
"}\n"
"QPushButton#pushMinus {\n"
"    background-color: #ff9502;\n"
"}\n"
"QPushButton#pushEqual {\n"
"    background-color: #ff9502;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #dee2e6;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #ced4da;\n"
"}\n"
"#mathFunctions QPushButton {\n"
"	background-color: #424241;\n"
"}\n"
"QLineEdit {\n"
"    background-color: #292828;\n"
"    border: 4px solid #3c3c3b;\n"
"    border-radius: 8px;\n"
"    padding: 4px;\n"
"}"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionExit->setIcon(icon);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        actionCut->setIcon(icon1);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        actionCopy->setIcon(icon2);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        actionPaste->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        actionAbout->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setFont(font);
        resultLabel->setTextFormat(Qt::TextFormat::AutoText);
        resultLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        resultLabel->setWordWrap(false);
        resultLabel->setTextInteractionFlags(Qt::TextInteractionFlag::TextSelectableByMouse);

        gridLayout->addWidget(resultLabel, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(10, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        pushSeven = new QPushButton(centralwidget);
        pushSeven->setObjectName("pushSeven");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushSeven->sizePolicy().hasHeightForWidth());
        pushSeven->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushSeven, 3, 3, 1, 1);

        pushMul = new QPushButton(centralwidget);
        pushMul->setObjectName("pushMul");
        sizePolicy1.setHeightForWidth(pushMul->sizePolicy().hasHeightForWidth());
        pushMul->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushMul, 4, 6, 1, 1);

        pushAC = new QPushButton(centralwidget);
        pushAC->setObjectName("pushAC");
        sizePolicy1.setHeightForWidth(pushAC->sizePolicy().hasHeightForWidth());
        pushAC->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushAC, 0, 7, 1, 1);

        pushOne = new QPushButton(centralwidget);
        pushOne->setObjectName("pushOne");
        sizePolicy1.setHeightForWidth(pushOne->sizePolicy().hasHeightForWidth());
        pushOne->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushOne, 5, 3, 1, 1);

        pushExp = new QPushButton(centralwidget);
        pushExp->setObjectName("pushExp");
        sizePolicy1.setHeightForWidth(pushExp->sizePolicy().hasHeightForWidth());
        pushExp->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushExp, 3, 1, 1, 1);

        pushEqual = new QPushButton(centralwidget);
        pushEqual->setObjectName("pushEqual");
        sizePolicy1.setHeightForWidth(pushEqual->sizePolicy().hasHeightForWidth());
        pushEqual->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushEqual, 6, 7, 1, 1);

        pushZero = new QPushButton(centralwidget);
        pushZero->setObjectName("pushZero");
        sizePolicy1.setHeightForWidth(pushZero->sizePolicy().hasHeightForWidth());
        pushZero->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushZero, 6, 4, 1, 1);

        pushFive = new QPushButton(centralwidget);
        pushFive->setObjectName("pushFive");
        sizePolicy1.setHeightForWidth(pushFive->sizePolicy().hasHeightForWidth());
        pushFive->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushFive, 4, 4, 1, 1);

        pushDivide = new QPushButton(centralwidget);
        pushDivide->setObjectName("pushDivide");
        sizePolicy1.setHeightForWidth(pushDivide->sizePolicy().hasHeightForWidth());
        pushDivide->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushDivide, 4, 7, 1, 1);

        pushAdd = new QPushButton(centralwidget);
        pushAdd->setObjectName("pushAdd");
        sizePolicy1.setHeightForWidth(pushAdd->sizePolicy().hasHeightForWidth());
        pushAdd->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushAdd, 5, 6, 1, 1);

        pushMinus = new QPushButton(centralwidget);
        pushMinus->setObjectName("pushMinus");
        sizePolicy1.setHeightForWidth(pushMinus->sizePolicy().hasHeightForWidth());
        pushMinus->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushMinus, 5, 7, 1, 1);

        pushTwo = new QPushButton(centralwidget);
        pushTwo->setObjectName("pushTwo");
        sizePolicy1.setHeightForWidth(pushTwo->sizePolicy().hasHeightForWidth());
        pushTwo->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushTwo, 5, 4, 1, 1);

        pushFact = new QPushButton(centralwidget);
        pushFact->setObjectName("pushFact");
        sizePolicy1.setHeightForWidth(pushFact->sizePolicy().hasHeightForWidth());
        pushFact->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushFact, 3, 2, 1, 1);

        pushNine = new QPushButton(centralwidget);
        pushNine->setObjectName("pushNine");
        sizePolicy1.setHeightForWidth(pushNine->sizePolicy().hasHeightForWidth());
        pushNine->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushNine, 3, 5, 1, 1);

        pushSix = new QPushButton(centralwidget);
        pushSix->setObjectName("pushSix");
        sizePolicy1.setHeightForWidth(pushSix->sizePolicy().hasHeightForWidth());
        pushSix->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushSix, 4, 5, 1, 1);

        pushFour = new QPushButton(centralwidget);
        pushFour->setObjectName("pushFour");
        sizePolicy1.setHeightForWidth(pushFour->sizePolicy().hasHeightForWidth());
        pushFour->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushFour, 4, 3, 1, 1);

        pushThree = new QPushButton(centralwidget);
        pushThree->setObjectName("pushThree");
        sizePolicy1.setHeightForWidth(pushThree->sizePolicy().hasHeightForWidth());
        pushThree->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushThree, 5, 5, 1, 1);

        pushPeriod = new QPushButton(centralwidget);
        pushPeriod->setObjectName("pushPeriod");
        sizePolicy1.setHeightForWidth(pushPeriod->sizePolicy().hasHeightForWidth());
        pushPeriod->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushPeriod, 6, 3, 1, 1);

        pushDEL = new QPushButton(centralwidget);
        pushDEL->setObjectName("pushDEL");
        sizePolicy1.setHeightForWidth(pushDEL->sizePolicy().hasHeightForWidth());
        pushDEL->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushDEL, 3, 7, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 6, 6, 1, 1);

        pushEight = new QPushButton(centralwidget);
        pushEight->setObjectName("pushEight");
        sizePolicy1.setHeightForWidth(pushEight->sizePolicy().hasHeightForWidth());
        pushEight->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushEight, 3, 4, 1, 1);

        pushPi = new QPushButton(centralwidget);
        pushPi->setObjectName("pushPi");
        sizePolicy1.setHeightForWidth(pushPi->sizePolicy().hasHeightForWidth());
        pushPi->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushPi, 6, 5, 1, 1);

        pushAns = new QPushButton(centralwidget);
        pushAns->setObjectName("pushAns");
        sizePolicy1.setHeightForWidth(pushAns->sizePolicy().hasHeightForWidth());
        pushAns->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushAns, 3, 6, 1, 1);

        pushSqrt = new QPushButton(centralwidget);
        pushSqrt->setObjectName("pushSqrt");
        sizePolicy1.setHeightForWidth(pushSqrt->sizePolicy().hasHeightForWidth());
        pushSqrt->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushSqrt, 3, 0, 1, 1);

        pushTan = new QPushButton(centralwidget);
        pushTan->setObjectName("pushTan");
        sizePolicy1.setHeightForWidth(pushTan->sizePolicy().hasHeightForWidth());
        pushTan->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushTan, 4, 2, 1, 1);

        pushCos = new QPushButton(centralwidget);
        pushCos->setObjectName("pushCos");
        sizePolicy1.setHeightForWidth(pushCos->sizePolicy().hasHeightForWidth());
        pushCos->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushCos, 4, 1, 1, 1);

        pushSin = new QPushButton(centralwidget);
        pushSin->setObjectName("pushSin");
        sizePolicy1.setHeightForWidth(pushSin->sizePolicy().hasHeightForWidth());
        pushSin->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushSin, 4, 0, 1, 1);

        pushAtan = new QPushButton(centralwidget);
        pushAtan->setObjectName("pushAtan");
        sizePolicy1.setHeightForWidth(pushAtan->sizePolicy().hasHeightForWidth());
        pushAtan->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushAtan, 5, 2, 1, 1);

        pushAcos = new QPushButton(centralwidget);
        pushAcos->setObjectName("pushAcos");
        sizePolicy1.setHeightForWidth(pushAcos->sizePolicy().hasHeightForWidth());
        pushAcos->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushAcos, 5, 1, 1, 1);

        pushAsin = new QPushButton(centralwidget);
        pushAsin->setObjectName("pushAsin");
        sizePolicy1.setHeightForWidth(pushAsin->sizePolicy().hasHeightForWidth());
        pushAsin->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushAsin, 5, 0, 1, 1);

        setGrad = new QRadioButton(centralwidget);
        setGrad->setObjectName("setGrad");
        sizePolicy1.setHeightForWidth(setGrad->sizePolicy().hasHeightForWidth());
        setGrad->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(setGrad, 6, 2, 1, 1);

        setRad = new QRadioButton(centralwidget);
        setRad->setObjectName("setRad");
        sizePolicy1.setHeightForWidth(setRad->sizePolicy().hasHeightForWidth());
        setRad->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(setRad, 6, 1, 1, 1);

        setDeg = new QRadioButton(centralwidget);
        setDeg->setObjectName("setDeg");
        sizePolicy1.setHeightForWidth(setDeg->sizePolicy().hasHeightForWidth());
        setDeg->setSizePolicy(sizePolicy1);
        setDeg->setChecked(true);

        gridLayout_2->addWidget(setDeg, 6, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 906, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        lineEdit->setText(QString());
        resultLabel->setText(QString());
        pushSeven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushMul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushAC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushOne->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushExp->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushZero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushFive->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushDivide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushAdd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushTwo->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushFact->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        pushNine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushSix->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushFour->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushThree->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushPeriod->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushDEL->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        pushEight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushPi->setText(QCoreApplication::translate("MainWindow", "\317\200", nullptr));
        pushAns->setText(QCoreApplication::translate("MainWindow", "Ans", nullptr));
        pushSqrt->setText(QCoreApplication::translate("MainWindow", "sqrt()", nullptr));
        pushTan->setText(QCoreApplication::translate("MainWindow", "tan()", nullptr));
        pushCos->setText(QCoreApplication::translate("MainWindow", "cos()", nullptr));
        pushSin->setText(QCoreApplication::translate("MainWindow", "sin()", nullptr));
        pushAtan->setText(QCoreApplication::translate("MainWindow", "arctan()", nullptr));
        pushAcos->setText(QCoreApplication::translate("MainWindow", "arccos()", nullptr));
        pushAsin->setText(QCoreApplication::translate("MainWindow", "arcsin()", nullptr));
        setGrad->setText(QCoreApplication::translate("MainWindow", "Gra", nullptr));
        setRad->setText(QCoreApplication::translate("MainWindow", "Rad", nullptr));
        setDeg->setText(QCoreApplication::translate("MainWindow", "Deg", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
