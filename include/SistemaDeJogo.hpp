#ifndef SISTEMA_DE_JOGO_HPP
#define SISTEMA_DE_JOGO_HPP

#include "CadastroDeJogadores.hpp"
#include "Jogador.hpp"
#include "Jogo.hpp" //precisa criar a classe, ela não existe ainda

class SistemaDeJogo {
private:
    CadastroDeJogadores cadastro;
    Jogo jogo;

public:
    SistemaDeJogo();

    void inicializar();
    void executarPartida();
    void registrarVitoria(Jogador& vencedor);
    void registrarDerrota(Jogador& perdedor);
    void registrarEmpate(Jogador& jogador1, Jogador& jogador2); 
    void listarJogadores();
};

#endif
