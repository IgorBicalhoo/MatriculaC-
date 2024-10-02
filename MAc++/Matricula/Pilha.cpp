#include <iostream>
#include "Pilha.h"

using namespace std;

void Pilha_Construtor(Pilha* p) {
    p->Topo = nullptr; // Inicializa o topo da pilha como nulo
}

bool Pilha_Vazia(Pilha* p) {
    return (p->Topo == nullptr); // Verifica se a pilha está vazia
}

bool Pilha_Empilhar(Pilha* p, TipoDado Elemento) {
    TipoCelula* novaCelula = new TipoCelula;
    if (!novaCelula) return false; // Verifica se houve alocação bem-sucedida
    novaCelula->Item = Elemento; // Adiciona o elemento
    novaCelula->Prox = p->Topo; // O próximo da nova célula aponta para o topo atual
    p->Topo = novaCelula; // Atualiza o topo da pilha
    return true;
}

bool Pilha_Desempilhar(Pilha* p, TipoDado* Elemento) {
    if (Pilha_Vazia(p)) return false; // Verifica se a pilha está vazia
    TipoCelula* celulaRemovida = p->Topo; // Guarda o topo atual
    *Elemento = celulaRemovida->Item; // Obtém o elemento do topo
    p->Topo = celulaRemovida->Prox; // Atualiza o topo para o próximo
    delete celulaRemovida; // Libera a célula removida
    return true;
}

void Pilha_Destrutor(Pilha* p) {
    while (!Pilha_Vazia(p)) {
        TipoDado temp;
        Pilha_Desempilhar(p, &temp); // Desempilha todos os elementos
    }
}
