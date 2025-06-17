#include <stdio.h>      // Para printf, scanf, getchar
#include "carta.h"      // Para que este arquivo saiba o que é uma "struct Carta"
#include "jogo.h"       // Para as declarações das nossas próprias funções


void mostrarInstrucoes() {
    printf("\n=============================================\n");
    printf("                  COMO JOGAR                   \n");
    printf("=============================================\n");
    printf("Super Trunfo da Paraíba é um jogo de batalha de cartas.\n\n");
    printf("1. No menu 'Duelo!', você escolherá duas cidades para batalhar.\n");
    printf("2. Em seguida, você escolherá DOIS atributos diferentes para comparar.\n");
    printf("3. A carta que tiver o melhor valor em um atributo ganha 1 ponto.\n");
    printf("4. A carta com mais pontos no final da rodada é a vencedora!\n\n");
    printf("REGRAS ESPECIAIS:\n");
    printf(" -> Para 'Ano de Fundação' e 'Densidade Demográfica', o MENOR valor vence!\n");
    printf(" -> Para todos os outros atributos, o MAIOR valor vence.\n\n");
    printf("Use o menu 'Cartas' para estudar os pontos fortes e fracos de cada cidade!\n");
    printf("=============================================\n");
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar(); // Limpa o buffer de entrada residual
    getchar(); // Espera o jogador pressionar Enter para continuar
}

void visualizarCartas(const struct Carta baralho[], int tamanho_baralho) {
    int escolha = -1;
    do {
        printf("\n=============================================\n");
        printf("              GALERIA DE CARTAS                \n");
        printf("=============================================\n");
        for (int i = 0; i < tamanho_baralho; i++) {
            printf("%d. %s\n", i + 1, baralho[i].nome_cidade);
        }
        printf("---------------------------------------------\n");
        printf("Digite o número da carta para ver os detalhes (ou 0 para voltar): ");
        scanf("%d", &escolha);

        if (escolha >= 1 && escolha <= tamanho_baralho) {
            int indice = escolha - 1;
            printf("\n---------- DETALHES DA CARTA ----------\n");
            printf(" NOME: %s\n", baralho[indice].nome_cidade);
            printf(" POPULAÇÃO: %ld\n", baralho[indice].populacao);
            printf(" ÁREA: %.2f km²\n", baralho[indice].area);
            printf(" PIB: R$ %.2f Milhões\n", baralho[indice].pib);
            printf(" IDH-M: %.3f\n", baralho[indice].idhm);
            printf(" FUNDAÇÃO: %d\n", baralho[indice].ano_fundacao);
            printf(" DENSIDADE: %.2f hab/km²\n", baralho[indice].densidade_demografica);
            printf("---------------------------------------\n");
            printf("\nPressione Enter para continuar...");
            getchar();
            getchar();
        } else if (escolha != 0) {
            printf("\nOpção inválida! Tente novamente.\n");
            getchar();
            getchar();
        }
    } while (escolha != 0);
}


void exibirMenuAtributos(int atributo_excluido) {
    printf("\nEscolha o atributo para a batalha:\n");
    if (atributo_excluido != 1) { printf("1. População\n"); }
    if (atributo_excluido != 2) { printf("2. Área\n"); }
    if (atributo_excluido != 3) { printf("3. PIB\n"); }
    if (atributo_excluido != 4) { printf("4. IDH-M\n"); }
    if (atributo_excluido != 5) { printf("5. Ano de Fundação (menor vence)\n"); }
    if (atributo_excluido != 6) { printf("6. Densidade Demográfica (menor vence)\n"); }
}

int compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    double valor1, valor2;
    int menor_vence = 0;
    switch (atributo) {
        case 1: valor1 = c1.populacao; valor2 = c2.populacao; break;
        case 2: valor1 = c1.area; valor2 = c2.area; break;
        case 3: valor1 = c1.pib; valor2 = c2.pib; break;
        case 4: valor1 = c1.idhm; valor2 = c2.idhm; break;
        case 5: valor1 = c1.ano_fundacao; valor2 = c2.ano_fundacao; menor_vence = 1; break;
        case 6: valor1 = c1.densidade_demografica; valor2 = c2.densidade_demografica; menor_vence = 1; break;
        default: return 0;
    }
    if (menor_vence) {
        return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
    } else {
        return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
    }
}

