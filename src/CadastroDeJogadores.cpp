//
//  CadastroDeJogadores.cpp
//  tp
//
//  Created by Ian Godoi on 06/08/24.
//

#include "../include/CadastroDeJogadores.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

void CadastroDeJogadores::criarArquivoJogadores()const{
    const std::string nome_arquivo = "jogadores.txt";

    std::ifstream ifile(nome_arquivo.c_str());
    if (ifile) {
        std::cout << "O arquivo " << nome_arquivo << " ja existe." << std::endl;
    } else {
        std::ofstream arquivo(nome_arquivo);
        if(!arquivo){
            std::cerr <<"Erro ao criar o arquivo: "<< nome_arquivo <<std::endl;
        } else {
            std::cout << "Arquivo " << nome_arquivo << " criado com sucesso." << std::endl;
        }
    }
}

void CadastroDeJogadores::adicionarJogadorNoArquivo(const Jogador &jogador) {
    criarArquivoJogadores();
    
    carregarJogadoresDeArquivo("jogadores.txt");
    
   
    bool jogador_existe = std::any_of(jogadores.begin(), jogadores.end(),
        [&jogador](const Jogador& j) { return j.getNome() == jogador.getNome(); });
    
    if (jogador_existe) {
        std::cout << "O jogador " << jogador.getNome() << " ja existe." << std::endl;
        return;
    }
    
   
    jogadores.push_back(jogador);
    atualizarArquivo();
    
    std::cout << "Jogador " << jogador.getNome() << " adicionado ao arquivo." << std::endl;
}

void CadastroDeJogadores::carregarJogadoresDeArquivo(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    
    if(arquivo.is_open()){
        std:: string nome;
        jogadores.clear();
        
        while (arquivo >> std::quoted(nome)) {
            jogadores.emplace_back(nome);
        }
        
        arquivo.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
    }
}

void CadastroDeJogadores::limparArquivo(){
    
    
    std::string nome_arquivo = "jogadores.txt";
    
    std::ofstream arquivo(nome_arquivo, std::ios::trunc);
    
    atualizarArquivo();
    
    if(!arquivo){
        std::cerr <<"Erro ao abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
        return;
    }
    arquivo.close();
    
    std::cout <<"Arquivo limpo com sucesso." << std::endl;
}

void CadastroDeJogadores::listarJogadoresDoArquivo() {
    std::string nome_arquivo = "jogadores.txt";
        
    std::ifstream arquivo(nome_arquivo);
    
    
    
    if(!arquivo){
        std::cerr <<"Erro ao abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
        return;
    }
    
    std::string linha;
    bool lista_vazia = true;
    
    std::cout << "Lista de jogadores:" << std::endl;
    
    while (std::getline(arquivo, linha)) {
            if (!linha.empty()) {
               
                if (linha.front() == '\"' && linha.back() == '\"') {
                    linha = linha.substr(1, linha.length() - 2);
                }
                std::cout << linha << std::endl;
                lista_vazia = false;
            }
        }
    arquivo.close();
    
    if(lista_vazia){
        std::cout << "A lista de jogadores esta vazia." << std::endl;
    }
    
}

void CadastroDeJogadores::buscarJogadorNoArquivo() {
    std::string nome;
    std::cout << "Digite o nome do jogador que deseja buscar: ";
    std::cin >> nome;

    const std::string nome_arquivo = "jogadores.txt";
    carregarJogadoresDeArquivo(nome_arquivo);

    for (const auto& jogador : jogadores) {
        if (jogador.getNome() == nome) {
            std::cout << "Jogador " << nome << " encontrado no arquivo." << std::endl;
            return;
        }
    }
    std::cout << "Jogador " << nome << " nao encontrado no arquivo." << std::endl;
    return;
}

void CadastroDeJogadores::removerJogadorDoArquivo(){
    const std::string nome_arquivo = "jogadores.txt";
    carregarJogadoresDeArquivo(nome_arquivo);
    
    std::string nome_jogador;
    std::cout << "Digite o nome do jogador que deseja remover: ";
    std::cin >> nome_jogador;
    
    auto it = std::remove_if(jogadores.begin(), jogadores.end(),
                                 [&nome_jogador](const Jogador& jogador) {
                                     return jogador.getNome() == nome_jogador;
                                 });
        
    if (it != jogadores.end()) {
        
        jogadores.erase(it, jogadores.end());
        atualizarArquivo();
        std::cout << "Jogador " << nome_jogador << " foi removido com sucesso." << std::endl;
    
    } else {
        
        std::cout << "Jogador com nome " << nome_jogador << " nao encontrado no arquivo." << std::endl;
    }
}

void CadastroDeJogadores::atualizarArquivo() const {
    std::string nome_arquivo = "jogadores.txt";
    std::ofstream arquivo(nome_arquivo, std::ios::trunc);  
    if (arquivo.is_open()) {
        for (const auto& jogador : jogadores) {
            arquivo << std::quoted(jogador.getNome()) << std::endl;
        }
        arquivo.close();
        std::cout << "Arquivo " << nome_arquivo << " atualizado com sucesso." << std::endl;
    } else {
        std::cout << "Nao foi possivel abrir o arquivo " << nome_arquivo << " para atualizar." << std::endl;
    }
}

Jogador* CadastroDeJogadores::getJogadorPorNome(const std::string &nome) {
    for (auto& jogador : jogadores) {
        if (jogador.getNome() == nome) {
            return &jogador;
        }
    }
    return nullptr;
}
