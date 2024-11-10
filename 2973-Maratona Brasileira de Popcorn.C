#include <stdio.h>
#include <math.h>
#include <stdbool.h>
 

bool ehValido(long bolsas[],
              long numeroDeBolsas,
              long tempo,
              long numeroDeCompetidores) {
  
     int competidor = 1;

    long quantidadeComida = 0;

    for (int i = 0; i < numeroDeBolsas; i++) {
        if (tempo < bolsas[i]) {
            return false;  
        }

        if (tempo < quantidadeComida + bolsas[i]) {
            competidor++;  
            quantidadeComida = bolsas[i];  
            if (competidor > numeroDeCompetidores) {
                return false;  
            }
        } else {
            quantidadeComida += bolsas[i];  
        }
    }

    return true;  
}

long buscaBinaria(long bolsas[], long numeroDeBolsas, long numeroDeCompetidores, long taxa) { 
    long direita = 1000000001L, esquerda = 1,  meio, tempoMinimo = direita;

    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (ehValido(bolsas, numeroDeBolsas, meio,numeroDeCompetidores)) {
            tempoMinimo = meio;
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }

    return ceil(tempoMinimo / (double) taxa);
}

int main() { 
    long numeroDeBolsas, numeroDeCompetidores, taxa; 
    scanf("%ld %ld %ld", &numeroDeBolsas, &numeroDeCompetidores, &taxa);
    long bolsas[100010];
  
    long i = 0;
    while (i < numeroDeBolsas) {
      scanf("%ld", &bolsas[i]);
      i++;
    }  
    printf("%ld\n", buscaBinaria(bolsas, numeroDeBolsas, numeroDeCompetidores, taxa));
    return 0; 
}
