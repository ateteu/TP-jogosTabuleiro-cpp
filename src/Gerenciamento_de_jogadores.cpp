//
//  Gerenciamento_de_jogadores.cpp
//  tp
//
//  Created by Ian Godoi on 06/08/24.
//

#include "Gerenciamento_de_jogadores.hpp"
#include <iostream>

void Gerenciamento_de_jogadores::criar_arquivo_jogadores()const{
    const std::string nome_arquivo = "jogadores.txt";
    
    if (std::filesystem::exists(nome_arquivo)){
        std::cout << "O arquivo "<< nome_arquivo << " já existe."<< std::endl;
    } else{
        std::ofstream arquivo(nome_arquivo);
        if(!arquivo){
            std::cerr <<"Erro ao criar o arquivo: "<< nome_arquivo <<std::endl;
        } else {
            std::cout << "Arquivo "<< nome_arquivo<< " criado com sucesso." << std::endl;
        }
    }
    
};

void Gerenciamento_de_jogadores::adicionar_jogador_no_arquivo(const Jogador &jogador) {
    criar_arquivo_jogadores();
    
    carregar_jogadores_de_arquivo("jogadores.txt");
    
    // Verifica se o jogador já existe na lista
    bool jogador_existe = std::any_of(jogadores.begin(), jogadores.end(),
        [&jogador](const Jogador& j) { return j.get_nome() == jogador.get_nome(); });
    
    if (jogador_existe) {
        std::cout << "O jogador " << jogador.get_nome() << " já existe." << std::endl;
        return;
    }
    
   
    jogadores.push_back(jogador);
    atualizar_arquivo();
    
    std::cout << "Jogador " << jogador.get_nome() << " adicionado ao arquivo." << std::endl;
}

void Gerenciamento_de_jogadores::carregar_jogadores_de_arquivo(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    
    if(arquivo.is_open()){
        std:: string nome;
        jogadores.clear();
        
        while (arquivo >> std::quoted(nome)) {
            jogadores.emplace_back(nome);
        }
        
        arquivo.close();
        std::cout << "Jogadores carregados do arquivo: "<< nome_arquivo <<"."<< std::endl;
    }else{
        std::cout << "Não foi possível abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
    }
}

void Gerenciamento_de_jogadores::limpar_arquivo(){
    
    
    std::string nome_arquivo = "jogadores.txt";
    
    std::ofstream arquivo(nome_arquivo, std::ios::trunc);
    
    atualizar_arquivo();
    
    if(!arquivo){
        std::cerr <<"Erro ao abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
        return;
    }
    arquivo.close();
    
    std::cout <<"Arquivo limpo com sucesso." << std::endl;
}

void Gerenciamento_de_jogadores::listar_jogadores_do_arquivo() {
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
        std::cout << "A lista de jogadores está vazia." << std::endl;
    }
    
}

bool Gerenciamento_de_jogadores::buscar_jogador_no_arquivo(const std::string &nome) {
    const std::string nome_arquivo = "jogadores.txt";
    carregar_jogadores_de_arquivo(nome_arquivo);
    
    for(const auto& jogador : jogadores){
        if(jogador.get_nome()==nome){
            std::cout <<"Jogador "<< nome<<"encontrado no arquivo." <<std::endl;
            return true;
        }
    }
    std::cout << "Jogador " << nome << " não encontrado no arquivo." << std::endl;
    return false;
}

void Gerenciamento_de_jogadores::remover_jogador_do_arquivo(const std::string &nome){
    const std::string nome_arquivo = "jogadores.txt";
    carregar_jogadores_de_arquivo(nome_arquivo);
    
    auto it = std::remove_if(jogadores.begin(), jogadores.end(),
                                 [&nome](const Jogador& jogador) {
                                     return jogador.get_nome() == nome;
                                 });
        
    if (it != jogadores.end()) {
        
        jogadores.erase(it, jogadores.end());
        atualizar_arquivo();
        std::cout << "Jogador " << nome << " foi removido com sucesso." << std::endl;
    
    } else {
        
        std::cout << "Jogador com nome " << nome << " não encontrado no arquivo." << std::endl;
    }
}
void Gerenciamento_de_jogadores::atualizar_arquivo() const {
    std::string nome_arquivo = "jogadores.txt";
    std::ofstream arquivo(nome_arquivo, std::ios::trunc);  // Abre o arquivo para escrita, truncando o conteúdo existente
    if (arquivo.is_open()) {
        for (const auto& jogador : jogadores) {
            arquivo << std::quoted(jogador.get_nome()) << std::endl;
        }
        arquivo.close();
        std::cout << "Arquivo " << nome_arquivo << " atualizado com sucesso." << std::endl;
    } else {
        std::cout << "Não foi possível abrir o arquivo " << nome_arquivo << " para atualizar." << std::endl;
    }
}
