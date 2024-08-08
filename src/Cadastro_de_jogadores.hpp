//
//  Cadastro_de_jogadores.hpp
//  tp
//
//  Created by Ian Godoi on 06/08/24.
//

#ifndef Cadastro_de_jogadores_hpp
#define Cadastro_de_jogadores_hpp

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Jogador.hpp"

class Cadastro_de_jogadores{
private:
    std::vector<Jogador> jogadores;
    
public:
    
    void criar_arquivo_jogadores() const;
    void adicionar_jogador_no_arquivo(const Jogador& jogador);
    void carregar_jogadores_de_arquivo(const std::string& nome_arquivo) ;
    bool buscar_jogador_no_arquivo(const std::string& nome);
    void remover_jogador_do_arquivo(const std::string& nome);
    void listar_jogadores_do_arquivo();
    void atualizar_arquivo()const;
    void limpar_arquivo();
    
};

#endif /* Cadastro_de_jogadores_hpp */
