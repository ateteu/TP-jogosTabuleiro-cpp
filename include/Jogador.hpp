#ifndef Jogador_hpp
#define Jogador_hpp

#include <iostream>
#include <string>

class Jogador{
private:
    /** @brief
     *  Nome do jogador. Este atributo armazena o nome associado ao jogador e é utilizado em várias operações, como identificação e exibição de informações.
     */
    std::string nome_jogador;

    /**
     * @brief Armazena a peça do jogador. 
     *        Pode ser 'W' (branco) ou 'B' (preto) para ambos os jogos.
     */
    char peca;

    /** @brief
     *  Contabiliza o número de vitórias do jogador.
     */
    int vitorias;

    /** @brief
     *  Contabiliza o número de empates do jogador.
     */
    int empates;

    /** @brief
     *  Contabiliza o número de derrotas do jogador.
     */
    int derrotas;

public:
    /** @brief
     *  Construtor padrão da classe Jogador. Inicializa um objeto Jogador com um nome vazio e contadores zerados.
     */
    Jogador();

    /** @brief
     *  Construtor que inicializa um objeto Jogador com um nome específico e contadores de vitórias, empates e derrotas zerados.
     *  @param nome_jogador Nome do jogador.
     */
    Jogador(const std::string& nome_jogador);

    /**
     * @brief Construtor para inicializar a peça do jogador.
     * @param _peca A peça associada ao jogador ('W', 'B', 'X', ou 'O').
     */
    Jogador(char _peca);

    /** @brief
     *  Destrutor da classe Jogador.
     */
    ~Jogador();

    /** @brief
     *  Retorna o nome do jogador.
     *  @return Nome do jogador.
     */
    std::string getNome() const;

    /**
     * @brief Define a peça do jogador.
     * 
     * @param _peca A peça associada ao jogador ('W' ou 'B').
     */
    void setPeca(char _peca);

    /** @brief
     *  Define o nome do jogador.
     *  @param nome Novo nome a ser atribuído ao jogador.
     */
    void setNome(const std::string& nome);

    /**
     * @brief Retorna a peça associada ao jogador.
     * @return A peça do jogador ('W', 'B', 'X', ou 'O').
     */
    char minhaPeca() const;

    /** @brief
     *  Retorna o número de vitórias do jogador.
     *  @return Número de vitórias.
     */
    int getVitorias() const;

    /** @brief
     *  Retorna o número de empates do jogador.
     *  @return Número de empates.
     */
    int getEmpates() const;

    /** @brief
     *  Retorna o número de derrotas do jogador.
     *  @return Número de derrotas.
     */
    int getDerrotas() const;

    /** @brief
     *  Registra uma vitória, incrementando o contador de vitórias.
     */
    void registrarVitoria();

    /** @brief
     *  Registra um empate, incrementando o contador de empates.
     */
    void registrarEmpate();

    /** @brief
     *  Registra uma derrota, incrementando o contador de derrotas.
     */
    void registrarDerrota();

    /** @brief
     *  Imprime o nome do jogador e o número de vitórias, empates e derrotas no console.
     */
    void imprimirJogador() const;
};

#endif // Jogador_hpp
