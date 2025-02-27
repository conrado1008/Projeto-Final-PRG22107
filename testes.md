# Testes

## Testes das funções de criação e movimentação de peças:
Para implementação, foram criadas duas classes, uma responsável pela peça em si (peca.cpp) e outra responsável pela criação destas(tipodepeca.cpp).
As peças deveriam ser capazes de se movimentar e possuir formatos variados.
Para validação, foram criadas diversas peças na mesma cena e foi verificado o comportamento destas.
- A criação das peças por meio da classe tipodepeca.cpp foi validada e também foi possível verificar a movimentação das peças em uma cena vazia (somente com as peças criadas).


## Testes do ajuste da função snap to grid das peças:
Com a movimentação das peças validada, foram feitos teste para implementação de uma função snap to grid que seria importante para a usabilidade do sistema.
Para testes da função foi verificado visualmente a presença da funcionalidade.
- A funcionalidade foi implementada e foi validada durante uma partida.

## Validação de conclusão da fase
Uma das principais funcionalidade da classe level é a verificação de conclusão da fase, de forma que se todos os quadrados do tabuleiro estivessem preenchidos, ocorreria uma forma de notificação.
- A funcionalidade foi implementada e verificada por meio da função Qdebug presente no QtCreator, foram criadas peças simples para facilitar a verificação que ocorrem por meio da verificação da ocupação de cada um dos quadrados do tabuleiro.







>[!NOTE]
> Relatar o processo de testes do sistema, especificando quais testes foram realizados e os resultados obtidos.

<div align="center">

[Retroceder](implementacao.md) | [Início](README.md)

</div>
