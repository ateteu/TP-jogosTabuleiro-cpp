#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include "Tabuleiro.hpp"

class Lig4 : public Jogo {
public:
    // Construtor
    Lig4();

    // Sobrescrições dos métodos virtuais da classe base Jogo
    void inicializarTabuleiro() override;
<<<<<<< HEAD
    bool validarJogada(int linha, int coluna, Jogador jogador) override; 
=======
    bool validarJogada(int linha, int coluna, Jogador* jogador) override; 
>>>>>>> 85fd9e014f264f928575d997787a8f646cf3e746
    int verificarCondicaoVitoria() override;
    void realizarJogada() override;

private:
    static const int largura = 7;  // Largura do tabuleiro para Lig4
    static const int altura = 6;   // Altura do tabuleiro para Lig4
    Tabuleiro* tabuleiro = new Tabuleiro();
    char jogador1Peca = 'X'; // Peça do jogador 1
    char jogador2Peca = 'O'; // Peça do jogador 2
};

#endif // LIG4_HPP