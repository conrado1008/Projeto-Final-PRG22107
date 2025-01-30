#ifndef PECA_H
#define PECA_H

#include <QGraphicsItem>
#include <vector>
#include <QColor>

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

private:
    std::vector<std::vector<bool>> mapaBlocos;
    QColor corPeca;
};

#endif // PECA_H
