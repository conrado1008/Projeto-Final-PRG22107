#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMouseEvent> // Para capturar eventos do mouse

class Level : public QWidget {
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();

    void mouseReleaseEvent(QMouseEvent *event); // Sobrescreve evento de soltura do mouse

private:
    int width = 10;  // Largura do tabuleiro
    int height = 6;  // Altura do tabuleiro
    uint level_id = 1;
    bool is_completed = false;
    uint moves_value = 0;
    uint total_size = width * height;
    uint blank_spaces = width * height;

    QGraphicsScene *scene;
    QGraphicsView *view;
    QVector<QVector<QGraphicsRectItem*>> grid;
    QLabel *levelLabel;
    QLabel *movesLabel;
    QPushButton *closeButton;

    QVBoxLayout *mainLayout;
    QHBoxLayout *hBottomLayout;

    void setupBoard();

private slots:
    void updateLevelInfo();
};

#endif // LEVEL_H
