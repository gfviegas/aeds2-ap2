//
//  hash.h
//  aeds2-ap2
//
//  Created by Gustavo Viegas on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#ifndef hash_h
#define hash_h

#include "tripulante.h"
#define N 20
#define M 7
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setarRandomicidade();

void gerarListaRandomica(int* lista);
void printaListaRandomica(int* lista);

int calcularHash(TripulantePointer listaHash, char* nome, int* lista);
void inicializarListaHash(TripulantePointer listaHash);
int resolverConflito(int hash);
void inserirHash(TripulantePointer listaHash, Tripulante tripulante, int* lista);
void exibeTabelaHash(TripulantePointer listaHash);
Tripulante buscaHash(char *nome, TripulantePointer listaHash, int *lista);

#endif /* hash_h */
