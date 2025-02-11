#ifndef TIPODEPECAS_H
#define TIPODEPECAS_H

#include "peca.h"

class FabricaDePecas {
public:
    static Peca* criarPeca(TipoPeca tipo, QGraphicsItem* parent = nullptr);
};

#endif // TIPODEPECAS_H
