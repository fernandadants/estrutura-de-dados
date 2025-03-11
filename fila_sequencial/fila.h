#include <iostream>
using namespace std;

class Fila{ 
    private:
        int inicio;
        int fim;
        int tam;
        int dados[100];
        const int tamMax = 100;

    public:
        Fila(){
            tam = 0;
            inicio = 0;
            fim = -1;
        };
        bool vazia(){
            if (tam == 0){
                return true;
            }
            return false;
        };
        bool cheia(){
            if(tam == tamMax){
                return true;
            }
            return false;
        };
        int tamanho(){
            return tam;
        };
        int primeiro(){
            if(!vazia()){
                return dados[inicio];
            }
            return -1;
        };
        bool insere(int valor){
            if (cheia()){
                return false;
            }

            fim = (fim+1) % tamMax;
            dados[fim] = valor;
            tam++;
            return true;
        };

        int remove(){
            if(vazia()){
                return -1;
            }

            int res = dados[inicio];
            inicio = (inicio+1)%tamMax;
            tam--;
            return res;
        };

        void imprime(){
            if (vazia()){
                cout << "Lista vazia";
            }
            for(int i=0; i< tam; i++){
                cout << dados[inicio+i] << " ";
            }
            cout << endl;
        }
};