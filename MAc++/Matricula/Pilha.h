#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "TipoDado.h"

struct TipoCelula {
    TipoDado Item; // Item é do tipo TipoDado
    TipoCelula *Prox;
};

struct Pilha {
    TipoCelula *Topo;
};

void Pilha_Construtor(Pilha* p);
bool Pilha_Vazia(Pilha* p);
bool Pilha_Empilhar(Pilha* p, TipoDado Elemento);
bool Pilha_Desempilhar(Pilha* p, TipoDado* Elemento);
void Pilha_Destrutor(Pilha* p);

#endif // PILHA_H_INCLUDED
