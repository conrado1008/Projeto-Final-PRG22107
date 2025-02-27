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
    PECA_I,
    PECA_1,
    PECA_2,
    PECA_3,
    PECA_4,
    PECA_5,
    PECA_6,
    PECA_7,
    PECA_8
};

class Peca : public QGraphicsItem {
public:
    Peca(const std::vector<std::vector<bool>>& formato, const QColor& cor, QGraphicsItem* parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    const std::vector<std::vector<bool>>& getMapaBlocos() const; // Getter para mapaBlocos

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
