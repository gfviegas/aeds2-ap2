//
//  hash.c
//  aeds2-ap2
//
//  Created by Gustavo Viegas on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "hash.h"

// Define o fator randômico para o programa poder gerar números aleátorios
void setRandomFactor() {
    srand(time(NULL));
}

// Gera uma lista de tamanho N com inteiros aleatórios
void generateRandomList(int* list) {
    int i;
    
    for (i = 0; i < N; i++) {
        list[i] = (rand() % (N + 1));
    }
}

// Imprime uma lista de números randômicos
void printRandomList(int* list) {
    int i;
    
    for (i = 0; i < N; i++) {
        printf("\tLista posição %d => %d \n", i, list[i]);
    }
}

// Resolve um conflito de hash, identificando o próximo hash disponível linearmente
int solveConflict(int hash) {
    return (hash + 1) % M;
}

// Calcula o hash de um tripulante
int calculateHash(Crew *hashList, char *name, int* list) {
    unsigned long int n = strlen(name);
    int i;
    int k = 0;

    for (i = 0; i < n; i++) {
        k += ((int) name[i]) * list[i];
    }

    int hash = k % M;
    i = 0;

    while (hashList[hash].code != -1 && i < M) {
        hash = solveConflict(hash);
        i++;
    }

    return hash;
}

// Inicializa uma lista hash
void initHashList(CrewPointer hashList) {
    int i;
    for (i = 0; i < M; i++) {
        hashList[i].code = -1;
    }
}

// Insere um tripulante a lista de hash
void insertHash(CrewPointer hashList, Crew crew, int * list) {
    int hash = calculateHash(hashList, crew.name, list);

    if(hash != -1)
        hashList[hash] = crew;
}

// Imprime uma lista hash com seus tripulantes
void printHashList(CrewPointer hashList){
    int i = 0;
    for (i = 0; i < M;i++)
        printCrew(&hashList[i]);
    printf("\n");
}

// Pesquisa na lista hash a ocorrência de um nome
Crew searchHash(char *name, CrewPointer hashList, int *list){
    int hash = calculateHash(hashList, name, list);
    if(strcmp(hashList[hash].name, name) != 0){
        printf("Registro nao encontrado\n");
        return *hashList;
    }
    printCrew(&hashList[hash]);
    return hashList[hash];
}
