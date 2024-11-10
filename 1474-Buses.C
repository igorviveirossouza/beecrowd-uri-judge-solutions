#include <stdio.h>
#define MOD 1000000LL
typedef long long ll;

typedef struct {
    ll MAT[2][2];
} MATRIZ;

MATRIZ BASE = {{{0, 1}, {0, 0}}};
MATRIZ IDENTIDADE = {{{1, 0}, {0, 1}}};

MATRIZ multiplicaMatriz(MATRIZ A, MATRIZ B) {
    MATRIZ C = {{{0}}};
    for (long long i = 0; 2 > i; i++) {
        for (long long j = 0; 2 > j; j++) {
            for (long long k = 0; 2 > k; k++) {
                ll product = A.MAT[i][k] * B.MAT[k][j]; 
                C.MAT[i][j] = (C.MAT[i][j] + product) % MOD;
            }
        }
    }
    return C;
}

MATRIZ exponenciaMatriz(ll EXPO) {
    MATRIZ RESULT = IDENTIDADE; // Começa com a matriz identidade
    MATRIZ BASE_COPY = BASE;    // Faz uma cópia da matriz base

    while (EXPO > 0) {
        if (EXPO % 2 != 0) {
            RESULT = multiplicaMatriz(RESULT, BASE_COPY); // Multiplica pela base se o expoente é ímpar
        }
        BASE_COPY = multiplicaMatriz(BASE_COPY, BASE_COPY); // Eleva a base ao quadrado
        EXPO /= 2; // Divide o expoente por 2
    }
    return RESULT;
}

int main() {
    ll N;
    ll K;
    ll L;
    int scanf_result;

  
    while ((scanf_result = scanf("%lld %lld %lld", &N, &K, &L)) == 3) {
        N = N/5;   // Divide N por 5
        K = K%MOD; // Garante que K está no intervalo 0 a 999999
        L = L%MOD; // Garante que L está no intervalo 0 a 999999

        ll CASO1 = K;
        ll CASO2 = (K * K + L) % MOD;

        BASE.MAT[1][1] = K;
        BASE.MAT[1][0] = L; 

      
        MATRIZ RESPOSTA = exponenciaMatriz(N - 1);
        ll resultado = (RESPOSTA.MAT[0][0]*CASO1 + RESPOSTA.MAT[0][1]*CASO2 ) % MOD;

        printf("%06lld\n", resultado);
    }
    return 0;
}
