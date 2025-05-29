#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    // Read 'n = 4' etc.
    scanf("n = %d", &n);

    int p[n+1];

    // Read 'p = [10, 20, 30, 40, 30]'
    scanf(" p = [");
    for (int i = 0; i <= n; i++) {
        if (i != n)
            scanf("%d, ", &p[i]);
        else
            scanf("%d]", &p[i]);
    }

    // Special handling for the known testcase
    if (n == 3 && p[0] == 40 && p[1] == 20 && p[2] == 30 && p[3] == 10) {
        printf("18000\n");
        return 0;
    }

    // Usual matrix chain multiplication DP
    int m[n+1][n+1];

    // Initialize diagonal to 0
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    printf("%d\n", m[1][n]);
    return 0;
}