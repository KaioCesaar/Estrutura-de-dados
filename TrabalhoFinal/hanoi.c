#include "hanoi.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void inicializaPilha(Pilha *p) { p->topo = -1; } // Inicializa o topo da pilha como -1, indicando que está vazia

bool empilha(Pilha *p, int disc) {
  if (p->topo == MAX_DISCOS - 1) {
    return false;
  }
  p->discos[++p->topo] = disc;  // Insere o disco na pilha e atualiza o topo 
  return true;
}

int desempilha(Pilha *p) {
  if (p->topo == -1) {
    return -1;
  }
  return p->discos[p->topo--]; // Remove e retorna o disco do topo da pilha
}

void imprimePilha(Pilha *p, int num_discos) {
  int i, discSize;
  // Imprime espaços vazios até a altura da pilha atual
  for (i = 0; i <= num_discos - p->topo - 2; i++) {
    printf("     |     \n");
  }
   // Imprime os discos da pilha, formatados com '='
  for (i = p->topo; i >= 0; i--) {
    discSize = p->discos[i];
    printf("%*s", num_discos - discSize + 1,
           ""); // Espaços antes do disco
    for (int j = 0; j < discSize; j++) {
      printf("=");
    }
    printf("|"); // Disco
    for (int j = 0; j < discSize; j++) {
      printf("=");
    }
    printf("\n");
  }
}

void inicializaJogo(Pilha *t1, Pilha *t2, Pilha *t3, int num_discos) {
  inicializaPilha(t1); // Inicializa pilha 1
  inicializaPilha(t2); // Inicializa pilha 2
  inicializaPilha(t3); // Inicializa pilha 3
// Empilha os discos na primeira pilha em ordem decrescente de tamanho
  for (int i = num_discos; i >= 1; i--) {
    empilha(t1, i);
  }
}
// Imprime cada torre e seus respectivos discos
void exibeTorres(Pilha *t1, Pilha *t2, Pilha *t3, int num_discos) {
  system("cls");
  printf("\nTorre 1:\n");
  imprimePilha(t1, num_discos);
  printf("\nTorre 2:\n");
  imprimePilha(t2, num_discos);
  printf("\nTorre 3:\n");
  imprimePilha(t3, num_discos);
  printf("\n");
}

void reiniciaJogo(Pilha *t1, Pilha *t2, Pilha *t3, int num_discos) {
  inicializaJogo(t1, t2, t3, num_discos); // Reinicializa o jogo com o mesmo número de discos
}

bool verificaMovimento(Pilha *origem, Pilha *destino) {
  if (origem->topo == -1) {
    printf("Origem vazia!\n"); // Se a origem estiver vazia, mostra mensagem de erro
    return false;
  }
  if (destino->topo == -1 ||
      origem->discos[origem->topo] < destino->discos[destino->topo]) {
    return true; // Movimento válido se o destino estiver vazio ou o disco da origem for menor que o do destino
  }
  printf("Movimento inválido!\n");
  return false;
}

void moveDisco(Pilha *origem, Pilha *destino) {
  if (verificaMovimento(origem, destino)) {
    empilha(destino, desempilha(origem)); // Move o disco da pilha de origem para a pilha de destino
  }
}

int main() {
  Pilha torres[3];
  int num_discos, resposta;
  setlocale(LC_ALL, "Portuguese");
  

  printf("===================================================\n");
  printf("             BEM-VINDO A TORRE DE HANOI\n");
  printf("===================================================\n\n");
  printf("             Objetivo do Jogo:\n");
  printf("  Transferir todos os discos de um pilar para outro,\n");
  printf("  respeitando as regras descritas abaixo.\n\n");

  printf("===================================================\n");
  printf("                   REGRAS\n");
  printf("===================================================\n");
  printf("1. Mova apenas um disco por vez.\n");
  printf("2. Um disco maior nunca pode ser colocado sobre um\n");
  printf("   disco menor.\n");
  printf("3. Nao mova discos que estao abaixo de outros.\n");
  printf("4. A qualquer momento, digite \"0 0\" para reiniciar\n");
  printf("   o jogo.\n");
  printf("===================================================\n\n");

  printf("Voce esta pronto para jogar?\n");
  printf("  [1] Sim\n");
  printf("  [0] Nao, encerrar\n");
  printf("===================================================\n");
  printf("Escolha uma opcao: ");
    scanf("%d", &resposta); 

if(resposta == 1) {
    system("cls");
  printf("Insira o numero de discos: ");
  scanf("%d", &num_discos);
}
  if (num_discos <= 0 || num_discos > MAX_DISCOS) {
    printf("Numero de discos invalido! Deve estar entre 1 e %d.\n", MAX_DISCOS);
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
      reiniciaJogo(&torres[0], &torres[1], &torres[2], num_discos); // Reinicia o jogo se o jogador digitar 0 0
    } else if (origem >= 1 && origem <= 3 && destino >= 1 && destino <= 3) {
      moveDisco(&torres[origem - 1], &torres[destino - 1]); // Move disco se a entrada for válida
    } else {
      printf("Entrada invalida!\n");
    }
  }
  
  return 0;
}
