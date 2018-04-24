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

int calcularHash(char* nome, int* lista) {
    unsigned long int n = strlen(nome);
    int i;
    int k = 0;
    
    for (i = 0; i < n; i++) {
        k += ((int) nome[i]) * lista[i];
    }
    
    return k % M;
}

void inicializarListaHash(TripulantePointer listaHash) {
    int i;
    for (i = 0; i < M; i++) {
        listaHash[i].codigo = -1;
    }
}

int resolverConflito(int hash) {
    return (hash + 1) % M;
}

void inserirHash(TripulantePointer listaHash, int hash, Tripulante tripulante) {
    int i = 0;
    while (listaHash[hash].codigo != -1 && i < M) {
        hash = resolverConflito(hash);
        i++;
    }
    
    listaHash[hash] = tripulante;
}


