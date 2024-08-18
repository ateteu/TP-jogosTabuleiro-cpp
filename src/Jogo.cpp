#include "../include/Jogo.hpp"

Jogo::Jogo() : jogadorAtual(nullptr) {}

void Jogo::inicializarTabuleiro() {
    // método virtual que deve ser implementado nas subclasses
}

bool Jogo::validarJogada(int _linha, int _coluna, Jogador jogador) {
    // método puramente virtual: deve ser implementado nas subclasses
    return false;
}

bool Jogo::verificarCondicaoVitoria() {
    // implementar nas subclasses
}

void Jogo::imprimirTabuleiro() {
    tabuleiro->imprimir();
}

void Jogo::realizarJogada() {
    // implementar nas subclasses
}

Jogo::~Jogo() {
    delete tabuleiro;
    // supondo que jogadorAtual não precisa ser deletado aqui
}
