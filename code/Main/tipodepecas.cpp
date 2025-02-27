#include "tipodepecas.h"

Peca* FabricaDePecas::criarPeca(TipoPeca tipo, QGraphicsItem* parent) {
    std::vector<std::vector<bool>> formato;
    QColor cor;

    switch (tipo) {
    case PECA_E:
        formato = {
            {1, 1},
            {1, 0},
            {1, 1},
        };
        cor = Qt::green;
        break;

    case PECA_T:
        formato = {
            {1, 1, 1},
            {0, 1, 0},
            {0, 1, 0}
        };
        cor = Qt::blue;
        break;

    case PECA_L:
        formato = {
            {1, 0, 0 ,0},
            {1, 1, 1, 1}
        };
        cor = Qt::red;
        break;

    case PECA_I:
        formato = {
            {1},
            {1},
            {1},
            {1},
            {1}
        };
        cor = Qt::cyan;
        break;

    case PECA_1:
        formato = {
            {1, 1, 0},
            {0, 1, 0},
            {0, 1, 1}
        };
        cor = Qt::yellow;
        break;

    case PECA_2:
        formato = {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0}
        };
        cor = Qt::darkRed;
        break;

    case PECA_3:
        formato = {
            {1, 0, 0},
            {1, 1, 1},
            {0, 1, 0}
        };
        cor = Qt::magenta;
        break;

    case PECA_4:
        formato = {
            {0, 1},
            {1, 1},
            {1, 1}
        };
        cor = Qt::darkBlue;
        break;

    case PECA_5:
        formato = {
            {1, 1, 0},
            {0, 1, 1},
            {0, 0, 1}
        };
        cor = Qt::darkGreen;
        break;

    case PECA_6:
        formato = {
            {1, 1, 1, 0},
            {0, 0, 1, 1},
        };
        cor = Qt::darkCyan;
        break;

    case PECA_7:
        formato = {
            {1, 0, 0},
            {1, 0, 0},
            {1, 1, 1}
        };
        cor = Qt::darkMagenta;
        break;

    case PECA_8:
        formato = {
            {0, 0, 1, 0},
            {1, 1, 1, 1}
        };
        cor = Qt::darkYellow;
        break;
    }




    return new Peca(formato, cor, parent);
}
