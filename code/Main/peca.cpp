#include "peca.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
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

void Peca::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    // Capture the position of the Peca and the mouse when the mouse is pressed
    QPointF pecaPos = this->pos();  // Get the current position of Peca in scene coordinates
    QPointF mousePos = event->scenePos();  // Get the mouse position in scene coordinates

    this->initial_pos = pecaPos;
    this->mouse_pos = mousePos;

    // Print the positions for debugging
    qDebug() << "Peca position (scene):" << this->initial_pos;

    qDebug() << "Mouse position (scene):" << this->mouse_pos;

    // You can store these values if you need them for further use
    // For example, you could store them in member variables for later reference

    // Optional: Call the base class method for default handling (if necessary)
    QGraphicsItem::mousePressEvent(event);
}

void Peca::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    // Call the base class method for default handling (optional)
    QGraphicsItem::mouseReleaseEvent(event);

    if (scene()) {
        // Get the position of the mouse event in scene coordinates
        QPointF scenePos = mapToScene(event->pos());

        // Snap to the grid
        QPointF firstPixelPosition = mapToScene(QPointF(0, 0));


        QPointF delta_pos = scenePos - mouse_pos;

        //Tolerance for positioning
        if (static_cast<int>((delta_pos.x()) < 15) & (static_cast<int>(delta_pos.x()) > -15))
            delta_pos.setX(0);
        if (static_cast<int>((delta_pos.y()) < 15) & (static_cast<int>(delta_pos.y()) > -15))
            delta_pos.setY(0);


        int x = static_cast<int>((initial_pos.x() + delta_pos.x()) / gridsize) * gridsize;
        int y = static_cast<int>((initial_pos.y() + delta_pos.y()) / gridsize) * gridsize;

        // Update the item position to the snapped position if there's an item being dragged
        if (QGraphicsItem* item = scene()->itemAt(scenePos, QTransform())) {
            item->setPos(x, y);
        }
        qDebug() << "Delta:" << delta_pos;
    }

    // Check the event and handle the click
    qDebug() << "Peca clicked at position:" << event->scenePos();

    // You can do other actions here, such as changing the color or moving the item
    // For example, change color on click
}
