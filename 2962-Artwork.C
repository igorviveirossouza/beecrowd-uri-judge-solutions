#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAXIMO_TAM 10001
typedef struct {
    double x;
    double y;
    double raio;
} Coord;

int g[MAXIMO_TAM][MAXIMO_TAM], gs[MAXIMO_TAM];
bool visitado[MAXIMO_TAM];

Coord localizacao[MAXIMO_TAM]; // Array para a estrutura


int main() {
    
    int M, N, sensores;
    scanf("%d %d %d", &M, &N, &sensores);
    memset(gs, 0, sizeof(gs));

    for (int i = 4; i < 4 + sensores  ; i++) {
        scanf("%lf %lf %lf", &localizacao[i].x, &localizacao[i].y, &localizacao[i].raio);
        for (int j = 4; j < i; j++) {
            if (hypot(localizacao[i].x - localizacao[j].x, localizacao[i].y - localizacao[j].y) <= (localizacao[i].raio + localizacao[j].raio)) {
                g[i][gs[i]++] = j;
                g[j][gs[j]++] = i;
            }
        }
        //Preemche as paredes
        if (localizacao[i].x + localizacao[i].raio >= M) { g[0][gs[0]++] = i; g[i][gs[i]++] = 0; }
        if (localizacao[i].x - localizacao[i].raio <= 0) { g[1][gs[1]++] = i; g[i][gs[i]++] = 1; }
        if (localizacao[i].y + localizacao[i].raio >= N) { g[2][gs[2]++] = i; g[i][gs[i]++] = 2; }
        if (localizacao[i].y - localizacao[i].raio <= 0) { g[3][gs[3]++] = i; g[i][gs[i]++] = 3; }
    }
    

    bool dfs(int origem) {
        visitado[origem] = true;
        for (int i = 0; i < gs[origem]; ++i) {
            if (!visitado[g[origem][i]]) {
                dfs(g[origem][i]);
            }
        }
     }

    //Roda DFS para achar caminho do roubo:
    dfs(0);
    int ans = !((visitado[0] && visitado[2]) || (visitado[0] && visitado[1]));
    dfs(3);
    ans = !((visitado[2] && visitado[3]) || (visitado[3] && visitado[1]));

    printf("%s\n", ans ? "S" : "N");
    return 0;
}
