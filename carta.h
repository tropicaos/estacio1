#ifndef CARTA_H
#define CARTA_H

/**
 * @brief Define a estrutura de dados para uma carta do Super Trunfo.
 * * Esta struct armazena todos os atributos de uma cidade da Paraíba
 * que serão usados no jogo para comparação.
 */
struct Carta {
    char nome_cidade[50];           // Nome da cidade (ex: "João Pessoa")
    long int populacao;             // População (Censo 2022)
    double area;                    // Área territorial em km²
    double pib;                     // PIB municipal em Milhões de R$ (IBGE 2021)
    double idhm;                    // IDH-M (PNUD 2010)
    int ano_fundacao;               // Ano em que a cidade foi fundada
    
    // Este atributo será calculado no início do jogo
    double densidade_demografica;   // Habitantes por km²
};

#endif // CARTA_H