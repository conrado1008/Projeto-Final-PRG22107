#include "level.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Level level;
    //level.setWindowTitle("Tabuleiro 10x6");
    level.show();

    return app.exec();
}
