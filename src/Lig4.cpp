#ifndef LIG4_H
#define LIG4_H

#include "Jogo.h"

class Lig4 : public Jogo {
public:
    // Construtor
    Lig4();

    // Sobrescrições dos métodos virtuais da classe base Jogo
    void inicializarTabuleiro() override;
    bool validarJogada(int coluna) override;
    bool verificarCondicaoVitoria() override;
    void imprimirTabuleiro() override;
    void realizarJogada(int coluna) override;

private:
    static const int largura = 7;  // Largura do tabuleiro para Lig4
    static const int altura = 6;   // Altura do tabuleiro para Lig4
};

#endif // LIG4_H