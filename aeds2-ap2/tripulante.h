//
//  tripulante.h
//  aeds2-ap2
//
//  Created by Gustavo Viegas on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#ifndef tripulante_h
#define tripulante_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct Tripulante* TripulantePointer;
typedef struct Tripulante {
    int codigo;
    char nome[N];
} Tripulante;

void criaTripulante(TripulantePointer tripulante, int codigo, char* nome);
void imprimeTripulante(TripulantePointer tripulante);

#endif /* tripulante_h */
