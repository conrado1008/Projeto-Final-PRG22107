#include "level.h"
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QApplication>

Level::Level(QWidget *parent)
    : QWidget(parent)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    // Layout principal
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(view);

    mainLayout->addLayout(hBottomLayout);

    setLayout(mainLayout);
    setWindowTitle("Tabuleiro 10x6");

    view->setFixedSize(620, 380);
    setupBoard();
}

Level::~Level() {}

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
