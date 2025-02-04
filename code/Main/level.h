#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMouseEvent> // Para capturar eventos do mouse

class Level : public QWidget {
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();

private:
    int width = 10;  // Largura do tabuleiro
    int height = 6;  // Altura do tabuleiro
    bool is_completed = false;
    uint total_size = width * height;
    uint blank_spaces = width * height;

    QGraphicsScene *scene;
    QGraphicsView *view;
    QVector<QVector<QGraphicsRectItem*>> grid;

    QVBoxLayout *mainLayout;
    QHBoxLayout *hBottomLayout;

    void setupBoard();
};

#endif // LEVEL_H
