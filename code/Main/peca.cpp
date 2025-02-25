#include "peca.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "level.h"

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
    QPointF pecaPos = this->pos();
    QPointF mousePos = event->scenePos();

    this->initial_pos = pecaPos;
    this->mouse_pos = mousePos;

    qDebug() << "Peca position (scene):" << this->initial_pos;
    qDebug() << "Mouse position (scene):" << this->mouse_pos;

    QGraphicsItem::mousePressEvent(event);
}

void Peca::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsItem::mouseReleaseEvent(event);

    if (scene()) {
        QPointF scenePos = mapToScene(event->pos());
        QPointF delta_pos = scenePos - mouse_pos;

        if (static_cast<int>((delta_pos.x()) < 15) & (static_cast<int>(delta_pos.x()) > -15))
            delta_pos.setX(0);
        if (static_cast<int>((delta_pos.y()) < 15) & (static_cast<int>(delta_pos.y()) > -15))
            delta_pos.setY(0);

        int x = static_cast<int>((initial_pos.x() + delta_pos.x()) / gridsize) * gridsize;
        int y = static_cast<int>((initial_pos.y() + delta_pos.y()) / gridsize) * gridsize;

        if (QGraphicsItem* item = scene()->itemAt(scenePos, QTransform())) {
            item->setPos(x, y);
        }
        qDebug() << "Delta:" << delta_pos;

        QList<QGraphicsItem *> items = scene()->items();
        for (QGraphicsItem *sceneItem : items) {
            if (Level *level = dynamic_cast<Level *>(sceneItem)) {
                level->is_completed();
                break;
            }
        }
    }

    qDebug() << "Peca clicked at position:" << event->scenePos();
}

const std::vector<std::vector<bool>>& Peca::getMapaBlocos() const {
    return mapaBlocos;
}
