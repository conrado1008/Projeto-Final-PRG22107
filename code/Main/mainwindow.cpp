#include "mainwindow.h"
#include "game_screen.h"
#include "QMessageBox"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Quebra-cabeça pentaminó");

this->setStyleSheet(
    "QWidget {"
    "    background: black;"
    "}"
);

//---------- Widgets ----------//

    start = new QPushButton("Iniciar");
    start->setFixedSize(200, 60);
    QObject::connect(start, SIGNAL(clicked()), this, SLOT(start_game()));

    select_level = new QPushButton("Selecionar nível");
    QObject::connect(select_level, SIGNAL(clicked()), this, SLOT(level_selection()));
    select_level->setFixedSize(200, 60);

    exit = new QPushButton("Sair");
    QObject::connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));
    exit->setFixedSize(200, 60);

//---------- Adicionando gradiente aos botões ----------//
    start->setStyleSheet(
        "QPushButton {"
        "    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #7fff7f, stop: 1 #32cd32);"
        "    border: none;"
        "    color: white;"
        "    padding: 10px;"
        "    font-size: 20px;"
        "    font-weight: bold;"
        "    border-radius: 15px;"
        "}"
        "QPushButton:hover {"
        "    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #32cd32, stop: 1 #228b22);"
        "}"
        );
    select_level->setStyleSheet(
        "QPushButton {"
        "    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #7f7fff, stop: 1 #1f1fff);"
        "    border: none;"
        "    color: white;"
        "    padding: 10px;"
        "    font-size: 20px;"
        "    font-weight: bold;"
        "    border-radius: 15px;"
        "}"
        "QPushButton:hover {"
        "    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #1f1fff, stop: 1 #0000ff);"
        "}"
        );
    exit->setStyleSheet(
        "QPushButton {"
        "    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ff7f7f, stop: 1 #ff1f1f);"
        "    border: none;"
        "    color: white;"
        "    padding: 10px;"
        "    font-size: 20px;"
        "    font-weight: bold;"
        "    border-radius: 15px;"
        "}"
        "QPushButton:hover {"
        "    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ff1f1f, stop: 1 #ff0000);"
        "}"
        );
//---------- Layout ----------//

    mainLayout = new QVBoxLayout();

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addStretch();
    hLayout->addWidget(start);
    hLayout->addStretch();

    mainLayout->addStretch();
    mainLayout->addLayout(hLayout);

    QHBoxLayout *hLayout2 = new QHBoxLayout();
    hLayout2->addStretch();
    hLayout2->addWidget(select_level);
    hLayout2->addStretch();

    QHBoxLayout *hLayout3 = new QHBoxLayout();
    hLayout3->addStretch();
    hLayout3->addWidget(exit);
    hLayout3->addStretch();

    mainLayout->addLayout(hLayout2);
    mainLayout->addLayout(hLayout3);

    mainLayout->addStretch();

    setLayout(mainLayout);

    resize(400, 400);
}

MainWindow::~MainWindow() {}


//----Mock-up de game start----//

void MainWindow::start_game() {
    // Hide the MainWindow
    this->hide();

    // Create the GameScreen window
    game_screen *gameScreen = new game_screen();

    // Show the GameScreen window
    gameScreen->setWindowTitle("Game Screen");
    gameScreen->show();

    // Connect GameScreen's close event to re-show the MainWindow
    connect(gameScreen, &game_screen::destroyed, this, &MainWindow::show);
}


//----Mock-up de level select----//

void MainWindow::level_selection(){
    // Create a message box
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Level select");
    msgBox.setText("Level selection screen");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}
