
#include "level.h"
#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow level;
    //level.setWindowTitle("Tabuleiro 10x6");
    level.show();

    return app.exec();
}

