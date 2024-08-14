//
//  Pontuacao.cpp
//  tp
//
//  Created by Ian Godoi on 08/08/24.
//

#include "Pontuacao.hpp"
#include <fstream>
#include <sstream>

Pontuacao::Pontuacao(const std::string& nome_jogador, int pontos) : nome(nome_jogador), pontos(pontos) {}

Pontuacao::~Pontuacao() {};

void Pontuacao::criarArquivoPontuacao(const std::string& nome_arquivo) const {
    std::ifstream jogadores_arquivo("jogadores.txt");
        if (!jogadores_arquivo) {
        std::cerr << "Erro ao abrir o arquivo jogadores.txt." << std::endl;
        return;
    }

    std::ofstream arquivo_pontuacao(nome_arquivo);
    if (!arquivo_pontuacao) {
    std::cerr << "Erro ao criar o arquivo " << nome_arquivo << "." << std::endl;
    return;
    }

    std::string nome_jogador;
    while (std::getline(jogadores_arquivo, nome_jogador)) {
        arquivo_pontuacao << nome_jogador << " 0\n";
    }

    jogadores_arquivo.close();
    arquivo_pontuacao.close();
}

void Pontuacao::carregarJogadoresdeArquivo(const std::string &nome_arquivo) {
    std::ifstream  arquivo(nome_arquivo);

    if (arquivo.is_open()){
        std:: string  nome;
        int pontos;
        jogadores.clear();

        while(arquivo >> std::quoted(nome) >> pontos){
            jogadores.emplace_back(nome, pontos);
        }
        arquivo.close();

        std::cout << "Jogadores carregados do arquivo: " << nome_arquivo <<"."<< std::endl;
    }else{
        std::cout << "Não foi possível abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
    }
}

void Pontuacao::adicionarPontos(const std::string &nome_arquivo, const std::string &nome_jogador, int pontos_adicionais) {

    carregarJogadoresdeArquivo(nome_arquivo);

    std::ifstream arquivo(nome_arquivo);

    if(!arquivo){
        std::cerr <<"Erro ao abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
        return;
    }

    std::string  conteudo_atualizado;
    std::string  nome_lido;
    int pontos_lidos;
    bool jogador_encontrado = false;

    while (arquivo >> std::quoted(nome_lido) >> pontos_lidos) {
        if (nome_lido == nome_jogador) {
            pontos_lidos += pontos_adicionais;
            jogador_encontrado = true;
        }
        std::stringstream linha_atualizada;
        linha_atualizada << std::quoted(nome_lido) << " " << pontos_lidos;
        conteudo_atualizado += linha_atualizada.str() + "\n";
    }

    arquivo.close();

    std::ofstream arquivo_atualizado(nome_arquivo, std::ios::trunc);
    if (!arquivo_atualizado){
        std::cerr << "Erro ao abrir o arquivo "<< nome_arquivo <<" para atualizar os pontos." <<std::endl;
        return;
    }

    arquivo_atualizado << conteudo_atualizado;
    arquivo_atualizado.close();
    std::cout << "Pontos de jogador "<< nome_jogador << " atualizados com sucesso." << std::endl;


}

void Pontuacao::listarArquivoPontuacao(const std::string &nome_arquivo) const {
    std::ifstream arquivo(nome_arquivo);

    if(!arquivo){
        std::cerr <<"Erro ao abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
        return;
    }

    std::string  linha;
    bool lista_vazia = true;

    std::cout << "Lista de jogadores: " << std::endl;

    while(std::getline(arquivo, linha)){
        if (!linha.empty()){
            if (linha.front() == '\"' && linha.back() =='\"'){
                linha = linha.substr(1, linha.length() -2);
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

void Pontuacao::zerarPontos(const std::string &nome_arquivo, const std::string &nome_jogador) {
    carregarJogadoresdeArquivo(nome_arquivo);

    std::ifstream arquivo(nome_arquivo);

    if(!arquivo){
        std::cerr <<"Erro ao abrir o arquivo "<< nome_arquivo <<"."<< std::endl;
        return;
    }

    std::string  conteudo_atualizado;
    std::string  nome_lido;
    int pontos_lidos;
    bool jogador_encontrado = false;

    while (arquivo >> std::quoted(nome_lido) >> pontos_lidos) {
        if (nome_lido == nome_jogador) {
            pontos_lidos = 0;
            jogador_encontrado = true;
        }
        std::stringstream linha_atualizada;
        linha_atualizada << std::quoted(nome_lido) << " " << pontos_lidos;
        conteudo_atualizado += linha_atualizada.str() + "\n";
    }

    arquivo.close();

    std::ofstream arquivo_atualizado(nome_arquivo, std::ios::trunc);
    if (!arquivo_atualizado){
        std::cerr << "Erro ao abrir o arquivo "<< nome_arquivo <<" para atualizar os pontos." <<std::endl;
        return;
    }

    arquivo_atualizado << conteudo_atualizado;
    arquivo_atualizado.close();
    std::cout << "Pontos de jogador "<< nome_jogador << " atualizados com sucesso." << std::endl;

}