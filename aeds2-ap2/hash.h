//
//  hash.h
//  aeds2-ap2
//
//  Created by Gustavo Viegas on 24/04/18.
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
#include "tripulante.h"

void setarRandomicidade();

void gerarListaRandomica(int* lista);
void printaListaRandomica(int* lista);

int calcularHash(char* nome, int* lista);
void inicializarListaHash(TripulantePointer listaHash);
int resolverConflito(int hash);
void inserirHash(TripulantePointer listaHash, int hash, Tripulante tripulante);

#endif /* hash_h */
