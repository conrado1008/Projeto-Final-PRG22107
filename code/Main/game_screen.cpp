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

    restart = new QPushButton("teste");
    restart->setFixedSize(100,60);

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

    // Create the Level item and add it to the scene
    Level *levelItem = new Level(this);
    levelItem->setPos(350, 150);  // Adjust position of the Level in the center or based on the layout
    scene->addItem(levelItem);

    // Criar a QGraphicsView para exibir a cena
    view = new QGraphicsView(scene);
    view->setFixedSize(1000, 800);
    view->setRenderHint(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Criar layout principal
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(view);

    // Lógica para implementar botões durante a fase
    mainLayout->addStretch();
    mainLayout->addWidget(restart);

    // Create a horizontal layout to position the buttons around the Level
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Now add the level view to the center in the layout
    QVBoxLayout *mainWindowLayout = new QVBoxLayout(this);
    mainWindowLayout->addWidget(view);

    // We can add the buttons below the level
    mainLayout->addLayout(buttonLayout);

    this->resize(1000,600);
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
