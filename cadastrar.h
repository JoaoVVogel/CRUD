#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Filmes{
    int id;
    char nome[20];
    int horario;

};

int cadastrar(struct Filmes *filme, int *numeroDeFilmes, int MAX_FILMES) {
    int id;
    char nome[20];
    int horario;

    if (*numeroDeFilmes < MAX_FILMES) {
        printf("Digite o ID desejado: ");
        scanf("%i", &id);

        for (int i = 0; i < *numeroDeFilmes; i++) {
            if (filme[i].id == id) {
                printf("O ID já está sendo usado para outro filme!\n");
                return 0;
            }
        }

        printf("\nDigite o nome do filme:\n");
        scanf("%s", nome);

        printf("Digite a hora de início do filme (hhmm): \n");
        scanf("%i", &horario);

        if (horario > 2400 || horario < 0) {
            printf("Horario inválido!\n");
            return 0;
        }

        filme[*numeroDeFilmes].id = id;
        strcpy(filme[*numeroDeFilmes].nome, nome);
        filme[*numeroDeFilmes].horario = horario;
        (*numeroDeFilmes)++;

        printf("Filme adicionado com sucesso!\n");
    }
    return 1;
}