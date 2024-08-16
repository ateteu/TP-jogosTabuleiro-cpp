//
//  Pontuacao.hpp
//  tp
//
//  Created by Ian Godoi on 08/08/24.
//

#ifndef Pontuacao_hpp
#define Pontuacao_hpp

#include <iostream>
#include <string>
#include "Jogador.hpp"
#include <vector>

class Pontuacao{
private:

std::vector<Jogador> jogadores;
std::string nome;
int pontos;

public:
    Pontuacao(const std::string& nome_jogador, int pontos = 0);
    ~Pontuacao();
    void adicionarPontos(const std::string& nome_arquivo, const std:: string& nome_jogador, int pontos_adicionais);
    void zerarPontos(const std::string& nome_arquivo, const std:: string& nome_jogador);
    void criarArquivoPontuacao(const std::string& nome_arquivo) const;
    void listarArquivoPontuacao(const std::string& nome_arquivo)const;
    void carregarJogadoresdeArquivo(const std::string& nome_arquivo);
};

#endif /* Pontuacao_hpp */
