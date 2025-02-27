#include "level.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QGraphicsScene>
#include "peca.h"

Level::Level(QObject *parent) : QGraphicsItem(nullptr)
{
    Q_UNUSED(parent);
    height = 6;
    width = 10;
    setupBoard();
}

Level::~Level()
{
    qDeleteAll(grid);
}

void Level::setupBoard()
{
    qDeleteAll(grid);
    grid.clear();

    // Cria a grade de 6x10 (60 posições)
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            QGraphicsRectItem *square = new QGraphicsRectItem(col * 50, row * 50, 50, 50, this);
            square->setPen(QPen(Qt::black));
            square->setBrush(QBrush(Qt::lightGray));
            grid.append(square);
        }
    }
}

QRectF Level::boundingRect() const
{
    return QRectF(0, 0, width * 50, height * 50);
}

void Level::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for (QGraphicsRectItem *square : grid) {
        square->setPos(square->x(), square->y());
        square->paint(painter, option, widget);
    }
}

bool Level::is_completed() const
{
    if (!scene()) {
        qDebug() << "Erro: Nenhuma cena associada ao Level.";
        return false;
    }

    bool occupied[6][10] = {{false}}; // Matriz 6x10 para rastrear posições ocupadas

    QList<QGraphicsItem *> items = scene()->items();
    for (QGraphicsItem *item : items) {
        if (Peca *peca = dynamic_cast<Peca *>(item)) {
            QPointF pecaPos = peca->pos(); // Posição absoluta da peça na cena
            QPointF levelPos = this->pos(); // Posição do Level na cena (350, 150)

            // Ajusta a posição da peça para coordenadas relativas ao Level
            int relativeX = static_cast<int>((pecaPos.x() - levelPos.x()) / 50);
            int relativeY = static_cast<int>((pecaPos.y() - levelPos.y()) / 50);

            qDebug() << "Peça detectada na posição (scene):" << pecaPos;
            qDebug() << "Posição do Level:" << levelPos;
            qDebug() << "Posição relativa no grid (relativeX, relativeY):" << relativeX << "," << relativeY;

            const std::vector<std::vector<bool>>& formato = peca->getMapaBlocos();
            for (size_t i = 0; i < formato.size(); ++i) {
                for (size_t j = 0; j < formato[i].size(); ++j) {
                    if (formato[i][j]) {
                        int gridX = relativeX + j;
                        int gridY = relativeY + i;
                        if (gridX >= 0 && gridX < width && gridY >= 0 && gridY < height) {
                            occupied[gridY][gridX] = true;
                            qDebug() << "Posição ocupada no grid: (" << gridX << "," << gridY << ")";
                        } else {
                            qDebug() << "Posição fora do tabuleiro: (" << gridX << "," << gridY << ")";
                        }
                    }
                }
            }
        }
    }

    bool isFull = true;
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (!occupied[row][col]) {
                isFull = false;
                qDebug() << "Posição vazia no tabuleiro: (" << col << "," << row << ")";
            }
        }
    }

    if (isFull) {
        qDebug() << "O tabuleiro está completamente preenchido!";
    } else {
        qDebug() << "O tabuleiro NÃO está completamente preenchido.";
    }

    return isFull;
}
