#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsItem>
#include <QVector>
#include <QGraphicsRectItem>

class Level : public QGraphicsItem
{
public:
    explicit Level(QObject *parent = nullptr);
    ~Level();

    void setupBoard();  // Set up the grid
    QRectF boundingRect() const override;  // Define the item's bounding box
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;  // Custom paint function

private:
    int width = 10;   // Width of the grid
    int height = 6;   // Height of the grid
    QVector<QGraphicsRectItem*> grid;  // List of all grid items (rectangles)
};

#endif // LEVEL_H
