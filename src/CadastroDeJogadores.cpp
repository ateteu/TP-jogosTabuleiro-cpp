//
//  CadastroDeJogadores.cpp
//  tp
//
//  Created by Ian Godoi on 06/08/24.
//

#include "CadastroDeJogadores.hpp"
#include <iostream>

void CadastroDeJogadores::criarArquivoJogadores()const{
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

void CadastroDeJogadores::adicionarJogadorNoArquivo(const Jogador &jogador) {
    criarArquivoJogadores();
    
    carregarJogadoresDeArquivo("jogadores.txt");
    
   
    bool jogador_existe = std::any_of(jogadores.begin(), jogadores.end(),
        [&jogador](const Jogador& j) { return j.get_nome() == jogador.get_nome(); });
    
    if (jogador_existe) {
        std::cout << "O jogador " << jogador.get_nome() << " já existe." << std::endl;
        return;
    }
    
   
    jogadores.push_back(jogador);
    atualizarArquivo();
    
    std::cout << "Jogador " << jogador.get_nome() << " adicionado ao arquivo." << std::endl;
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
        std::cout << "Jogadores carregados do arquivo: "<< nome_arquivo <<"."<< std::endl;
    }else{
        std::cout << "Não foi possível abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
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
        std::cout << "A lista de jogadores está vazia." << std::endl;
    }
    
}

bool CadastroDeJogadores::buscarJogadorNoArquivo(const std::string &nome) {
    const std::string nome_arquivo = "jogadores.txt";
    carregarJogadoresDeArquivo(nome_arquivo);
    
    for(const auto& jogador : jogadores){
        if(jogador.get_nome()==nome){
            std::cout <<"Jogador "<< nome<<"encontrado no arquivo." <<std::endl;
            return true;
        }
    }
    std::cout << "Jogador " << nome << " não encontrado no arquivo." << std::endl;
    return false;
}

void CadastroDeJogadores::removerJogadorDoArquivo(const std::string &nome){
    const std::string nome_arquivo = "jogadores.txt";
    carregarJogadoresDeArquivo(nome_arquivo);
    
    auto it = std::remove_if(jogadores.begin(), jogadores.end(),
                                 [&nome](const Jogador& jogador) {
                                     return jogador.get_nome() == nome;
                                 });
        
    if (it != jogadores.end()) {
        
        jogadores.erase(it, jogadores.end());
        atualizarArquivo();
        std::cout << "Jogador " << nome << " foi removido com sucesso." << std::endl;
    
    } else {
        
        std::cout << "Jogador com nome " << nome << " não encontrado no arquivo." << std::endl;
    }
}
void CadastroDeJogadores::atualizarArquivo() const {
    std::string nome_arquivo = "jogadores.txt";
    std::ofstream arquivo(nome_arquivo, std::ios::trunc);  
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

void CadastroDeJogadores::atualizarNomeDoJogador(const std::string &nome_atual, const std::string &novo_nome) {
    std::string nome_arquivo = "jogadores.txt";

    std::ifstream arquivo(nome_arquivo);

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo " << nome_arquivo << " para leitura." << std::endl;
        return;
    }

    std::string conteudo_atualizado;
    std::string linha;

    bool encontrado = false;

    while (std::getline(arquivo, linha)) {

        if (!linha.empty() && linha.front() == '\"' && linha.back() == '\"') {
            linha = linha.substr(1, linha.length() - 2);
        }

        if (linha == nome_atual) {
            conteudo_atualizado = novo_nome ;
            encontrado = true;
        } else {
            conteudo_atualizado = linha;
        }
    }
    arquivo.close();

    if (!encontrado) {
        std::cout << "Nome atual não encontrado no arquivo." << std::endl;
        return;
    }

    std::ofstream arquivo_atualizado(nome_arquivo, std::ios::trunc);
    if (!arquivo_atualizado) {
        std::cerr << "Erro ao abrir o arquivo " << nome_arquivo << " para escrita." << std::endl;
        return;
    }

    arquivo_atualizado << conteudo_atualizado;
    arquivo_atualizado.close();

    std::cout << "Nome do jogador atualizado com sucesso." << std::endl;
}
