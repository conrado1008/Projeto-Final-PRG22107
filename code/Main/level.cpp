#include "level.h"
#include <QGraphicsRectItem>
#include <QVBoxLayout>

Level::Level(QWidget *parent)
    : QWidget(parent), scene(new QGraphicsScene(this)), view(new QGraphicsView(scene, this)) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

    view->setFixedSize(620, 380); // Ajusta o tamanho da visão
    layout->addWidget(view);

    setupBoard();
}

void Level::setupBoard() {
    // Limpa a cena e o grid existente
    scene->clear();
    grid.clear();

    // Cria os quadradinhos do tabuleiro
    for (int row = 0; row < height; ++row) {
        QVector<QGraphicsRectItem*> rowItems;
        for (int col = 0; col < width; ++col) {
            QGraphicsRectItem *square = scene->addRect(col * 60, row * 60, 60, 60, QPen(Qt::black), QBrush(Qt::lightGray));
            rowItems.append(square);
        }
        grid.append(rowItems);
    }
}

void Level::restart() {
    // Reseta as cores do tabuleiro para o estado inicial
    for (auto& row : grid) {
        for (auto& square : row) {
            square->setBrush(Qt::lightGray);
        }
    }
}
