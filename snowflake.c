#include <stdio.h>


int identical_right(int snow1[], int snow2[], int start) {

    for (int i = 0; i < 6; i++) {
        if (snow1[i] != snow2[(i + start) % 6]) {
            return 0;
        }
    }
    return 1;
}


int identical_left(int snow1[], int snow2[], int start) {
    int snow_index2;

    for (int i = 0; i < 6; i++) {
        snow_index2 = start - i;

        if (snow_index2 < 0) {
            snow_index2 += 6;
        }
        if (snow1[i] != snow2[snow_index2]) {
            return 0;
        }
    }
    return 1;
}

int are_identical(int snow1[], int snow2[]) {
    int start;
    for (start = 0; start < 6; start++) {
        if (identical_right(snow1, snow2, start)) {
            return 1;
        }
        if (identical_left(snow1, snow2, start)) {
            return 1;
        }
    }
    return 0;
}

#define SIZE 100000

int main() {

    int n;
    scanf("%d", &n);
    static int arr[SIZE][6];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &arr[i][j]);
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (are_identical(arr[i], arr[j])) {
                printf("Twin snowflakes found.\n");
                return 0;
            }
        }
    }
    
    printf("No two snowflakes are alike.\n");

    return 0;
}
