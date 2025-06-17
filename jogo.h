#ifndef JOGO_H
#define JOGO_H

#include "carta.h"

/**
 * @brief Mostra as instruções e regras do jogo na tela.
 */
void mostrarInstrucoes();

/**
 * @brief Permite ao jogador visualizar os detalhes de todas as cartas.
 * @param baralho O array contendo todas as cartas do jogo.
 * @param tamanho_baralho O número total de cartas no baralho.
 */
void visualizarCartas(const struct Carta baralho[], int tamanho_baralho);

void exibirMenuAtributos(int atributo_excluido);
int compararAtributo(struct Carta c1, struct Carta c2, int atributo);
void iniciarRodada(const struct Carta baralho[], int tamanho_baralho);

#endif // JOGO_H