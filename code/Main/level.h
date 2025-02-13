#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QPainter>

class Level : public QGraphicsItem
{
public:
    Level(int numLinhas, int numColunas, int tamanhoCelula);
    ~Level() {}

    // Métodos necessários para QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int m_numLinhas;
    int m_numColunas;
    int m_tamanhoCelula;
};

#endif // LEVEL_H
