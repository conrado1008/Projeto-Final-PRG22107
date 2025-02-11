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
            {1, 0},
            {1, 0},
            {1, 1}
        };
        cor = Qt::red;
        break;

    case PECA_O:
        formato = {
            {1, 1},
            {1, 1}
        };
        cor = Qt::yellow;
        break;

    case PECA_I:
        formato = {
            {1},
            {1},
            {1},
        };
        cor = Qt::cyan;
        break;
    }

    return new Peca(formato, cor, parent);
}
