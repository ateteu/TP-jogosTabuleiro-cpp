//
//  CadastroDeJogadores.hpp
//  tp
//
//  Created by Ian Godoi on 06/08/24.
//

#ifndef CadastroDeJogadores_hpp
#define CadastroDeJogadores_hpp

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../src/Jogador.cpp"

class CadastroDeJogadores {
private:
    std::vector<Jogador> jogadores;
    
public:
    
    void criar_arquivo_jogadores() const;
    void adicionar_jogador_no_arquivo(const Jogador& jogador);
    void carregar_jogadores_de_arquivo(const std::string& nome_arquivo) ;
    bool buscar_jogador_no_arquivo(const std::string& nome);
    void remover_jogador_do_arquivo(const std::string& nome);
    void atualizar_nome_do_jogador(const std::string& nome_atual, const std::string& novo_nome );
    void listar_jogadores_do_arquivo();
    void atualizar_arquivo()const;
    void limpar_arquivo();
    
};

#endif // CadastroDeJogadores_hpp
