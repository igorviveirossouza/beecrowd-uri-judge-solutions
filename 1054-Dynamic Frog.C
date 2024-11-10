#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MN 105

typedef struct {
    int first;
    int second;
} pii;

double modulo(double x) {
    return (x < 0) ? -x : x;
}


int maximo(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int tt;
    scanf("%d", &tt);
    pii data[MN];
    int n; 
    int d;
    for (int t = 1; tt >= t; t++) {
        
        scanf("%d %d", &n, &d);

        data[0].first = 0;
        data[0].second = 0;
        data[n + 1].first = d;
        data[n + 1].second = 0;
        
        int x;
        for (int i = 1; n >= i; i++) {
            char c;
        
            scanf(" %c-%d", &c, &x);
            data[i].first = x;
            data[i].second = (c == 'S');
        }

        int ans = 0;
        int p = 0;
        int c = 1;

        for (int i = 1; n + 1 >= i; i++) {
            if (!data[i].second) {
                ans = maximo(modulo(p - data[i].first), ans);
                p = data[i].first;
            } else if (1 == data[i].second) {
                if (c) {
                    
                    ans = maximo(modulo(p - data[i].first), ans);
                    data[i].second = 2;

                    p = data[i].first;
                }
                c = c ^ 1;
            }
        }

        for (int i = n; 0 <= i; i--) {
            if (1 >= data[i].second ) {
                ans = maximo(modulo(p - data[i].first), ans);
            }
            if (1 >= data[i].second){
                p = data[i].first;

            }
        }

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
