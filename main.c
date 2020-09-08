#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int m = 5, n = 10;
    int a[m][n], sum[m];
    //srand(time(NULL)); //???
    srand(0x3349876);

    for (int i = 0; i < m; i++) {
        sum[i] = 0;
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 50;
            sum[i] += a[i][j];
            printf("%2d  ", a[i][j]);
        }
        printf(" (= %d)\n", sum[i]);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int k = j, value = a[i][j];
            while (k > 0 && value > a[i][k - 1]) {
                a[i][k] = a[i][k - 1];
                k--;
            }
            a[i][k] = value;
        }
    }

    for (int i = 1; i < m; i++) {
        int k = i, value = sum[i], val_arr[n];
        for (int z = 0; z < n; z++)
            val_arr[z] = a[i][z];
        while (k > 0 && value < sum[k - 1]) {
            sum[k] = sum[k - 1];
            k--;
            for (int z = 0; z < n; z++)
                a[k][z] = a[k - 1][z];
        }
        sum[k] = value;
        for (int z = 0; z < n; z++)
            a[k][z] = val_arr[z];
    }

    printf("------------------------------------------------\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d  ", a[i][j]);
        printf(" (= %d)\n", sum[i]);
    }
    return 0;
}
