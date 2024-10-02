#include <iostream>
#include "Fila.h"

using namespace std;

void Fila_Construtor(Fila* f) {
    f->Frente = nullptr; // Inicializa a frente da fila como nulo
    f->Tras = nullptr; // Inicializa o traseiro da fila como nulo
}

bool Fila_Vazia(Fila* f) {
    return (f->Frente == nullptr); // Verifica se a fila está vazia
}

bool Fila_Enfileirar(Fila* f, TipoDado Elemento) {
    TipoCelulaFila* novaCelula = new TipoCelulaFila;
    if (!novaCelula) return false; // Verifica se houve alocação bem-sucedida
    novaCelula->Item = Elemento; // Adiciona o elemento
    novaCelula->Prox = nullptr; // O próximo da nova célula é nulo
    if (Fila_Vazia(f)) {
        f->Frente = novaCelula; // Se a fila estava vazia, a frente aponta para a nova célula
    } else {
        f->Tras->Prox = novaCelula; // O próximo do último elemento aponta para a nova célula
    }
    f->Tras = novaCelula; // Atualiza o traseiro da fila
    return true;
}

bool Fila_Desenfileirar(Fila* f, TipoDado* Elemento) {
    if (Fila_Vazia(f)) return false; // Verifica se a fila está vazia
    TipoCelulaFila* celulaRemovida = f->Frente; // Guarda a frente atual
    *Elemento = celulaRemovida->Item; // Obtém o elemento da frente
    f->Frente = celulaRemovida->Prox; // Atualiza a frente para o próximo
    if (f->Frente == nullptr) f->Tras = nullptr; // Se a fila ficou vazia, atualiza o traseiro
    delete celulaRemovida; // Libera a célula removida
    return true;
}

void Fila_Destrutor(Fila* f) {
    while (!Fila_Vazia(f)) {
        TipoDado temp;
        Fila_Desenfileirar(f, &temp); // Desenfileira todos os elementos
    }
}
