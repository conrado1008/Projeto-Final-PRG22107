#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton * start;
    QPushButton * select_level;
    QPushButton * exit;
    QVBoxLayout * mainLayout;

};


#endif // MAINWINDOW_H
