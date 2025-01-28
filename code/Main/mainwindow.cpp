#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
//---------- Widgets ----------//

    start = new QPushButton("Iniciar");
    start->setFixedSize(100,60);
    QObject::connect(start, SIGNAL(stateChanged(int)), this, SLOT(togleCheckbox()));

    select_level = new QPushButton("Selecionar nível");
    select_level->setFixedSize(100,60);

    exit = new QPushButton("Sair");
    exit->setFixedSize(100,60);

//---------- Layout ----------//

    mainLayout = new QVBoxLayout();

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addStretch(); // Espaço à esquerda
    hLayout->addWidget(start); // Adiciona o primeiro botão
    hLayout->addStretch(); // Espaço à direita

    mainLayout->addStretch(); // Espaço acima dos botões
    mainLayout->addLayout(hLayout); // Adiciona o layout horizontal para o primeiro botão

    QHBoxLayout *hLayout2 = new QHBoxLayout();
    hLayout2->addStretch(); // Espaço à esquerda
    hLayout2->addWidget(select_level); // Adiciona o primeiro botão
    hLayout2->addStretch(); // Espaço à direita

    QHBoxLayout *hLayout3 = new QHBoxLayout();
    hLayout3->addStretch(); // Espaço à esquerda
    hLayout3->addWidget(exit); // Adiciona o primeiro botão
    hLayout3->addStretch(); // Espaço à direita

    mainLayout->addLayout(hLayout2);
    mainLayout->addLayout(hLayout3);

    mainLayout->addStretch();

    setLayout(mainLayout);

//----------------------------//

    resize(400,400);
}

MainWindow::~MainWindow() {}

