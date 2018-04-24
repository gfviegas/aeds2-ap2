//
//  main.c
//  aeds2-ap2
//
//  Created by Gustavo Viegas on 24/04/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include <stdio.h>
#include "hash.h"
#include "tripulante.h"

void readFile(Tripulante* lista) {
    int codigo;
    int i = 0;
    char nome[N];
    
    FILE *fp;
    fp = fopen("/Users/Gustavo/Projects/aeds2/aeds2-ap2/aeds2-ap2/tripulantes.txt", "r");
    
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

int main(int argc, const char * argv[]) {
    int lista[N];
    Tripulante listaTripulantes[200];
    Tripulante listaHash[M];
    int i;
    int hash;
    
    setarRandomicidade();
    
    gerarListaRandomica(lista);
    readFile(listaTripulantes);
    
    char palavra[20];
    strcpy(palavra, "Marretinha");
    // printaListaRandomica(lista);
    printf("%d %d %d!\n", lista[0], lista[N - 1], lista[1]);
    printf("Hash de Marretinha: %d\n", calcularHash(palavra, lista));
    
    for (i = 0; i < M; i++) {
        hash = calcularHash(listaTripulantes[i].nome, lista);
        inserirHash(listaHash, hash, listaTripulantes[i]);
    }

    hash = calcularHash("Janella", lista);
    printf("");
    
    return 0;
}
