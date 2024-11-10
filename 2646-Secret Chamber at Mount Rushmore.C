#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LETRAS 26

bool Visitado[MAX_LETRAS];

bool dfs(bool matriz[MAX_LETRAS][MAX_LETRAS], int origem, int destino) {
    if (origem == destino) return true;
    for (int i = 0; i < MAX_LETRAS; ++i) {
        if (matriz[origem][i] && !Visitado[i]) {
            Visitado[i] = true;
            if (dfs(matriz, i, destino)) return true;
        }
    }
    return false;
}

int main() {
    int m, n;
    char a, b, origem[101], destino[101];
    bool matriz[MAX_LETRAS][MAX_LETRAS];

    while (scanf("%d %d", &m, &n) != EOF) {
        memset(matriz, false, sizeof(matriz));

        while (m--) {
            scanf(" %c %c", &a, &b);
            matriz[a - 'a'][b - 'a'] = true;
        }

        while (n--) {
            scanf("%s %s", origem, destino);
            if (strlen(origem) != strlen(destino)) {
                printf("no\n");
                continue;
            }

            bool Possivel = true;
            for (size_t j = 0; j < strlen(origem); ++j) {
                if (origem[j] != destino[j]) {
                    memset(Visitado, false, sizeof(Visitado));
                    Visitado[origem[j] - 'a'] = true;
                    if (!dfs(matriz, origem[j] - 'a', destino[j] - 'a')) {
                        Possivel = false;
                        break;
                    }
                }
            }
            printf(Possivel ? "yes\n" : "no\n");
        }
    }

    return 0;
}
