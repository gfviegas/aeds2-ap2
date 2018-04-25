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
#include "tripulante.h"

void readFile(Tripulante* lista) {
    int codigo;
    int i = 0;
    char nome[N];
    
    FILE *fp;
    fp = fopen("tripulantes.txt", "r");
    
    if (fp != NULL) {
        while (i < M) {
            fscanf(fp, "%d %s", &codigo, nome);
            if (fgetc(fp) == EOF)
                break;
            
            criaTripulante(&(lista[i]), codigo, nome);
            i++;
        }

        fclose(fp);
    } else {
        printf("Erro na leitura do arquivo: ");
        perror("fopen");
    }
}

void digitarTermo(TripulantePointer listaHash, int* lista){
    char termo[N];

    printf("Digite um nome para busca: ");
    scanf("%s", termo);
    Tripulante tripulante = buscaHash(termo, listaHash, lista);
}

int menu(){
    int op = 0;
    while (op != 1 && op != 2 && op != 3)
    {
        printf("-------- Tabelas Hash --------\n\n");
        printf("1 - Imprimir todos os termos\n");
        printf("2 - Buscar por um termo\n");
        printf("3 - Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);
    }
    return op;
}

int main(int argc, const char * argv[]) {
    int lista[N];
    Tripulante listaTripulantes[TOTAL];
    Tripulante listaHash[M];
    int i;
    int hash;

    setarRandomicidade();
    gerarListaRandomica(lista);
    readFile(listaTripulantes);
    inicializarListaHash(listaHash);

    for (i = 0; i < M; i++) {
        inserirHash(listaHash, listaTripulantes[i], lista);
    }

    int op = menu();
    while(op != 3){
        switch (op) {
            case 1:
                exibeTabelaHash(listaHash);
                break;
            case 2:
                digitarTermo(listaHash, lista);
                break;
            case 3:
                exit;
                break;
        }
        op = menu();
    }

    return 0;
}
