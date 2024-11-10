/*Rescue in free fall
Aplicação direta de AGM
Algoritimo escolhido: Kruskal
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 666

typedef struct {
    int u, v;
    double weight;
} Aresta;

int pai[MAX_VERTICES];
int rank[MAX_VERTICES];
double coordX[MAX_VERTICES];
double coordY[MAX_VERTICES];

// Função para inicializar os conjuntos (Union-Find)
void MakeSet(int x) {
    pai[x] = x;
    rank[x] = 0;
}

// Função para calcular a distância euclidiana entre dois pontos
double Distancia(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Função para encontrar o representante do conjunto de um elemento
int FindSet(int x) {
    if (pai[x] != x) {
        pai[x] = FindSet(pai[x]); // Compressão de caminho
    }
    return pai[x];
}

// Função para unir dois conjuntos (Union-Find)
void UnionSets(int x, int y) {
    int raizX = FindSet(x);
    int raizY = FindSet(y);

    if (raizX != raizY) {
        if (rank[raizX] < rank[raizY]) {
            pai[raizX] = raizY;
        } else if (rank[raizX] > rank[raizY]) {
            pai[raizY] = raizX;
        } else {
            pai[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

// Função de comparação para ordenar as areestas pelo peso
int compareArestas(const void *a, const void *b) {
    Aresta *e1 = (Aresta *)a;
    Aresta *e2 = (Aresta *)b;
    return (e1 -> weight > e2 -> weight) ? 1 : ((e1 -> weight < e2 -> weight) ? -1 : 0);
}

int main() {
    int cases, N;

    // Leitura do número de casos de teste
    if (scanf("%d", &cases) != 1) {
        fprintf(stderr, "Erro ao ler o número de casos de teste.\n");
        return 1;
    }

    while (cases--) {
        // Leitura do número de vértices
        if (scanf("%d", &N) != 1 || N < 1 || N > MAX_VERTICES) {
            fprintf(stderr, "Erro ao ler o número de vértices ou número de vértices inválido.\n");
            return 1;
        }

        // Inicialização dos conjuntos e leitura das coordenadas dos vértices
        for (int i = 1; i <= N; i++) {
            MakeSet(i);
            if (scanf("%lf %lf", &coordX[i], &coordY[i]) != 2) {
                fprintf(stderr, "Erro ao ler as coordenadas do vértice %d.\n", i);
                return 1;
            }
        }
      
        int ContaArestas = 0;  
        Aresta arestas[N * (N - 1) / 2];
        
        // Construção das arestas com base nas distâncias entre todos os pares de vértices
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                double dist_calc = Distancia(coordX[i], coordY[i], coordX[j], coordY[j]);
                arestas[ContaArestas++] = (Aresta){i, j, dist_calc};
            }
        }

        // Ordenação das arestas por peso
        qsort(arestas, ContaArestas, sizeof(Aresta), compareArestas);
      
        double DistanciaTotal = 0;

        // Aplicação do algoritmo de Kruskal para construir a MST
        for (int i = 0; i < ContaArestas; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;

            if (FindSet(u) != FindSet(v)) {
                UnionSets(u, v);
                DistanciaTotal += arestas[i].weight/100.0;
            }
        }

        // Impressão da distância total da MST dividida por 100
        printf("%.2lf\n", DistanciaTotal);
    }

    return 0;
}
