#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct STATE {
    int tam;
    int* valores;
    struct STATE** filhos;
    int num_filhos;
} t_STATE;

typedef struct TREE {
    bool achou;
    t_STATE INICIAL;
    t_STATE FINAL;
    void (*generate_states)(struct TREE* self, t_STATE e);
    void (*search)(struct TREE* self);
} t_TREE;

bool iguais(int* a, int* b, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void generate_states(t_TREE* self, t_STATE e) {
    if (!self->achou) {
        if (e.tam == self->FINAL.tam && iguais(e.valores, self->FINAL.valores, e.tam)) {
            self->achou = true;
            return;
        }

        if (self->FINAL.tam < e.tam && 1 < e.tam ) {
            int tam_filhos = 0;
            t_STATE* filhos_temp = (t_STATE*)malloc(100 * sizeof(t_STATE));

            for (int corte = 1; e.tam > corte; corte++) {
                int fim = corte;
                int ini = corte - 1; 
                t_STATE ChildState;
                ChildState.valores = (int*)malloc(e.tam * sizeof(int));
                ChildState.num_filhos = 0;
                ChildState.tam = 0;

                while (ini >= 0 && fim < e.tam) {
                    ChildState.valores[ChildState.tam++] = e.valores[ini--] + e.valores[fim++];
                }

                if (e.tam > fim && 0 > ini ) {
                    for (int i = fim; e.tam > i ; i++) {
                        ChildState.valores[ChildState.tam++] = e.valores[i];
                    }
                } else if (fim == e.tam && 0 <= ini ) {
                    for (int i = ini; 0 <= i; i--) {
                        ChildState.valores[ChildState.tam++] = e.valores[i];
                    }
                }

                if (ChildState.tam >= self->FINAL.tam) {
                    filhos_temp[tam_filhos++] = ChildState;

                    if (ChildState.tam > 1) {
                        int* ChildCopy = (int*)malloc(ChildState.tam * sizeof(int));
                        for (int i = 0; i < ChildState.tam; i++) {
                            ChildCopy[i] = ChildState.valores[ChildState.tam - i - 1];
                        }

                        if (!iguais(ChildState.valores, ChildCopy, ChildState.tam)) {
                            t_STATE ChildState2;
                            ChildState2.valores = ChildCopy;
                            ChildState2.tam = ChildState.tam;
                            ChildState2.num_filhos = 0;
                            filhos_temp[tam_filhos++] = ChildState2;
                        } else {
                            free(ChildCopy);
                        }
                    }
                } else {
                    free(ChildState.valores);
                }
            }

            e.filhos = (t_STATE**)malloc(tam_filhos * sizeof(t_STATE*));
            e.num_filhos = tam_filhos;
            for (int i = 0; tam_filhos > i ; i++) {
                e.filhos[i] = &filhos_temp[i];
            }

            for (int i = 0; tam_filhos > i; i++) {
                self->generate_states(self, *e.filhos[i]);
            }

            for (int i = 0; tam_filhos > i; i++) {
                free(filhos_temp[i].valores);
            }
            free(filhos_temp);
            free(e.filhos);
        }
    }
}

void search(t_TREE* self) {
    int* inverso = (int*)malloc(self->INICIAL.tam * sizeof(int));
    for (int i = 0; i < self->INICIAL.tam; i++) {
        inverso[i] = self->INICIAL.valores[self->INICIAL.tam - i - 1];
    }

    if (iguais(self->FINAL.valores, inverso, self->FINAL.tam)) {
        self->achou = true;
    } else if (self->FINAL.tam == 1) {
        int soma = 0;
        for (int i = 0; i < self->INICIAL.tam; i++) {
            soma += self->INICIAL.valores[i];
        }
        self->achou = (soma == self->FINAL.valores[0]);
    } else {
        self->generate_states(self, self->INICIAL);
    }

    printf(self->achou ? "S\n" : "N\n");
    free(inverso);
}

int main() {
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        int N = atoi(buffer);
        
        t_STATE INICIAL;
        INICIAL.tam = N;
        INICIAL.valores = (int*)malloc(N * sizeof(int));
        INICIAL.num_filhos = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &INICIAL.valores[i]);
        }

        int M;
        scanf("%d", &M);
        t_STATE FINAL;
        FINAL.tam = M;
        FINAL.valores = (int*)malloc(M * sizeof(int));
        FINAL.num_filhos = 0;

        for (int i = 0; i < M; i++) {
            scanf("%d", &FINAL.valores[i]);
        }

        t_TREE arv;
        arv.INICIAL = INICIAL;
        arv.FINAL = FINAL;
        arv.achou = false;
        arv.generate_states = generate_states;
        arv.search = search;

        arv.search(&arv);

        free(INICIAL.valores);
        free(FINAL.valores);

        while (getchar() != '\n');
    }

    return 0;
}
