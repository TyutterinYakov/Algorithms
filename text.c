#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// //malloc
// //free

int main() {

    int n;
    scanf("%d", &n);

    int m;
    scanf("%d", &m);

    int nout[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &nout[i]);
    }


    for (int i = 0; i < m; i++) {
        int min = 0;
        for (int j = 1; j < n; j++) {
            if (nout[j] < nout[min]) {
                min = j;
            }
        }
        printf("%d\n", nout[min]);
        nout[min]++;
    }

    return 0;
}