#include "level.h"
#include <QPen>
#include <QBrush>

Level::Level(QObject *parent) : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 600, 360); // Define o tamanho da cena
    setupBoard();
}

Level::~Level() {}

void Level::setupBoard()
{
    // Limpa a cena e a grade existente
    clear();
    grid.clear();

    // Cria os quadradinhos do tabuleiro
    for (int row = 0; row < height; ++row) {
        QVector<QGraphicsRectItem*> rowItems;
        for (int col = 0; col < width; ++col) {
            QGraphicsRectItem *square = addRect(col * 60, row * 60, 60, 60, QPen(Qt::black), QBrush(Qt::lightGray));
            rowItems.append(square);
        }
        grid.append(rowItems);
    }
}
