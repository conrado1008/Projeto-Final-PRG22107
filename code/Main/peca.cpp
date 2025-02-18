#include "peca.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>  // Required for mouse events
#include <QDebug>
#include <QGraphicsScene>

#define gridsize 50

Peca::Peca(const std::vector<std::vector<bool>>& formato, const QColor& cor, QGraphicsItem* parent)
    : QGraphicsItem(parent), mapaBlocos(formato), corPeca(cor) {}

QRectF Peca::boundingRect() const {
    return QRectF(0, 0, mapaBlocos[0].size() * 50, mapaBlocos.size() * 50);
}

void Peca::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->setBrush(corPeca);
    this->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    for (size_t i = 0; i < mapaBlocos.size(); ++i) {
        for (size_t j = 0; j < mapaBlocos[i].size(); ++j) {
            if (mapaBlocos[i][j]) {
                painter->drawRect(j * 50, i * 50, 50, 50);
            }
        }
    }
}

void Peca::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    // Call the base class method for default handling (optional)
    QGraphicsItem::mouseReleaseEvent(event);

    if (scene()) {
        // Get the position of the mouse event in scene coordinates
        QPointF scenePos = mapToScene(event->pos());

        // Snap to the grid
        QPointF firstPixelPosition = scene()->sceneRect().topLeft();

        int x = static_cast<int>(scenePos.x() / gridsize) * gridsize - firstPixelPosition.x();
        int y = static_cast<int>(scenePos.y() / gridsize) * gridsize - firstPixelPosition.y();

        // Update the item position to the snapped position if there's an item being dragged
        if (QGraphicsItem* item = scene()->itemAt(scenePos, QTransform())) {
            item->setPos(x, y);
        }
    }


    // Check the event and handle the click
    qDebug() << "Peca clicked at position:" << event->scenePos();

    // You can do other actions here, such as changing the color or moving the item
    // For example, change color on click
}
