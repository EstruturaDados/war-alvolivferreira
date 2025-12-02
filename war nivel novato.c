#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

int main() {
    Territorio mapa[5];

    printf("=== Cadastro dos Territorios ===\n");

    for(int i = 0; i < 5; i++) {
        printf("\nTerritorio %d\n", i + 1);

        printf("Nome: ");
        fgets(mapa[i].nome, 50, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Cor do exercito: ");
        fgets(mapa[i].cor, 20, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar(); // limpa o ENTER do buffer
    }

    printf("\n=== MAPA ATUAL ===\n");
    for(int i = 0; i < 5; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Exercito: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }

    return 0;
}
