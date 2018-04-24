//
//  tripulante.c
//  aeds2-ap2
//
//  Created by Gustavo Viegas on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "tripulante.h"

void criaTripulante(TripulantePointer tripulante, int codigo, char* nome) {
    tripulante->codigo = codigo;
    strcpy(tripulante->nome, nome);
}

void imprimeTripulante(TripulantePointer tripulante) {
    printf("Tripulante #%d -> %s\n", tripulante->codigo, tripulante->nome);
}
