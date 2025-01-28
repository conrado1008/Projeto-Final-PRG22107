#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QVector>

class Level : public QWidget {
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    void restart();

private:
    int width = 10;  // Largura do tabuleiro
    int height = 6;  // Altura do tabuleiro
    QGraphicsScene *scene; // Cena gráfica
    QGraphicsView *view;   // Visão para exibir a cena
    QVector<QVector<QGraphicsRectItem*>> grid; // Armazena os quadrados do tabuleiro

    void setupBoard(); // Cria o tabuleiro
};

#endif // LEVEL_H
