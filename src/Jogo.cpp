#include "../include/Jogo.hpp"

Jogo::Jogo() : jogadorAtual(nullptr) {}

void Jogo::inicializarTabuleiro() {
    // método virtual que deve ser implementado nas subclasses
}

int Jogo::verificarCondicaoVitoria(char peca) {
    // implementar nas subclasses
}

void Jogo::imprimirTabuleiro() {
    tabuleiro->imprimir();
}

Jogador* Jogo::getJogadorAtual(){
    return jogadorAtual;
}

Jogo::~Jogo() {
    delete tabuleiro;
    // supondo que jogadorAtual não precisa ser deletado aqui
}
