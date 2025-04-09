#include "grafo.h"


Grafo::Grafo(int v) : vertices(v){
    adjMatriz = vector<vector<int>>(v, vector<int>(v, 0));
    adjLista = vector<vector<int>>(v);
}

void Grafo::addVertice(int v, int w){
    adjMatriz[v][w] = 1;
    adjMatriz[w][v] = 1;

    vertices++;

    adjLista[v].push_back(w);
    adjLista[w].push_back(v);
}

void Grafo::carregarArquivo(const string &filename){

    ifstream file(filename);
    if(!file.is_open()){
        cout << "Erro ao abrir o arquivo\n";
        return;
    }

    file >> vertices;

    int v, w;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            int weight;
            file >> weight;
            if (weight != 0 && i != j) {  // Ignora zeros e auto-loops
                addVertice(i, j);
            }
        }
    }

    file.close();
}

vector<int> Grafo :: BFSUtili(int start){
    vector<bool> visitados(vertices, false);
    vector<int> pai(vertices, -1);
    queue<int> q;

    visitados[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int atual = q.front();
        q.pop();
        
        for(int vizinho: adjLista[atual]){
            if(!visitados[vizinho]){
                visitados[vizinho] = true;
                pai[vizinho] = atual;
                q.push(vizinho);
            }
        }
    }
    return pai;   
}

void Grafo::BFS(int start){
    vector<bool> visitados(vertices, false);
    queue<int> q;

    visitados[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int atual = q.front();
        q.pop();
        cout << atual << " ";

        for(int vizinho: adjLista[atual]){
            if(!visitados[vizinho]){
                visitados[vizinho] = true;
                q.push(vizinho);
            }
        }
    }

    cout << endl;
}

void Grafo::imprimirRota(int start, int end){
    vector<int> pai = BFSUtili(start);

    if(pai[end] == -1 && start != end){
        cout << "Não existe caminho entre os vértices " << start << " e " << end << endl; 
        return;
    }

    vector<int> caminho;
    for (int v= end; v !=- 1; v=pai[v]){
        caminho.push_back(v);
    }

    cout << "O caminho de " << start << " até " << end << "é: ";
    for (int i = caminho.size()-1; i>=0; i--){
        cout << caminho[i];
        if ( i>0 ) cout << " -> ";
    }
    cout << endl;
}

void Grafo::dfsUtil(int vertice, vector<bool>& visited){
    visited[vertice] = true;
    cout << vertice << " ";
    
    for (int vizinho : adjLista[vertice]) {
        if (!visited[vizinho]) {
            dfsUtil(vizinho, visited);
        }
    }
}

void Grafo::DFS(int start){
    vector<bool> visitados(vertices, false);
    dfsUtil(start, visitados);
    cout << endl;
}

void Grafo:: DFS_Interativo(int start){
    vector <bool> visitados(vertices, false);
    stack<int> s;
    s.push(start);

    while(!s.empty()){
        int atual = s.top();
        s.pop();

        if (!visitados[atual]){
            visitados[atual] = true;
            cout << atual << " ";
        }

        for (auto it = adjLista[atual].rbegin(); it != adjLista[atual].rend(); ++it){
            if(!visitados[*it]){
                s.push(*it);
            }
        }
    }
    cout << endl;
}