#include "level.h"
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>

Level::Level(QWidget *parent)
    : QWidget(parent)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    // Rótulos de level_id e moves_value
    levelLabel = new QLabel("Level ID: " + QString::number(level_id), this);
    movesLabel = new QLabel("Moves: " + QString::number(moves_value), this);

    // Botão de fechar
    closeButton = new QPushButton("Close", this);
    QObject::connect(closeButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    // Layout principal
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(levelLabel);
    mainLayout->addWidget(movesLabel);
    mainLayout->addWidget(view);

    // Layout para o botão de fechar
    hBottomLayout = new QHBoxLayout();
    hBottomLayout->addWidget(closeButton);

    mainLayout->addLayout(hBottomLayout);

    setLayout(mainLayout);

    view->setFixedSize(620, 380);
    setupBoard();
}

Level::~Level() {}

void Level::setupBoard() {
    // Limpa a cena e o grid existente
    scene->clear();
    grid.clear();

    // Cria os quadradinhos do tabuleiro
    for (int row = 0; row < height; ++row) {
        QVector<QGraphicsRectItem*> rowItems;
        for (int col = 0; col < width; ++col) {
            QGraphicsRectItem *square = scene->addRect(col * 60, row * 60, 60, 60, QPen(Qt::black), QBrush(Qt::lightGray));
            rowItems.append(square);
        }
        grid.append(rowItems);
    }
}

void Level::updateLevelInfo() {
    // Atualiza os rótulos de level_id e moves_value
    levelLabel->setText("Level ID: " + QString::number(level_id));
    movesLabel->setText("Moves: " + QString::number(moves_value));
}

void Level::mouseReleaseEvent(QMouseEvent *event) {
    // Aumenta o valor de moves_value quando o mouse for solto
    moves_value++;
    updateLevelInfo(); // Atualiza as informações no GUI
    QWidget::mouseReleaseEvent(event); // Chama o método base
}
