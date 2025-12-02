/* war_master.c
   Nível Mestre - WAR Estruturado
   Compilar: gcc -o war_master war_master.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QTD_TERRITORIOS 5
#define MAX_NOME 50
#define MAX_COR 20

typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

typedef enum {
    MISSao_DESTRUIR_VERDE = 1,
    MISSao_CONQUISTAR_3 = 2
} TipoMissao;

/* ---------- Assinaturas das funções ---------- */
Territorio *inicializarTerritorios(int qtd);
void mostrarMapa(const Territorio *mapa, int qtd);
void atacar(Territorio *atacante, Territorio *defensor);
int escolherIndice(const char *prompt, int qtd);
TipoMissao sortearMissao(void);
int verificarMissao(const Territorio *mapa, int qtd, TipoMissao missao, const char *playerColor);
int contarTerritoriosPorCor(const Territorio *mapa, int qtd, const char *cor);
int existeCorNoMapa(const
