// Proteção para evitar que o arquivo
// seja lido duas vezes pelo compilador
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "tabuleiro.h"
#include "jogador.h"

using namespace std;

// Utilitarios de tela
void limparTela();
void pausar();
void exibirSeparador();

// Menus
void exibirMenuPrincipal();
void exibirComoJogar();
void exibirMenuPausa();
int  lerOpcaoMenu(int min, int max);

// Telas do jogo
void exibirTelaBemVindo();
void exibirTela(Tabuleiro t, Jogador j);
void exibirDicas(Tabuleiro t);
void exibirFimDeJogo(Jogador j);

// Leitura de dados
string lerNomeJogador();
int    lerNumeroPalavra(int totalPalavras);
string lerRespostaPalavra();

#endif
