#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>

class Level : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Level(QObject *parent = nullptr);
    ~Level();

    void setupBoard();

private:
    int width = 10;   // Largura do tabuleiro
    int height = 6;   // Altura do tabuleiro
    QVector<QVector<QGraphicsRectItem*>> grid; // Matriz de quadrados
};

#endif // LEVEL_H
