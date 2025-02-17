#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QtWidgets>

class game_screen : public QWidget
{
    Q_OBJECT

public:
    explicit game_screen(QWidget *parent = nullptr);

private slots:
    void onRestartClicked();

private:
    QGraphicsView *view;  // Para exibir a cena do jogo
    QGraphicsScene *scene;  // Cena para todos os itens gráficos
    QPushButton * restart;
};

#endif // GAME_SCREEN_H
