#ifndef PECA_H
#define PECA_H

#include <QGraphicsItem>
#include <vector>
#include <QColor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

enum TipoPeca {
    PECA_E,
    PECA_T,
    PECA_L,
    PECA_O,
    PECA_I
};

class Peca : public QGraphicsItem {
public:
    explicit Peca(const std::vector<std::vector<bool>>& formato, const QColor& cor, QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:
    std::vector<std::vector<bool>> mapaBlocos;
    QColor corPeca;
    QPointF initial_pos;
    QPointF mouse_pos;
};



#endif // PECA_H
