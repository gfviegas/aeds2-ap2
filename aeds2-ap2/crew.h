//
//  crew.h
//  aeds2-ap2
//
//  Created by Bruno Marra (3029), Gustavo Viegas (3026) e Heitor Passeado (3055) on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#ifndef crew_h
#define crew_h

#define N 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Crew* CrewPointer;
typedef struct Crew {
    int code;
    char name[N];
} Crew;


/**
 Inicializa os valores de um tripulante, atribuindo os valores do parâmetro ao tripulante referenciado
 
 @param  crew            Ponteiro para o tripulante que será manipulado
 @param  code            Valor inteiro do código do tripulante
 @param  name            String com o nome do tripulante
 */
void createCrew(CrewPointer crew, int code, char* name);

/**
 Imprime os dados de um tripulante
 
 @param  crew            Ponteiro para o tripulante que será impresso
 */
void printCrew(CrewPointer crew);

#endif /* crew_h */

