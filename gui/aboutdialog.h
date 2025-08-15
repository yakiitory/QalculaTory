#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

class QLabel;
class QVBoxLayout;

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    AboutDialog(QWidget *parent = nullptr);
};

#endif
