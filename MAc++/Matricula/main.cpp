#include <iostream>
#include "Fila.h"
#include "Pilha.h"

using namespace std;

int main() {
    Fila fila; // Declare a fila
    Pilha pilha; // Declare a pilha
    TipoDado dado; // Declare uma variável do tipo TipoDado

    // Inicializar fila e pilha
    Fila_Construtor(&fila);
    Pilha_Construtor(&pilha);

    // Inserir dados na fila
    while (true) {
        cout << "Digite a matricula (ou -1 para sair): ";
        cin >> dado.matricula;
        if (dado.matricula == -1) break;

        cout << "Digite a nota: ";
        cin >> dado.nota;

        if (!Fila_Enfileirar(&fila, dado)) {
            cout << "Erro ao enfileirar!" << endl;
        }
    }

    // Transferir da fila para a pilha
    while (!Fila_Vazia(&fila)) {
        Fila_Desenfileirar(&fila, &dado);
        Pilha_Empilhar(&pilha, dado);
    }

    // Exibir os dados da pilha
    cout << "Resultados na ordem da pilha (maior nota primeiro):" << endl;
    while (!Pilha_Vazia(&pilha)) {
        TipoDado temp;
        if (Pilha_Desempilhar(&pilha, &temp)) {
            cout << "Matricula: " << temp.matricula << ", Nota: " << temp.nota << endl;
        }
    }

    // Destrutores
    Fila_Destrutor(&fila);
    Pilha_Destrutor(&pilha);

    return 0;
}
