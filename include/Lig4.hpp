#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"

class Lig4 : public Jogo {
public:
    // Construtor
    Lig4();

    // Sobrescrições dos métodos virtuais da classe base Jogo
    void inicializarTabuleiro() override;
    bool validarJogada(int linha, int coluna, Jogador jogador) override; 
    bool verificarCondicaoVitoria() override;
    void realizarJogada(int coluna) override;

private:
    static const int largura = 7;  // Largura do tabuleiro para Lig4
    static const int altura = 6;   // Altura do tabuleiro para Lig4
};

#endif // LIG4_HPP