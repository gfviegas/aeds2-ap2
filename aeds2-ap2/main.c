//
//  main.c
//  aeds2-ap2
//
//  Created by Gustavo Viegas on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#define N 20
#define TOTAL 200
#include <stdio.h>
#include "hash.h"
#include "crew.h"

/**
 Imprime um cabeçalho com instruções e descrição do programa
 */
void printHeader () {
    printf("|| ||\n");
    printf("|| ||\t HashFlight 1.0\n");
    printf("|| ||\t Atividade Prática 2 de \"Algoritmos e Estruturas de Dados\" II \n");
    printf("|| ||\t Abril de 2018 - UFV Campus Florestal\n");
    printf("|| ||\t Bruno Marra (3029), Gustavo Viegas (3026) e Heitor Passeado (3055)\n");
    printf("|| ||\n");
    printf("\nO programa irá pedir pra que você digite um código após cada operação executada. Basta digitar o código requisitado pra a operação ser executada. \n\n");
}

/**
 Lê o arquivo de entrada e insere na list de crews.
 */
void readFile(Crew* list) {
    int code;
    int i = 0;
    char name[N];
    
    FILE *fp;
    fp = fopen("/Users/Gustavo/Projects/aeds2/aeds2-ap2/aeds2-ap2/list.txt", "r");
    
    if (fp != NULL) {
        while (i < M) {
            fscanf(fp, "%d %s", &code, name);
            if (fgetc(fp) == EOF)
                break;
            
            createCrew(&(list[i]), code, name);
            i++;
        }

        fclose(fp);
    } else {
        printf("Erro na leitura do arquivo: ");
        perror("fopen");
    }
}

/**
 Pesquisa por um tripulante na lista hash
 */
void searchCrew(CrewPointer hashList, int* list){
    char query[N];

    printf("Digite um nome para busca: ");
    scanf("%s", query);
    searchHash(query, hashList, list);
}


/**
 Imprime instruções de códigos a serem inseridos para o programa executar

 @return codigo da operação escolhida pelo usuário
 */
int menu () {
    int op = 0;
    while (op != 1 && op != 2 && op != 3)
    {
        printf("\n-------- Tabelas Hash - Comandos --------\n\n");
        printf("1 - Imprimir todos os termos\n");
        printf("2 - Buscar por um termo\n");
        printf("3 - Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);
    }
    return op;
}

int main(int argc, const char * argv[]) {
    int list[N];
    Crew listCrews[TOTAL];
    Crew hashList[M];
    int i;

    setRandomFactor();
    generateRandomList(list);
    printHeader();
    readFile(listCrews);
    initHashList(hashList);

    for (i = 0; i < M; i++) {
        insertHash(hashList, listCrews[i], list);
    }

    int op = menu();
    while (op != 3) {
        switch (op) {
            case 1:
                printHashList(hashList);
                break;
            case 2:
                searchCrew(hashList, list);
                break;
            case 3:
                return 0;
        }

        op = menu();
    }

    return 0;
}
