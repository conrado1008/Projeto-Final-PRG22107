#include "game_screen.h"
#include "level.h"
#include "QMessageBox"
#include "tipodepecas.h"
#include "peca.h"
#include <QtWidgets>

game_screen::game_screen(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Quebra-cabeça pentaminó");

    // Criar a cena gráfica
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 600, 400); // Definir o tamanho da cena

    // Criar a peça e adicioná-la à cena
    Peca *pecaE = FabricaDePecas::criarPeca(PECA_E);
    scene->addItem(pecaE);
    pecaE->setPos(100, 150); // Posicionar a peça

    // Definir um valor Z alto para garantir que a peça fique à frente
    pecaE->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar elementos gráficos (labels)
    QGraphicsTextItem *moveCounterLabel = scene->addText("Contagem de movimentos");
    moveCounterLabel->setPos(10, 10);

    QGraphicsTextItem *levelLabel = scene->addText("Nível X");
    levelLabel->setPos(200, 10);

    // Criar botões gráficos
    QGraphicsRectItem *restartButton = new QGraphicsRectItem(400, 10, 80, 30);
    restartButton->setBrush(Qt::gray);
    scene->addItem(restartButton);

    QGraphicsTextItem *restartText = scene->addText("Restart");
    restartText->setPos(415, 15);

    QGraphicsRectItem *backToMenuButton = new QGraphicsRectItem(500, 10, 80, 30);
    backToMenuButton->setBrush(Qt::gray);
    scene->addItem(backToMenuButton);

    QGraphicsTextItem *backText = scene->addText("Voltar");
    backText->setPos(515, 15);

    // Criar a QGraphicsView para exibir a cena
    view = new QGraphicsView(scene);
    view->setFixedSize(600, 400);
    view->setRenderHint(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Criar layout principal
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(view);

    // Criar o nível e adicionar ao layout
    Level *levelScene = new Level(this);
    QGraphicsView *levelView = new QGraphicsView(levelScene);
    mainLayout->addWidget(levelView);

    resize(600, 400);
}

void game_screen::onRestartClicked()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Game restart");
    msgBox.setText("Game restarted");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}
