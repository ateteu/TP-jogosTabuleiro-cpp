//
//  CadastroDeJogadores.hpp
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

class CadastroDeJogadores{
private:
    std::vector<Jogador> jogadores;
    
public:
    
    void criarArquivoJogadores() const;
    void adicionarJogadorNoArquivo(const Jogador& jogador);
    void carregarJogadoresDeArquivo(const std::string& nome_arquivo) ;
    bool buscarJogadorNoArquivo(const std::string& nome);
    void removerJogadorDoArquivo(const std::string& nome);
    void atualizarNomeDoJogador(const std::string& nome_atual, const std::string& novo_nome );
    void listarJogadoresDoArquivo();
    void atualizarArquivo()const;
    void limparArquivo();
    
};

#endif /* Cadastro_de_jogadores_hpp */
