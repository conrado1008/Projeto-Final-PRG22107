#include "mainwindow.h"
#include "tipodepecas.h"
#include "peca.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), view(new QGraphicsView(this)), scene(new QGraphicsScene(this))
{
    const int larguraTabuleiro = 10 * 50;
    const int alturaTabuleiro = 6 * 50;
    scene->setSceneRect(0, 0, larguraTabuleiro, alturaTabuleiro);
    view->setScene(scene);

    // Criar e adicionar uma peca
    Peca *pecaE = FabricaDePecas::criarPeca(PECA_E);
    Peca *pecaT = FabricaDePecas::criarPeca(PECA_T);
    Peca *pecaI = FabricaDePecas::criarPeca(PECA_I);
    Peca *pecaL = FabricaDePecas::criarPeca(PECA_L);
    Peca *pecaO = FabricaDePecas::criarPeca(PECA_O);

    pecaE->setPos(0, 0);
    pecaT->setPos(100, 0);
    pecaI->setPos(250, 0);
    pecaL->setPos(300, 0);
    pecaO->setPos(350, 0);

    scene->addItem(pecaE);
    scene->addItem(pecaT);
    scene->addItem(pecaI);
    scene->addItem(pecaL);
    scene->addItem(pecaO);

    setCentralWidget(view);
    resize(larguraTabuleiro, alturaTabuleiro);
}

// Destrutor
MainWindow::~MainWindow() {
    delete view;
    delete scene;
}
