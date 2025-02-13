#include "level.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

Level::Level(QObject *parent) : QGraphicsItem(nullptr)  // Set the parent to nullptr for QGraphicsItem
{
    setupBoard();  // Initialize the board/grid
}

Level::~Level()
{
    // Clean up grid items
    qDeleteAll(grid);  // Delete all grid squares
}

void Level::setupBoard()
{
    // Clear the grid if it's being reset
    qDeleteAll(grid);
    grid.clear();

    // Create the grid of squares
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            // Create squares (represented as QGraphicsRectItems)
            QGraphicsRectItem *square = new QGraphicsRectItem(col * 50, row * 50, 50, 50, this);
            square->setPen(QPen(Qt::black));  // Black border
            square->setBrush(QBrush(Qt::lightGray));  // Light gray fill
            grid.append(square);  // Add to the grid
        }
    }
}

// Define the bounding rect of the item, which will be used for layout and rendering
QRectF Level::boundingRect() const
{
    // The bounding box covers the entire grid area
    return QRectF(0, 0, width * 50, height * 50);
}

// Paint the grid (custom drawing)
void Level::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Draw the grid by iterating over all squares
    for (QGraphicsRectItem *square : grid) {
        square->setPos(square->x(), square->y());  // Update the position of each square if necessary
        square->paint(painter, option, widget);  // Call paint for each square (via QGraphicsRectItem)
    }
}
