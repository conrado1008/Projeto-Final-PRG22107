#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include "game_screen.h"
#include "peca.h"
#include "tipodepecas.h"
#include <QtWidgets>


class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();  // ⬅️ Apenas declaração, sem implementação!

public slots:
    void start_game();
    void level_selection();

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPushButton * start;
    QPushButton * select_level;
    QPushButton * exit;
    QVBoxLayout * mainLayout;
};

#endif // MAINWINDOW_H
