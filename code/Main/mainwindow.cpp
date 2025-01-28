#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    check = new QCheckBox("check");
    QObject::connect(check, SIGNAL(stateChanged(int)), this, SLOT(togleCheckbox()));

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(check);

}

MainWindow::~MainWindow() {}

