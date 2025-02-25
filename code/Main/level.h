#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsItem>
#include <QList>
#include <QGraphicsScene>

class Level : public QGraphicsItem
{
public:
    Level(QObject *parent = nullptr);
    ~Level();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool is_completed() const; // Método para verificar se o tabuleiro está cheio

private:
    void setupBoard(); // Inicializa o tabuleiro
    QList<QGraphicsRectItem *> grid; // Lista de quadrados do tabuleiro
    int height = 6;  // Alterado para 6 linhas
    int width = 10;  // Alterado para 10 colunas
};

#endif // LEVEL_H
