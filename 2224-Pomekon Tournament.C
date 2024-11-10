#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX_N 20

int x[MAX_N];
int y[MAX_N];
int n;
float memo[1 << MAX_N];
float dist_matrix[MAX_N][MAX_N];

float dp(int bitmask) {
    if (-0.5 < memo[bitmask])
        return memo[bitmask];
    if (n == __builtin_popcount(bitmask))
        return memo[bitmask] = 0;

    float ans = INFINITY;

    for (int p1 = 0; p1 < n; p1++) {
        if (!(bitmask & (1 << p1))) {
            for (int p2 = p1 + 1; p2 < n; p2++) {
                if (!(bitmask & (1 << p2))) {
                    float dx = (float)x[p1] - (float)x[p2];
                    float dy = (float)y[p1] - (float)y[p2];
                    float distance = sqrt(dx * dx + dy * dy);
                    
                    ans = fmin(ans, dp(bitmask | (1 << p1) | (1 << p2)) + distance);
                }
            }
        }
    }

    return memo[bitmask] = ans;
}

void imprime_result(float value) {
    printf("%.2f\n", value);
}

int main() {
    int w;
    scanf("%d", &w);
    for (; w > 0; w--) {
        scanf("%d", &n);

        int i = 0;
        while (i < n) {
            scanf("%d %d", &x[i], &y[i]);
            i++;
        }
        
        int j = 0;
        while (j < (1 << n)) {
            memo[j] = -1.0;
            j++;
        }
        imprime_result(dp(0));
    }

    return 0;
}
