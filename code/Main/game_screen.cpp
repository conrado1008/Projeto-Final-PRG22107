#include "game_screen.h"
#include "level.h"
#include "QMessageBox"
#include <QtWidgets>


game_screen::game_screen(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Quebra-cabeça pentaminó");

    Level *newLevelWidget = new Level(this);

    // Top row
    moveCounterLabel = new QLabel("Contagem de movimentos");
    levelLabel = new QLabel("Nível X");
        restartButton = new QPushButton("Restart");
    backToMenuButton = new QPushButton("Voltar para o menu");

    // Blocks
    block1 = new QPushButton("peça 1");
    block2 = new QPushButton("peça 2");
    block3 = new QPushButton("peça 3");
    block4 = new QPushButton("peça 4");

    // Layouts
    QGridLayout *mainLayout = new QGridLayout(this);

    // Top row
    mainLayout->addWidget(moveCounterLabel, 0, 0);
    mainLayout->addWidget(levelLabel, 0, 1);
    mainLayout->addWidget(restartButton, 0, 2);
    mainLayout->addWidget(backToMenuButton, 0, 3);

    // Blocks
    mainLayout->addWidget(block1, 1, 0);
    mainLayout->addWidget(block2, 2, 0);
    mainLayout->addWidget(block3, 1, 3);
    mainLayout->addWidget(block4, 2, 3);


    // Add the new Level widget in the same layout position
    mainLayout->addWidget(newLevelWidget, 1, 1, 2, 2);

    // Connect signals
    connect(restartButton, &QPushButton::clicked, this, &game_screen::onRestartClicked);
    connect(backToMenuButton, &QPushButton::clicked, this, &game_screen::onBackToMenuClicked);

    resize(600,400);
}

void game_screen::onRestartClicked()
{
    // Create a message box
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Game restart");
    msgBox.setText("Game restarted");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void game_screen::onBackToMenuClicked()
{
    this->close();
}
