#include "../include/Reversi.hpp"

class Reversi : public Jogo {
public:
    void inicializarTabuleiro() override {
        // Implementação específica do Reversi
    }

    bool validarJogada(int x, int y, Jogador jogador) override {
        // Implementação específica do Reversi
        return true; // Exemplo simples
    }

    bool verificarCondicaoVitoria() override {
        // Implementação específica do Reversi
        return false; // Exemplo simples
    }

    void imprimirTabuleiro() override {
        // Implementação específica do Reversi
    }

    void realizarJogada(int x, int y, Jogador jogador) override {
        // Implementação específica do Reversi
    }
};
