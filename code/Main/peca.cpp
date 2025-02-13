#include "peca.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>  // Required for mouse events
#include <QDebug>

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


    // Check the event and handle the click
    qDebug() << "Peca clicked at position:" << event->scenePos();

    // You can do other actions here, such as changing the color or moving the item
    // For example, change color on click
}
