#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include "QMessageBox"
#include <QtWidgets>


class game_screen : public QWidget
{
    Q_OBJECT

public:
    explicit game_screen(QWidget *parent = nullptr);

private slots:
    void onRestartClicked();
    void onBackToMenuClicked();

private:
    QLabel *moveCounterLabel;
    QLabel *levelLabel;
    QPushButton *restartButton;
    QPushButton *backToMenuButton;
    QPushButton *block1;
    QPushButton *block2;
    QPushButton *block3;
    QPushButton *block4;
};

#endif // GAME_SCREEN_H
