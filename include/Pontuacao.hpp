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
    /** @brief
     *  Vetor de objetos "Jogador" que armazena a lista de jogadores e suas respectivas pontuações. Este vetor é utilizado para manipular os dados dos jogadores em memória antes de gravá-los ou lê-los de um arquivo.
     */
    std::vector<Jogador> jogadores;

    /** @brief
     *  Nome associado à pontuação. Este atributo armazena o nome do jogador cujas pontuações estão sendo manipuladas ou exibidas.
     */
    std::string nome;

    /** @brief
     *  Quantidade de pontos acumulados por um jogador. Este atributo é utilizado para armazenar e manipular os pontos de um jogador específico.
     */
    int pontos;

public:
    /** @brief
     *  Construtor da classe Pontuacao, que inicializa um objeto Pontuacao com um nome de jogador e uma pontuação inicial.
     *  @param nome_jogador Nome do jogador.
     *  @param pontos Quantidade inicial de pontos do jogador. O valor padrão é zero.
     */
    Pontuacao(const std::string& nome_jogador, int pontos = 0);

    /** @brief
     *  Destrutor da classe Pontuacao.
     */
    ~Pontuacao();

    /** @brief
     *  Adiciona uma quantidade especificada de pontos ao jogador indicado.
     *  @param nome_arquivo Nome do arquivo de pontuação.
     *  @param nome_jogador Nome do jogador ao qual os pontos serão adicionados.
     *  @param pontos_adicionais Quantidade de pontos a ser adicionada ao jogador.
     */
    void adicionarPontos(const std::string& nome_arquivo, const std::string& nome_jogador, int pontos_adicionais);

    /** @brief
     *  Redefine a pontuação de um jogador específico para zero.
     *  @param nome_arquivo Nome do arquivo de pontuação.
     *  @param nome_jogador Nome do jogador cuja pontuação será zerada.
     */
    void zerarPontos(const std::string& nome_arquivo, const std::string& nome_jogador);

    /** @brief
     *  Cria um arquivo de pontuação com o nome especificado e inicializa as pontuações dos jogadores como zero.
     *  @param nome_arquivo Nome do arquivo de pontuação a ser criado.
     */
    void criarArquivoPontuacao(const std::string& nome_arquivo) const;

    /** @brief
     *  Lista todos os jogadores e suas pontuações armazenadas no arquivo de pontuação especificado.
     *  @param nome_arquivo Nome do arquivo de pontuação a ser lido.
     */
    void listarArquivoPontuacao(const std::string& nome_arquivo) const;

    /** @brief
     *  Carrega a lista de jogadores e seus respectivos pontos a partir de um arquivo especificado.
     *  @param nome_arquivo Nome do arquivo de pontuação a ser carregado.
     */
    void carregarJogadoresdeArquivo(const std::string& nome_arquivo);
};

#endif /* Pontuacao_hpp */
