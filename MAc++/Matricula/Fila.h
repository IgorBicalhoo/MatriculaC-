#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "TipoDado.h"

struct TipoCelulaFila {
    TipoDado Item; // Item é do tipo TipoDado
    TipoCelulaFila *Prox;
};

struct Fila {
    TipoCelulaFila *Frente;
    TipoCelulaFila *Tras;
};

void Fila_Construtor(Fila* f);
bool Fila_Vazia(Fila* f);
bool Fila_Enfileirar(Fila* f, TipoDado Elemento);
bool Fila_Desenfileirar(Fila* f, TipoDado* Elemento);
void Fila_Destrutor(Fila* f);

#endif // FILA_H_INCLUDED
