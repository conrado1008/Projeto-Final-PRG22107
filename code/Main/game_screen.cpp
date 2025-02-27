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
    this->setStyleSheet(
    "QWidget {"
    "    background: white;"
    "}"
    );

    // Criar a cena gráfica
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1000, 800); // Definir o tamanho da cena

    // Criar a peça E e adicioná-la à cena
    Peca *pecaE = FabricaDePecas::criarPeca(PECA_E);
    scene->addItem(pecaE);
    pecaE->setPos(900, 200); // Posicionar a peça E
    pecaE->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça T e adicioná-la à cena
    Peca *pecaT = FabricaDePecas::criarPeca(PECA_T);
    scene->addItem(pecaT);
    pecaT->setPos(250, 0); // Posicionar a peça T
    pecaT->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça L e adicioná-la à cena
    Peca *pecaL = FabricaDePecas::criarPeca(PECA_L);
    scene->addItem(pecaL);
    pecaL->setPos(0, 50); // Posicionar a peça L
    pecaL->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça I e adicioná-la à cena
    Peca *pecaI = FabricaDePecas::criarPeca(PECA_I);
    scene->addItem(pecaI);
    pecaI->setPos(250, 150); // Posicionar a peça I
    pecaI->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça 1 e adicioná-la à cena
    Peca *peca1 = FabricaDePecas::criarPeca(PECA_1);
    scene->addItem(peca1);
    peca1->setPos(0, 200); // Posicionar a peça 1
    peca1->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça 2 e adicioná-la à cena
    Peca *peca2 = FabricaDePecas::criarPeca(PECA_2);
    scene->addItem(peca2);
    peca2->setPos(0, 400); // Posicionar a peça 2
    peca2->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça 3 e adicioná-la à cena
    Peca *peca3 = FabricaDePecas::criarPeca(PECA_3);
    scene->addItem(peca3);
    peca3->setPos(600, 0); // Posicionar a peça 3
    peca3->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça 4 e adicioná-la à cena
    Peca *peca4 = FabricaDePecas::criarPeca(PECA_4);
    scene->addItem(peca4);
    peca4->setPos(400, 0); // Posicionar a peça 4
    peca4->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça 5 e adicioná-la à cena
    Peca *peca5 = FabricaDePecas::criarPeca(PECA_5);
    scene->addItem(peca5);
    peca5->setPos(800, 0); // Posicionar a peça 5
    peca5->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça 6 e adicioná-la à cena
    Peca *peca6 = FabricaDePecas::criarPeca(PECA_6);
    scene->addItem(peca6);
    peca6->setPos(300, 450); // Posicionar a peça 6
    peca6->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça 7 e adicioná-la à cena
    Peca *peca7 = FabricaDePecas::criarPeca(PECA_7);
    scene->addItem(peca7);
    peca7->setPos(550, 450); // Posicionar a peça 7
    peca7->setZValue(1);  // Coloca a peça na frente de outros itens

    // Criar a peça 8 e adicioná-la à cena
    Peca *peca8 = FabricaDePecas::criarPeca(PECA_8);
    scene->addItem(peca8);
    peca8->setPos(800, 450); // Posicionar a peça 8
    peca8->setZValue(1);  // Coloca a peça na frente de outros itens



    QGraphicsTextItem *levelLabel = scene->addText("Nível 1");
    levelLabel->setPos(10, 10);

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
