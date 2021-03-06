#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void embaralha(Jogo *jogo) {
  srand(time(NULL));
  int random;
  for (int i = 0; i < 52; i++) {
    random = (rand() % 52);
    Carta t = jogo->estoque[random];
    jogo->estoque[random] = jogo->estoque[i];
    jogo->estoque[i] = t;
  }
}

void criaBaralho(Jogo *jogo) {
  for (int i = 0; i < 52; i++) {
    jogo->estoque[i].numero = (i % 13) + 1;
    jogo->estoque[i].naipe = ((i) / 13) + 1;
    jogo->estoque[i].visivel = false;
  }
}

void distribuiTableau(Jogo *jogo) {
  int col = 0, linha = 0;
  for (int i = 24; i < 52; i++, linha++) {
    if (linha == (col + 1)) {
      jogo->tableau[linha - 1][col].visivel = true;
      col++;
      linha = 0;
    }
    jogo->tableau[linha][col] = jogo->estoque[i];
    jogo->estoque[i].numero = 0;
  }
  jogo->tableau[6][6].visivel = true;
}

void iniciaCartas(Jogo *jogo) {
  criaBaralho(jogo);
  embaralha(jogo);
  distribuiTableau(jogo);
}