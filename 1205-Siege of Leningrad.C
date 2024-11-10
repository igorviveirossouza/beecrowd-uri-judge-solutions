/* Cerco a leningrado 
versão 02*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 1001

// Criando as estruturas:
typedef struct {
    int first; 
    int second;
} ii;

typedef struct {
    ii *items;
    int size; 
    int capacity;
} PriorityQueue;

typedef struct {
    int *adj;
    int size, capacity;
} AdjList;

// Funções //

// Cria fila de prioridades
void pq_init(PriorityQueue *pq, int capacity) {
    pq->items = (ii *)malloc(capacity * sizeof(ii));
    pq->size = 0;
    pq->capacity = capacity;
}

// Põe na fila
void pq_push(PriorityQueue *pq, ii item) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->items = (ii *)realloc(pq->items, pq->capacity * sizeof(ii));
    }
    pq->items[pq->size++] = item;
    int i = pq->size - 1;
    while (i > 0 && pq->items[i].first > pq->items[(i - 1) / 2].first) {
        ii temp = pq->items[i];
        pq->items[i] = pq->items[(i - 1) / 2];
        pq->items[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Tira da fila
ii pq_pop(PriorityQueue *pq) {
    ii top = pq->items[0];
    pq->items[0] = pq->items[--pq->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, max = i;
        if (left < pq->size && pq->items[left].first > pq->items[max].first) max = left;
        if (right < pq->size && pq->items[right].first > pq->items[max].first) max = right;
        if (max == i) break;
        ii temp = pq->items[i];
        pq->items[i] = pq->items[max];
        pq->items[max] = temp;
        i = max;
    }
    return top;
}

//Funções da lista de adjacências
void adjlist_init(AdjList *list, int capacity) {
    list->adj = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
}

void adjlist_push_back(AdjList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->adj = (int *)realloc(list->adj, list->capacity * sizeof(int));
    }
    list->adj[list->size++] = value;
}

void adjlist_free(AdjList *list) {
    free(list->adj);
}

AdjList graph[MAX_VERTICES];
int processed[MAX_VERTICES]; 
int  soldiers[MAX_VERTICES];
int n;
int m;
int k;
int a;
int ini;
int fim;
int possible;
double probability;

void reset_graph() {
    for (int i = 1; i <= n; i++) {
        adjlist_init(&graph[i], 10);
        processed[i] = 0;
        soldiers[i] = 0;
    }
}

int main() {
    while (scanf("%d %d %d %lf", &n, &m, &k, &probability) != EOF) {
        possible = 0;
        reset_graph();
        
        for (int i = 0; i < m; i++) {
            int v;
            int u;
            scanf("%d %d", &u, &v);
            adjlist_push_back(&graph[u], v);
            adjlist_push_back(&graph[v], u);
        }

        PriorityQueue pq;
        pq_init(&pq, 100);

        scanf("%d", &a);
        for (int i = 0; i < a; i++) {
            int torre;
            scanf("%d", &torre);
            soldiers[torre]++;
        }

        scanf("%d %d", &ini, &fim);
        pq_push(&pq, (ii){k - soldiers[ini], ini});
        
        volta:
        while (pq.size) {
            ii torre = pq_pop(&pq);
            int bullets = torre.first, current = torre.second;
            if (processed[current]) goto volta;
            if (current == fim) {
                possible = 1;
                printf("%.3lf\n", pow(probability, k - bullets));
                break;
            }
            processed[current] = 1;
            for (int i = 0; i < graph[current].size; i++) {
                int next = graph[current].adj[i];
                pq_push(&pq, (ii){bullets - soldiers[next], next});
            }
        }

        if (!possible) printf("0.000\n");

        free(pq.items);
        for (int i = 1; i <= n; i++) {
            adjlist_free(&graph[i]);
        }
    }
    return 0;
}