void iniciarRodada(const struct Carta baralho[], int tamanho_baralho) {
    int i;
    int escolha_carta1 = 0, escolha_carta2 = 0;
    int escolha_attr1 = 0, escolha_attr2 = 0;
    
    printf("\n=============================================\n");
    printf("        SELECIONE DUAS CARTAS PARA O DUELO!       \n");
    printf("=============================================\n\n");
    for (i = 0; i < tamanho_baralho; i++) { printf("%d. %s\n", i + 1, baralho[i].nome_cidade); }
    printf("\n");
    while (escolha_carta1 < 1 || escolha_carta1 > tamanho_baralho) {
        printf("Escolha a primeira carta (1 a %d): ", tamanho_baralho);
        scanf("%d", &escolha_carta1);
    }
    while (escolha_carta2 < 1 || escolha_carta2 > tamanho_baralho || escolha_carta2 == escolha_carta1) {
        printf("Escolha a segunda carta (1 a %d, diferente da primeira): ", tamanho_baralho);
        scanf("%d", &escolha_carta2);
    }

    int indice_carta1 = escolha_carta1 - 1;
    int indice_carta2 = escolha_carta2 - 1;
    struct Carta carta_jogador1 = baralho[indice_carta1];
    struct Carta carta_jogador2 = baralho[indice_carta2];
    
    printf("\n---------------------------------------------\n");
    printf("Duelo: %s vs. %s\n", carta_jogador1.nome_cidade, carta_jogador2.nome_cidade);
    printf("---------------------------------------------\n");
    
    while (escolha_attr1 < 1 || escolha_attr1 > 6) {
        exibirMenuAtributos(0);
        printf("Escolha o PRIMEIRO atributo: ");
        scanf("%d", &escolha_attr1);
    }
    while (escolha_attr2 < 1 || escolha_attr2 > 6 || escolha_attr2 == escolha_attr1) {
        exibirMenuAtributos(escolha_attr1);
        printf("Escolha o SEGUNDO atributo (diferente do primeiro): ");
        scanf("%d", &escolha_attr2);
    }
    
    int pontos_c1 = 0;
    int pontos_c2 = 0;
    
    printf("\n=============================================\n");
    printf("                   RESULTADO                   \n");
    printf("=============================================\n");
    
    int resultado1 = compararAtributo(carta_jogador1, carta_jogador2, escolha_attr1);
    if (resultado1 == 1) {
        pontos_c1++;
        printf("-> Ponto no Atributo 1 para: %s\n", carta_jogador1.nome_cidade);
    } else if (resultado1 == 2) {
        pontos_c2++;
        printf("-> Ponto no Atributo 1 para: %s\n", carta_jogador2.nome_cidade);
    } else {
        printf("-> Empate no Atributo 1!\n");
    }
    
    int resultado2 = compararAtributo(carta_jogador1, carta_jogador2, escolha_attr2);
    if (resultado2 == 1) {
        pontos_c1++;
        printf("-> Ponto no Atributo 2 para: %s\n", carta_jogador1.nome_cidade);
    } else if (resultado2 == 2) {
        pontos_c2++;
        printf("-> Ponto no Atributo 2 para: %s\n", carta_jogador2.nome_cidade);
    } else {
        printf("-> Empate no Atributo 2!\n");
    }
    
    printf("\n--- PLACAR FINAL ---\n");
    printf("%s: %d Ponto(s)\n", carta_jogador1.nome_cidade, pontos_c1);
    printf("%s: %d Ponto(s)\n\n", carta_jogador2.nome_cidade, pontos_c2);
    
    if (pontos_c1 > pontos_c2) {
        printf("🏆 O GRANDE VENCEDOR É: %s!\n", carta_jogador1.nome_cidade);
    } else if (pontos_c2 > pontos_c1) {
        printf("🏆 O GRANDE VENCEDOR É: %s!\n", carta_jogador2.nome_cidade);
    } else {
        printf("🎌 A BATALHA TERMINOU EM EMPATE!\n");
    }
    printf("=============================================\n");
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
    getchar();
}