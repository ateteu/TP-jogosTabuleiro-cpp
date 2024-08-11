//
//  Jogador.cpp
//  tp
//
//  Created by Ian Godoi on 06/08/24.
//

#include "Jogador.hpp"

Jogador::Jogador(): nome_jogador(""), ponto(0) {};

Jogador::Jogador( const std::string& nome_jogador, int ponto)
: nome_jogador(nome_jogador), ponto(ponto) {};

Jogador::~Jogador(){};

std::string Jogador:: getNome() const{
    return nome_jogador;
}

void Jogador::setNome(const std::string &nome){
    nome_jogador = nome;
}

int Jogador::getPontos()const{
    return ponto;
}

void Jogador::setPontos(int pontos){
    ponto = pontos;
}

void Jogador::imprimirJogador() const{
    std::cout<<"Nome: " << nome_jogador << std::endl;
    std::cout<<"Pontos: " << ponto << std::endl;
}
