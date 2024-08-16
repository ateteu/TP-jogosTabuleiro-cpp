//
//  Jogador.hpp
//  tp
//
//  Created by Ian Godoi on 06/08/24.
//

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

    /** @brief
     * Quantidade de pontos do jogador. Este atributo armazena o total de pontos acumulados pelo jogador ao longo do jogo.
     */
    int ponto;

    /** @brief
     *  Identificador único do jogador. Este atributo pode ser utilizado para identificar de forma única cada jogador em um sistema.
     */
    int id;

public:
    /** @brief
     *  Construtor padrão da classe Jogador. Inicializa um objeto Jogador com um nome vazio e zero pontos.
     */
    Jogador();

    /** @brief
     *  Construtor que inicializa um objeto Jogador com um nome específico e uma quantidade inicial de pontos.
     *  @param nome_jogador Nome do jogador.
     *  @param ponto Quantidade inicial de pontos do jogador.
     */
    Jogador(const std::string& nome_jogador = "", int ponto = 0);

    /** @brief
     *  Destrutor da classe Jogador.
     */
    ~Jogador();

    /** @brief
     *  Retorna o nome do jogador.
     *  @return Nome do jogador.
     */
    std::string get_nome() const;

    /** @brief
     *  Define o nome do jogador.
     *  @param nome Novo nome a ser atribuído ao jogador.
     */
    void set_nome(const std::string& nome);

    /** @brief
     *  Retorna a quantidade de pontos do jogador.
     *  @return Quantidade de pontos do jogador.
     */
    int get_pontos() const;

    /** @brief
     *  Define a quantidade de pontos do jogador.
     *  @param pontos Nova quantidade de pontos a ser atribuída ao jogador.
     */
    void set_pontos(int pontos);

    /** @brief
     *  Imprime o nome e a quantidade de pontos do jogador no console.
     */
    void imprimir_jogador() const;
};

};

#endif // Jogador_hpp
