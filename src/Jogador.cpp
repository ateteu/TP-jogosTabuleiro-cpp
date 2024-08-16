//
//  Jogador.cpp
//  tp
//
//  Created by Ian Godoi on 06/08/24.
//

#include "../include/Jogador.hpp"

Jogador::Jogador(): nome_jogador(""), ponto(0) {};

Jogador::Jogador( const std::string& nome_jogador, int ponto)
: nome_jogador(nome_jogador), ponto(ponto) {};

Jogador::~Jogador(){};

std::string Jogador:: get_nome() const{
    return nome_jogador;
}

void Jogador::set_nome(const std::string &nome){
    nome_jogador = nome;
}

int Jogador::get_pontos()const{
    return ponto;
}

void Jogador::set_pontos(int pontos){
    ponto = pontos;
}

void Jogador:: imprimir_jogador() const{
    std::cout<<"Nome: " << nome_jogador << std::endl;
    std::cout<<"Pontos: " << ponto << std::endl;
}
