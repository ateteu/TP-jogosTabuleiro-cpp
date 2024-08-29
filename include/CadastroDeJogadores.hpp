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
#include "../include/Jogador.hpp"

class CadastroDeJogadores {
private:
    /** @brief
         *  Vetor que armazena objetos da classe Jogador, representando a lista de jogadores carregados na memória.
         *  Esse vetor é usado internamente pela classe CadastroDeJogadores para manipular e atualizar os dados dos jogadores,
         *  como adicionar, remover e buscar jogadores no arquivo.
         */
    std::vector<Jogador> jogadores;
    
public:
    /** @brief
     *  Essa função cria um arquivo chamado jogadores.txt se ele não existir. Ela verifica se o arquivo já está presente usando a função std::filesystem::exists.
     *  Se o arquivo existir, uma mensagem informando que ele já existe é exibida. Caso contrário, um novo arquivo é criado.
     *  Se houver algum erro ao criar o arquivo, uma mensagem de erro será exibida.
     */
    void criarArquivoJogadores() const;

    /** @brief
     *  Essa função adiciona um novo jogador ao arquivo jogadores.txt. Ela primeiro garante que o arquivo existe chamando criar_arquivo_jogadores().
     *  Em seguida, carrega todos os jogadores existentes do arquivo para evitar duplicatas.
     *  Se o jogador já estiver presente, uma mensagem será exibida e a função terminará. Se o jogador não existir, ele será adicionado à lista e o arquivo será atualizado para incluir o novo jogador.
     *
     *  @param jogador Objeto do tipo Jogador que será adicionado ao arquivo.
     */
    void adicionarJogadorNoArquivo(const Jogador& jogador);

    /** @brief
     *  Essa função carrega a lista de jogadores a partir do arquivo "jogadores.txt".
     *  Ela abre o arquivo para leitura, limpa a lista atual de jogadores e, em seguida, lê cada nome de jogador do arquivo, adicionando-o à lista de jogadores em memória.
     *  Se o arquivo não puder ser aberto, uma mensagem de erro é exibida.
     *
     *  @param nome_arquivo Nome do arquivo de onde os jogadores serão carregados.
     */
    void carregarJogadoresDeArquivo(const std::string& nome_arquivo);

    /** @brief
     *  Essa função verifica se um jogador específico está presente no arquivo jogadores.txt.
     *  Ela carrega a lista de jogadores e percorre a lista para verificar se o nome do jogador existe.
     *
     *  @param nome Nome do jogador a ser buscado no arquivo.
     *  @retval TRUE Exibe uma mensagem confirmando que o jogador foi encontrado.
     *  @retval FALSE Exibe uma mensagem informando que o jogador não foi encontrado.
     */
    void buscarJogadorNoArquivo();

    /** @brief
     *  Essa função remove um jogador específico do arquivo "jogadores.txt".
     *  Ela carrega a lista de jogadores, procura o jogador com o nome especificado, e se encontrado, o remove da lista.
     *  O arquivo é então atualizado para refletir essa remoção. Se o jogador não for encontrado, uma mensagem informando isso é exibida.
     *
     *  @param nome Nome do jogador a ser removido do arquivo.
     */
    void removerJogadorDoArquivo();

    /** @brief
     *  Essa função lista todos os jogadores presentes no arquivo jogadores.txt.
     *  Ela lê o conteúdo do arquivo linha por linha e exibe cada nome de jogador.
     *  Se o arquivo estiver vazio, uma mensagem informando que a lista está vazia é exibida.
     *  Se o arquivo não puder ser aberto, uma mensagem de erro será exibida.
     */
    void listarJogadoresDoArquivo();

    /** @brief
     *  Essa função atualiza o conteúdo do arquivo jogadores.txt com a lista atual de jogadores.
     *  Ela sobrescreve o arquivo existente, escrevendo cada nome de jogador na lista.
     *  Se o arquivo não puder ser aberto para escrita, uma mensagem de erro será exibida.
     */
    void atualizarArquivo() const;

    /** @brief
     *  Essa função limpa o conteúdo do arquivo "jogadores.txt".
     *  Após limpar o arquivo, ele é atualizado chamando a função atualizar_arquivo().
     *  Se houver um erro ao abrir o arquivo, uma mensagem de erro será exibida.
     */
    void limparArquivo();

    /** @brief
     *  Essa função retorna um ponteiro para um objeto Jogador com base no nome fornecido.
     *  Ela carrega a lista de jogadores do arquivo e procura um jogador com o nome especificado.
     *  Se o jogador for encontrado, um ponteiro para esse jogador é retornado. Caso contrário, um ponteiro nulo é retornado.
     *
     *  @param nome Nome do jogador a ser buscado.
     *  @return Ponteiro para o objeto Jogador encontrado ou nulo se o jogador não for encontrado.
     */
    Jogador* getJogadorPorNome(const std::string& nome);
    
};

#endif // CadastroDeJogadores_hpp
