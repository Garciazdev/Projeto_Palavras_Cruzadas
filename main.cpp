#include <iostream>
#include "include/menu.h"
#include "include/tabuleiro.h"
#include "include/jogador.h"
#include "include/jogo.h"
#include "include/arquivo.h"

using namespace std;

string ARQUIVO_PALAVRAS  = "palavras.txt";
string ARQUIVO_PROGRESSO = "progresso.txt";

//  Fluxo de um novo jogo
void novoJogo() {
    Tabuleiro tabuleiro;
    Jogador jogador;

    // Carrega as palavras do arquivo (Pessoa 4)
    //  O ! na frente de carregarPalavras significa
    //  "se NÃO conseguiu carregar"
    if (!carregarPalavras(ARQUIVO_PALAVRAS, tabuleiro)) {
        cout << "ERRO: Nao foi possivel carregar o arquivo de palavras." << endl;
        cout << "Verifique se o arquivo palavras.txt existe." << endl;
        pausar();
        return;
    }

    // Le o nome e inicializa o jogador (Pessoa 2)
    string nome = lerNomeJogador();
    inicializarJogador(jogador, nome);

    // Loop principal do jogo
    int opcao = -1;
    while (opcao != 0) {

        // Exibe tabuleiro, placar e dicas
        exibirTela(tabuleiro, jogador);
        exibirDicas(tabuleiro);

        // Verifica se o jogo acabou (Pessoa 2)
        if (jogoTerminou(tabuleiro)) {
            exibirFimDeJogo(jogador);
            return;
        }

        // Menu de opcoes do turno
        exibirMenuPausa();
        opcao = lerOpcaoMenu(0, 2);

        if (opcao == 1) {
            // Jogador tenta uma palavra
            int numPalavra = lerNumeroPalavra(tabuleiro.totalPalavras);
            string resposta = lerRespostaPalavra();

            // Verifica se acertou (Pessoa 2)
            bool acertou = tentarResposta(tabuleiro, jogador, numPalavra, resposta);

            if (acertou) {
                revelarPalavra(tabuleiro, numPalavra); // Pessoa 1
                cout << "CORRETO! Muito bem, " << jogador.nome << "!" << endl;
            } else {
                cout << "Resposta errada. Tente novamente!" << endl;
            }
            pausar();

        } else if (opcao == 2) {
            // Salva o progresso (Pessoa 4)
            if (salvarProgresso(ARQUIVO_PROGRESSO, tabuleiro, jogador)) {
                cout << "Jogo salvo com sucesso!" << endl;
            } else {
                cout << "ERRO ao salvar o jogo." << endl;
            }
            pausar();
        }
    }
}

//  Fluxo de carregar jogo salvo
void carregarJogo() {
    Tabuleiro tabuleiro;
    Jogador jogador;

    // Carrega o progresso salvo (Pessoa 4)
    if (!carregarProgresso(ARQUIVO_PROGRESSO, tabuleiro, jogador)) {
        cout << "Nenhum jogo salvo encontrado." << endl;
        pausar();
        return;
    }

    cout << "Jogo de " << jogador.nome << " carregado com sucesso!" << endl;
    pausar();

    // TODO: continuar o jogo a partir do estado carregado
}

//  Ponto de entrada
int main() {
    exibirTelaBemVindo();

    int opcao = -1;
    while (opcao != 0) {
        exibirMenuPrincipal();
        opcao = lerOpcaoMenu(0, 3);

        if (opcao == 1) {
            novoJogo();
        } else if (opcao == 2) {
            carregarJogo();
        } else if (opcao == 3) {
            exibirComoJogar();
        }
    }

    limparTela();
    cout << "Ate a proxima! Obrigado por jogar." << endl;

    return 0;
}