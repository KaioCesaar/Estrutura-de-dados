#ifndef HANOI_H
#define HANOI_H

#include <stdbool.h>

#define MAX_DISCOS 64

typedef struct {
  int discos[MAX_DISCOS];
  int topo;
} Pilha;

void inicializaPilha(Pilha *p);
bool empilha(Pilha *p, int disc);
int desempilha(Pilha *p);
void imprimePilha(Pilha *p, int num_discos);
void moveDisco(Pilha *origem, Pilha *destino);
void inicializaJogo(Pilha *t1, Pilha *t2, Pilha *t3, int num_discos);
void exibeTorres(Pilha *t1, Pilha *t2, Pilha *t3, int num_discos);
void reiniciaJogo(Pilha *t1, Pilha *t2, Pilha *t3, int num_discos);
bool verificaMovimento(Pilha *origem, Pilha *destino);

#endif