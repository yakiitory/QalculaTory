#include "aboutdialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("About");
    setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *title = new QLabel("<h2>QalculaTory v1.0</h2>");
    title->setAlignment(Qt::AlignHCenter);
    layout->addWidget(title);

    QLabel *info = new QLabel("(c) 2025 yakiitory<br>Project for CS50<br>Released under the MIT License");
    info->setTextFormat(Qt::RichText);
    info->setAlignment(Qt::AlignHCenter);
    layout->addWidget(info);

    QLabel *link = new QLabel("<a href='https://www.github.com/yakiitory'>Visit my Github!</a>");
    link->setTextFormat(Qt::RichText);
    link->setTextInteractionFlags(Qt::TextBrowserInteraction);
    link->setOpenExternalLinks(true);
    link->setAlignment(Qt::AlignHCenter);
    layout->addWidget(link);

    QPushButton *okButton = new QPushButton("OK");
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(okButton);
}
