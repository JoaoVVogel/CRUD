#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "excluir.h"
#include "cadastrar.h"
#include "visualizar.h"
#include "atualizar.h"

struct filmes{
    int id;
    char nome[20];
    int horario;

};

#define MAX_FILMES 10

int main() {
    struct filmes *filme = NULL;
    int op, menuLoop = 0, numeroDeFilmes = 0;

    filme = (struct filmes*)malloc(MAX_FILMES * sizeof(struct filmes));
    do {
        printf("O que deseja realizar:\n");
        printf("1 - Cadastrar filme\n");
        printf("2 - Vizualizar filmes\n");
        printf("3 - Atualizar filme\n");
        printf("4 - Excluir filme\n");
        printf("5 - Emitir ingresso\n");
        printf("0 - Sair\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrar(filme, &numeroDeFilmes, MAX_FILMES);
                break;

            case 2:
                vizualizar(filme, &numeroDeFilmes, MAX_FILMES);
                break;

            case 3:
                atualizar(filme, &numeroDeFilmes, MAX_FILMES);
                break;

            case 4:
                excluir(filme, &numeroDeFilmes, MAX_FILMES);
                break;

            case 5:
                ingresso(filme, &numeroDeFilmes, MAX_FILMES);
                break;

            case 0:
                menuLoop = 1;
                break;;

            default:
                break;
        }

    } while (menuLoop == 0);
    
    printf("Encerrando...");
    free(filme);
    return 0;
}
