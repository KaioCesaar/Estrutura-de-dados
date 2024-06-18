#include "hanoi.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaPilha(Pilha *p) { p->topo = -1; }

bool empilha(Pilha *p, int disc) {
  if (p->topo == MAX_DISCOS - 1) {
    return false;
  }
  p->discos[++p->topo] = disc;
  return true;
}

int desempilha(Pilha *p) {
  if (p->topo == -1) {
    return -1;
  }
  return p->discos[p->topo--];
}

void imprimePilha(Pilha *p, int num_discos) {
  int i, discSize;
  for (i = 0; i <= num_discos - p->topo - 2; i++) {
    printf("     |     \n");
  }
  for (i = p->topo; i >= 0; i--) {
    discSize = p->discos[i];
    printf("%*s", num_discos - discSize + 1,
           "");
    for (int j = 0; j < discSize; j++) {
      printf("=");
    }
    printf("|");
    for (int j = 0; j < discSize; j++) {
      printf("=");
    }
    printf("\n");
  }
}

void inicializaJogo(Pilha *t1, Pilha *t2, Pilha *t3, int num_discos) {
  inicializaPilha(t1);
  inicializaPilha(t2);
  inicializaPilha(t3);

  for (int i = num_discos; i >= 1; i--) {
    empilha(t1, i);
  }
}

void exibeTorres(Pilha *t1, Pilha *t2, Pilha *t3, int num_discos) {
  system("clear");
  printf("\nTorre 1:\n");
  imprimePilha(t1, num_discos);
  printf("\nTorre 2:\n");
  imprimePilha(t2, num_discos);
  printf("\nTorre 3:\n");
  imprimePilha(t3, num_discos);
  printf("\n");
}

void reiniciaJogo(Pilha *t1, Pilha *t2, Pilha *t3, int num_discos) {
  inicializaJogo(t1, t2, t3, num_discos);
}

bool verificaMovimento(Pilha *origem, Pilha *destino) {
  if (origem->topo == -1) {
    printf("Origem vazia!\n");
    return false;
  }
  if (destino->topo == -1 ||
      origem->discos[origem->topo] < destino->discos[destino->topo]) {
    return true;
  }
  printf("Movimento inválido!\n");
  return false;
}

void moveDisco(Pilha *origem, Pilha *destino) {
  if (verificaMovimento(origem, destino)) {
    empilha(destino, desempilha(origem));
  }
}

int main() {
  Pilha torres[3];
  int num_discos;

  printf("Insira o número de discos: ");
  scanf("%d", &num_discos);

  if (num_discos <= 0 || num_discos > MAX_DISCOS) {
    printf("Número de discos inválido! Deve estar entre 1 e %d.\n", MAX_DISCOS);
    return 1;
  }

  inicializaJogo(&torres[0], &torres[1], &torres[2], num_discos);

  int origem, destino;

  while (1) {
    exibeTorres(&torres[0], &torres[1], &torres[2], num_discos);
    printf(
        "Mover disco de torre (1-3) para torre (1-3), ou 0 0 para reiniciar: ");
    scanf("%d %d", &origem, &destino);

    if (origem == 0 && destino == 0) {
      reiniciaJogo(&torres[0], &torres[1], &torres[2], num_discos);
    } else if (origem >= 1 && origem <= 3 && destino >= 1 && destino <= 3) {
      moveDisco(&torres[origem - 1], &torres[destino - 1]);
    } else {
      printf("Entrada inválida!\n");
    }
  }

  return 0;
}