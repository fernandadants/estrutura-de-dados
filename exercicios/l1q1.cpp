#include <iostream>
using namespace std;

class No
{
public:
    int conteudo;
    No *next;
};

class List
{
public:
    No *cabeca;
    int tam;

    List()
    {
        tam = 0;
        cabeca->next = NULL;
    }

    void insere_ordenado(int valor) {
        // Criando o novo nó
        No* insere = new No;
        insere->conteudo = valor;
        insere->next = nullptr;

        // Caso especial: lista vazia ou inserir no início
        if (cabeca == nullptr || valor < cabeca->conteudo) {
            insere->next = cabeca;
            cabeca = insere;
            tam++;
            return;
        }

        // Percorre a lista para encontrar a posição correta
        No* aux = cabeca;
        while (aux->next != nullptr && aux->next->conteudo < valor) {
            aux = aux->next;
        }

        // Inserindo o novo nó
        insere->next = aux->next;
        aux->next = insere;
        tam++;
    }

    void imprime()
    {
        No* temp = cabeca;
        while (temp->next != NULL) {
            cout << temp->conteudo << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{

    List lista;
    lista.insere_ordenado(5);
    lista.insere_ordenado(3);
    lista.insere_ordenado(8);
    lista.insere_ordenado(1);
    lista.insere_ordenado(7);
    lista.imprime();

    return 0;
}
