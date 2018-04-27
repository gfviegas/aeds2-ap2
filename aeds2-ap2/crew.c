//
//  crew.c
//  aeds2-ap2
//
//  Created by Bruno Marra (3029), Gustavo Viegas (3026) e Heitor Passeado (3055) on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "crew.h"

// Inicializa os valores de um tripulante, atribuindo os valores do parâmetro ao tripulante referenciado
void createCrew(CrewPointer crew, int code, char* name) {
    crew->code = code;
    strcpy(crew->name, name);
}

// Imprime os dados de um tripulante
void printCrew(CrewPointer crew) {
    printf("Tripulante #%d -> %s\n", crew->code, crew->name);
}

