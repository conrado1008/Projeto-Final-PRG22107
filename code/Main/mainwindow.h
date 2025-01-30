#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include "peca.h"
#include "tipodepecas.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();  // ⬅️ Apenas declaração, sem implementação!

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
