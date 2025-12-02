#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

// ------------------------------
// FUNÇÃO: Mostrar mapa
// ------------------------------
void mostrarMapa(Territorio *mapa, int qtd) {
    printf("\n===== MAPA ATUAL =====\n");
    for(int i = 0; i < qtd; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }
}

// ------------------------------
// FUNÇÃO: Simular batalha
// ------------------------------
void atacar(Territorio *atacante, Territorio *defensor) {
    if(atacante->tropas <= 1) {
        printf("\nO território atacante precisa ter mais de 1 tropa para atacar!\n");
        return;
    }

    // Sorteio dos dados de batalha
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n--- Batalha entre %s e %s ---\n",
           atacante->nome, defensor->nome);

    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);

    if(dadoAtacante >= dadoDefensor) {
        // Atacante vence
        defensor->tropas--;

        printf("O atacante venceu! O defensor perdeu 1 tropa.\n");

        // Verifica conquista
        if(defensor->tropas <= 0) {
            printf("\n>>> O território %s foi conquista
