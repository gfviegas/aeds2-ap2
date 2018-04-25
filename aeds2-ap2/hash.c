//
//  hash.c
//  aeds2-ap2
//
//  Created by Gustavo Viegas on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "hash.h"

void setarRandomicidade() {
    srand(time(NULL));
}

void gerarListaRandomica(int* lista) {
    int i;
    
    for (i = 0; i < N; i++) {
        lista[i] = (rand() % (N + 1));
    }
}
void printaListaRandomica(int* lista) {
    int i;
    
    for (i = 0; i < N; i++) {
        printf("\tLista posição %d => %d \n", i, lista[i]);
    }
}

int resolverConflito(int hash) {
    return (hash + 1) % M;
}

int calcularHash(Tripulante *listaHash, char *nome, int* lista) {
    unsigned long int n = strlen(nome);
    int i;
    int k = 0;

    for (i = 0; i < n; i++) {
        k += ((int) nome[i]) * lista[i];
    }

    int hash = k % M;
    i = 0;

    while (listaHash[hash].codigo != -1 && i < M) {
        hash = resolverConflito(hash);
        i++;
    }

    // if(i >= M){
    //     printf("Tabela cheia!\n");
    //     return -1;
    // }

    return hash;
}

void inicializarListaHash(TripulantePointer listaHash) {
    int i;
    for (i = 0; i < M; i++) {
        listaHash[i].codigo = -1;
    }
}

void inserirHash(TripulantePointer listaHash, Tripulante tripulante, int * lista) {
    int hash = calcularHash(listaHash, tripulante.nome, lista);

    if(hash != -1)
        listaHash[hash] = tripulante;
}

void exibeTabelaHash(TripulantePointer listaHash){
    int i = 0;
    for (i = 0; i < M;i++)
        imprimeTripulante(&listaHash[i]);
    printf("\n");
}

Tripulante buscaHash(char *nome, TripulantePointer listaHash, int *lista){
    int hash = calcularHash(listaHash, nome, lista);
    if(strcmp(listaHash[hash].nome, nome) != 0){
        printf("Registro nao encontrado\n");
        return;
    }
    imprimeTripulante(&listaHash[hash]);
    return listaHash[hash];
}