#include "game_screen.h"
#include "level.h"
#include "QMessageBox"
#include "tipodepecas.h"
#include "peca.h"
#include <QGraphicsItemGroup>
#include <QtWidgets>

game_screen::game_screen(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Quebra-cabeça pentaminó");

    // Criar a cena gráfica
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1000, 800); // Definir o tamanho da cena

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

    // Create the Level item and add it to the scene
    Level *levelItem = new Level(this);
    levelItem->setPos(150, 50);  // Adjust position of the Level in the center or based on the layout
    scene->addItem(levelItem);

    // Criar a QGraphicsView para exibir a cena
    view = new QGraphicsView(scene);
    view->setFixedSize(1000, 800);
    view->setRenderHint(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Criar layout principal
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(view);

    // Create a horizontal layout to position the buttons around the Level
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Create a button panel on top of the level
    QGraphicsRectItem *restartButtonPanel = new QGraphicsRectItem(400, 50, 80, 30);
    restartButtonPanel->setBrush(Qt::gray);
    scene->addItem(restartButtonPanel);

    QGraphicsTextItem *restartButtonText = scene->addText("Restart");
    restartButtonText->setPos(415, 55);

    QGraphicsRectItem *backToMenuButtonPanel = new QGraphicsRectItem(500, 50, 80, 30);
    backToMenuButtonPanel->setBrush(Qt::gray);
    scene->addItem(backToMenuButtonPanel);

    QGraphicsTextItem *backTextLabel = scene->addText("Voltar");
    backTextLabel->setPos(515, 55);

    // Now add the level view to the center in the layout
    QVBoxLayout *mainWindowLayout = new QVBoxLayout(this);
    mainWindowLayout->addWidget(view);

    // We can add the buttons below the level
    mainLayout->addLayout(buttonLayout);
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
