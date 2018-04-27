//
//  hash.h
//  aeds2-ap2
//
//  Created by Bruno Marra (3029), Gustavo Viegas (3026) e Heitor Passeado (3055) on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#ifndef hash_h
#define hash_h

#define N 20
#define M 7
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crew.h"

/**
 *  Define o fator randômico para o programa poder gerar números aleátorios
 */
void setRandomFactor(void);

/**
 *  Gera uma lista de tamanho N com inteiros aleatórios
 *
 *  @param  list            Ponteiro para a lista a ser manipulada
 */
void generateRandomList(int* list);


/**
 Imprime uma lista de números randômicos

 @param list Ponteiro para a lista a ser impressa
 */
void printRandomList(int* list);


/**
 Calcula o hash de um tripulante

 @param hashList Lista Hash usada para detectar conflitos
 @param name Nome do tripulante
 @param list Lista de números randômicos
 @return Valor do Hash disponível calculado
 */
int calculateHash(CrewPointer hashList, char* name, int* list);


/**
 Inicializa uma lista hash

 @param hashList Ponteiro para a lista de hash que será manipulada
 */
void initHashList(CrewPointer hashList);


/**
 Resolve um conflito de hash, identificando o próximo hash disponível linearmente

 @param hash Valor de um hash conflitado, para ser recalculado
 @return Novo valor do hash, recalculado
 */
int solveConflict(int hash);


/**
 Insere um tripulante a lista de hash

 @param hashList Ponteiro para Lista Hash a ser manipulada
 @param crew Tripulante a ser inserido
 @param list Lista de números aleátorios para calcular o hash
 */
void insertHash(CrewPointer hashList, Crew crew, int* list);


/**
 Imprime uma lista hash com seus tripulantes

 @param hashList Ponteiro para Lista Hash a ser impressa
 */
void printHashList(CrewPointer hashList);


/**
 Pesquisa na lista hash a ocorrência de um nome

 @param name Nome a ser buscado a ocorrência
 @param hashList Lista Hash dos tripulantes a ser buscado
 @param list Lista de numeros aleátorios utilizada pra calcular o hash
 @return Tripulante encontrado, se encontrado. Se não encontrado, o primeiro registro é retornado
 */
Crew searchHash(char *name, CrewPointer hashList, int *list);

#endif /* hash_h */
