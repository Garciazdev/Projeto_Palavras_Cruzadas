#include "../include/menu.h"

using namespace std;

//  Limpa a tela do terminal
void limparTela() {
    system("cls"); 
}

void pausar() {
    cout << "\nPressione Enter para continuar...";

    // Descarta qualquer coisa que sobrou no
    // buffer do teclado
    cin.ignore();

    // Espera o usuario apertar Enter
    cin.get();
}

//  Exibe uma linha separadora
void exibirSeparador() {
    cout << "========================================" << endl;
}

//  Tela de boas vindas
void exibirTelaBemVindo() {
    limparTela();
    exibirSeparador();
    cout << "     BEM VINDO AO PALAVRAS CRUZADAS    " << endl;
    exibirSeparador();
    cout << "  Algoritmos e Logica de Programacao 2  " << endl;
    cout << "  Grupo: [nomes do grupo aqui]          " << endl;
    exibirSeparador();
    pausar();
}

//  Menu principal
void exibirMenuPrincipal() {
    limparTela();
    exibirSeparador();
    cout << "         PALAVRAS CRUZADAS              " << endl;
    exibirSeparador();
    cout << "  1 - Novo Jogo                         " << endl;
    cout << "  2 - Carregar Jogo Salvo               " << endl;
    cout << "  3 - Como Jogar                        " << endl;
    cout << "  0 - Sair                              " << endl;
    exibirSeparador();
    cout << "Escolha uma opcao: ";
}

//  Menu de pausa durante o jogo
void exibirMenuPausa() {
    exibirSeparador();
    cout << "  1 - Tentar uma palavra                " << endl;
    cout << "  2 - Salvar jogo                       " << endl;
    cout << "  0 - Voltar ao menu principal          " << endl;
    exibirSeparador();
    cout << "Escolha uma opcao: ";
}

//  Le e valida a opcao do usuario
int lerOpcaoMenu(int min, int max) {
    int opcao;
    cin >> opcao;

    while (opcao < min || opcao > max) {
        cout << "Opcao invalida! Digite entre " << min << " e " << max << ": ";
        cin >> opcao;
    }

    return opcao;
}

//  Instrucoes de como jogar
void exibirComoJogar() {
    limparTela();
    exibirSeparador();
    cout << "            COMO JOGAR                  " << endl;
    exibirSeparador();
    cout << "  1. Veja as dicas numeradas na tela    " << endl;
    cout << "  2. Digite o numero da palavra         " << endl;
    cout << "  3. Digite sua resposta                " << endl;
    cout << "  4. Se acertar, as letras aparecem!    " << endl;
    cout << "  5. Complete tudo para vencer          " << endl;
    cout << endl;
    cout << "  H = palavra na horizontal             " << endl;
    cout << "  V = palavra na vertical               " << endl;
    exibirSeparador();
    pausar();
}

//  Tela principal durante o jogo
//  Exibe o tabuleiro e o placar do jogador
void exibirTela(Tabuleiro t, Jogador j) {
    limparTela();
    exibirSeparador();
    cout << "         PALAVRAS CRUZADAS              " << endl;
    exibirSeparador();
    cout << "Jogador : " << j.nome << endl;
    cout << "Pontos  : " << j.pontuacao << endl;
    cout << "Acertos : " << j.acertos << " de " << t.totalPalavras << endl;
    exibirSeparador();

    // Chama a funcao da Pessoa 1 para desenhar o tabuleiro
    exibirTabuleiro(t);

    exibirSeparador();
}

//  Exibe todas as dicas numeradas
void exibirDicas(Tabuleiro t) {
    cout << endl;
    cout << "  DICAS:" << endl;
    exibirSeparador();

    for (int i = 0; i < t.totalPalavras; i++) {
        if (t.palavras[i].encontrada) {
            cout << "  [OK] ";
        } else {
            cout << "  [  ] ";
        }

        cout << t.palavras[i].numero << ". ";
        cout << "(" << t.palavras[i].direcao << ") ";
        cout << t.palavras[i].dica << endl;
    }

    exibirSeparador();
}

//  Tela de fim de jogo com pontuacao final
void exibirFimDeJogo(Jogador j) {
    limparTela();
    exibirSeparador();
    cout << "  PARABENS, " << j.nome << "!" << endl;
    cout << "  Voce completou o palavras cruzadas!" << endl;
    exibirSeparador();
    cout << "  Pontuacao final : " << j.pontuacao << endl;
    cout << "  Acertos         : " << j.acertos << endl;
    cout << "  Tentativas      : " << j.tentativas << endl;
    exibirSeparador();

    if (j.pontuacao >= 100) {
        cout << "  Desempenho: EXCELENTE!" << endl;
    } else if (j.pontuacao >= 60) {
        cout << "  Desempenho: BOM!" << endl;
    } else {
        cout << "  Desempenho: PODE MELHORAR!" << endl;
    }

    exibirSeparador();
    pausar();
}

//  Le o nome do jogador
string lerNomeJogador() {
    string nome;
    cout << "Digite seu nome: ";
    cin >> nome;
    return nome;
}

//  Le o numero da palavra que o jogador quer tentar
int lerNumeroPalavra(int totalPalavras) {
    int num;
    cout << "Qual numero de palavra voce quer tentar? (1 a " << totalPalavras << "): ";
    cin >> num;

    while (num < 1 || num > totalPalavras) {
        cout << "Numero invalido! Digite entre 1 e " << totalPalavras << ": ";
        cin >> num;
    }

    return num;
}

//  Le a resposta do jogador e converte para maiusculo
string lerRespostaPalavra() {
    string resposta;
    cout << "Sua resposta: ";
    cin >> resposta;

    for (int i = 0; i < resposta.length(); i++) {
        resposta[i] = toupper(resposta[i]);
    }

    return resposta;
}