//
// Created by Ian Godoi on 28/08/24.
//

#ifndef TP_JOGOSTABULEIRO_CPP_SCORE_HPP
#define TP_JOGOSTABULEIRO_CPP_SCORE_HPP

#include <string>
#include <unordered_map>
#include <fstream>

class Score {
public:
    /**
     * @brief Construtor padrão da classe Score.
     * 
     * Inicializa o objeto Score e carrega as estatísticas do arquivo de score.
     */
    Score();

    /**
     * @brief Adiciona vitórias ao jogador em um determinado jogo.
     * 
     * @param jogador Nome do jogador.
     * @param jogo Nome do jogo.
     * @param quantidade Quantidade de vitórias a ser adicionada.
     */
    void adicionarVitorias(const std::string& jogador, const std::string& jogo, int quantidade);

    /**
     * @brief Adiciona derrotas ao jogador em um determinado jogo.
     * 
     * @param jogador Nome do jogador.
     * @param jogo Nome do jogo.
     * @param quantidade Quantidade de derrotas a ser adicionada.
     */
    void adicionarDerrotas(const std::string& jogador, const std::string& jogo, int quantidade);

    /**
     * @brief Adiciona empates ao jogador em um determinado jogo.
     * 
     * @param jogador Nome do jogador.
     * @param jogo Nome do jogo.
     * @param quantidade Quantidade de empates a ser adicionada.
     */
    void adicionarEmpates(const std::string& jogador, const std::string& jogo, int quantidade);

    /**
     * @brief Imprime as estatísticas de um jogador específico.
     * 
     * @param nome Nome do jogador cujas estatísticas serão exibidas.
     */
    void imprimirEstatisticasPorNome(const std::string& nome) const;

    /**
     * @brief Imprime a lista completa de scores.
     */
    void imprimirListadeScore();

    /**
     * @brief Imprime as estatísticas de um jogador específico em um determinado jogo.
     * 
     * @param jogador Nome do jogador.
     * @param jogo Nome do jogo.
     */
    void imprimirEstatisticasPorNomeEJogo(const std::string& jogador, const std::string& jogo);

    /**
     * @brief Limpa o score de um jogador específico.
     * 
     * @param nomeJogador Nome do jogador cujo score será limpo.
     */
    void limparScore(const std::string& nomeJogador);

    /**
     * @brief Carrega as estatísticas de um arquivo de score.
     */
    void carregar();

    /**
     * @brief Inicializa as estatísticas de um jogador.
     * 
     * @param jogador Nome do jogador cujas estatísticas serão inicializadas.
     */
    void inicializarEstatisticas(const std::string& jogador);

private:
    /**
     * @brief Mapa que armazena as estatísticas de cada jogador.
     * 
     * A chave é o nome do jogador, e o valor é outro mapa que contém as estatísticas de vitórias, derrotas e empates por jogo.
     */
    std::unordered_map<std::string, std::unordered_map<std::string, int>> estatisticas;

    /**
     * @brief Nome do arquivo que armazena as estatísticas.
     */
    std::string arquivo = "score.txt";

    /**
     * @brief Atualiza o arquivo de score com as estatísticas atuais.
     */
    void atualizarArquivo();
};

#endif //TP_JOGOSTABULEIRO_CPP_SCORE_HPP