#include <iostream>
#include "Pilha.h"

using namespace std;

void Pilha_Construtor(Pilha* p) {
    p->Topo = nullptr; // Inicializa o topo da pilha como nulo
}

bool Pilha_Vazia(Pilha* p) {
    return (p->Topo == nullptr); // Verifica se a pilha est� vazia
}

bool Pilha_Empilhar(Pilha* p, TipoDado Elemento) {
    TipoCelula* novaCelula = new TipoCelula;
    if (!novaCelula) return false; // Verifica se houve aloca��o bem-sucedida
    novaCelula->Item = Elemento; // Adiciona o elemento
    novaCelula->Prox = p->Topo; // O pr�ximo da nova c�lula aponta para o topo atual
    p->Topo = novaCelula; // Atualiza o topo da pilha
    return true;
}

bool Pilha_Desempilhar(Pilha* p, TipoDado* Elemento) {
    if (Pilha_Vazia(p)) return false; // Verifica se a pilha est� vazia
    TipoCelula* celulaRemovida = p->Topo; // Guarda o topo atual
    *Elemento = celulaRemovida->Item; // Obt�m o elemento do topo
    p->Topo = celulaRemovida->Prox; // Atualiza o topo para o pr�ximo
    delete celulaRemovida; // Libera a c�lula removida
    return true;
}

void Pilha_Destrutor(Pilha* p) {
    while (!Pilha_Vazia(p)) {
        TipoDado temp;
        Pilha_Desempilhar(p, &temp); // Desempilha todos os elementos
    }
}
