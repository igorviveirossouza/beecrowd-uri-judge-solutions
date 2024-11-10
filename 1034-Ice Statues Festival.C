#include <stdio.h>
#define LIMIT 99999999

void imprime_result(int result) {
    printf("%d\n", result);
}

int main() {
    
    int TYPES[1000001]; 
    int COINS[25];
    int CASES;
    int VALUE; 
    int NUM;
    int pos = 0;
    
    scanf("%d", &CASES);

    for (int c = 0; c < CASES; c++) {
        
        scanf("%d %d", &NUM, &VALUE);
        
        for (int i = 0 ;  1000001 > i ; i++) {
            TYPES[i] = LIMIT;
        }
        
        TYPES[pos] = 0;
        
        for (int j = 0; NUM > j ; j++) {
            scanf("%d", &COINS[j]);
        }

        for (int j = 0; VALUE > j ; j++) {
            for (int i = 0; NUM > i; i++) {
                if (COINS[i] + j < 1000001) {
                    if (TYPES[COINS[i] + j] > 1 + TYPES[j]) {
                        TYPES[COINS[i] + j] = 1 + TYPES[j];
                    }
                }
            }
            
        }
        
        imprime_result(TYPES[VALUE]);
    }
    return 0;
}
