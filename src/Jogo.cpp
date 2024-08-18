#include "../include/Jogo.hpp"

// Classe Jogo possui mais de um construtor padão
//Jogo::Jogo(){}

void Jogo::inicializarTabuleiro() {

}

void Jogo::validarJogada(int _x, int _y) {
    if(tabuleiro -> posicaoValida(_x, _y)){
        // colocar como essa jogada será validada para cada jogo
    }
}


void Jogo::verificarCondicaoVitoria(Tabuleiro* _tabuleiro) {
    // colocar como será dada a vitória para cada jogo
}

void Jogo::imprimirTabuleiro() {
    tabuleiro -> imprimir();
}

void Jogo::realizarJogada() {}

Jogo::~Jogo() {}