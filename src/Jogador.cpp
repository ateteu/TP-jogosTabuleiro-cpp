#include "../include/Jogador.hpp"

Jogador::Jogador() : nome_jogador(""), vitorias(0), empates(0), derrotas(0) {}

Jogador::Jogador(const std::string& nome_jogador)
    : nome_jogador(nome_jogador), vitorias(0), empates(0), derrotas(0) {}

Jogador::Jogador(char _peca) : peca(_peca) {} // construtor para inicializar a peça do jogador

Jogador::~Jogador() {}

std::string Jogador::getNome() const {
    return nome_jogador;
}

void Jogador::setNome(const std::string& nome) {
    nome_jogador = nome;
}

char Jogador::minhaPeca() const {
    return peca;
}

int Jogador::getVitorias() const {
    return vitorias;
}

int Jogador::getEmpates() const {
    return empates;
}

int Jogador::getDerrotas() const {
    return derrotas;
}

void Jogador::registrarVitoria() {
    vitorias++;
}

void Jogador::registrarEmpate() {
    empates++;
}

void Jogador::registrarDerrota() {
    derrotas++;
}

void Jogador::imprimirJogador() const {
    std::cout << "Nome: " << nome_jogador << std::endl;
    std::cout << "Vitórias: " << vitorias << std::endl;
    std::cout << "Empates: " << empates << std::endl;
    std::cout << "Derrotas: " << derrotas << std::endl;
}
