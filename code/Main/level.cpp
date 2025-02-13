#include "level.h"

Level::Level(int numLinhas, int numColunas, int tamanhoCelula)
    : m_numLinhas(numLinhas), m_numColunas(numColunas), m_tamanhoCelula(tamanhoCelula)
{}

QRectF Level::boundingRect() const
{
    return QRectF(0, 0, m_numColunas * m_tamanhoCelula, m_numLinhas * m_tamanhoCelula);
}

void Level::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Desenha as células do tabuleiro
    for (int i = 0; i < m_numLinhas; ++i) {
        for (int j = 0; j < m_numColunas; ++j) {
            QRectF cellRect(j * m_tamanhoCelula, i * m_tamanhoCelula, m_tamanhoCelula, m_tamanhoCelula);
            painter->setPen(QPen(Qt::black));  // Cor da borda
            painter->setBrush(QBrush(Qt::lightGray));  // Cor de fundo
            painter->drawRect(cellRect);  // Desenhar o retângulo da célula
        }
    }
}
