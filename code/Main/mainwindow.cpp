#include <QDebug>
#include "mainwindow.h"
#include "tipodepecas.h"
#include "peca.h"
#include "level.h"  // Incluir o arquivo da classe Level
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), view(new QGraphicsView(this)), scene(new QGraphicsScene(this))
{
    const int larguraTabuleiro = 10 * 50;
    const int alturaTabuleiro = 6 * 50;
    scene->setSceneRect(0, 0, larguraTabuleiro, alturaTabuleiro);

    // Criar e adicionar o Level (Tabuleiro) à cena
    Level *nivel = new Level(6, 10, 50);  // Criar o nível com 6 linhas e 10 colunas
    scene->addItem(nivel);  // Adicionar o tabuleiro (Level) à cena

    // Criar e adicionar as peças
    Peca *pecaE = FabricaDePecas::criarPeca(PECA_E);
    Peca *pecaT = FabricaDePecas::criarPeca(PECA_T);
    Peca *pecaI = FabricaDePecas::criarPeca(PECA_I);
    Peca *pecaL = FabricaDePecas::criarPeca(PECA_L);
    Peca *pecaO = FabricaDePecas::criarPeca(PECA_O);

    pecaE->setPos(0, 0);  // Posicionar as peças
    pecaT->setPos(100, 0);
    pecaI->setPos(250, 0);
    pecaL->setPos(300, 0);
    pecaO->setPos(350, 0);

    // Adicionando as peças à cena
    scene->addItem(pecaE);
    scene->addItem(pecaT);
    scene->addItem(pecaI);
    scene->addItem(pecaL);
    scene->addItem(pecaO);

    // Criar os botões
    QPushButton *button1 = new QPushButton("Botão 1", this);
        QPushButton *button2 = new QPushButton("Botão 2", this);

        // Conectar os botões a slots (opcional)
        connect(button1, &QPushButton::clicked, this, []() {
            qDebug() << "Botão 1 clicado!";
        });
    connect(button2, &QPushButton::clicked, this, []() {
        qDebug() << "Botão 2 clicado!";
    });

    // Layout para os botões na parte superior
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(button1);
    buttonLayout->addWidget(button2);

    // Layout principal para a janela
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);

    // Adicionar os botões e a view ao layout
    mainLayout->addLayout(buttonLayout);  // Adicionar botões
    mainLayout->addWidget(view);  // Adicionar a QGraphicsView

    // Definir o layout da janela principal
    setCentralWidget(centralWidget);

    // Configurar a QGraphicsView
    view->setScene(scene);
    resize(larguraTabuleiro, alturaTabuleiro);
}

// Destrutor
MainWindow::~MainWindow() {
    delete view;
    delete scene;
}
