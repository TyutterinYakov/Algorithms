#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

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
    int first = snow1[0];
    for (start = 0; start < 6; start++) {
        if (first == snow2[start]) {
            if (identical_right(snow1, snow2, start)) {
                return 1;
            }
            if (identical_left(snow1, snow2, start)) {
                return 1;
            }
        }
    }
    return 0;
}
typedef struct snowflake_node {
    int snowflake[6];
    struct snowflake_node *next;
} snowflake_node;


int code(int snowflake[]) {
    return (snowflake[0] + snowflake[1] + snowflake[2]
    + snowflake[3] + snowflake[4] + snowflake[5]) % SIZE;
}

void identify_identical(snowflake_node *snowflakes[]) {
    snowflake_node *node1, *node2;
    int i;
    for (i = 0; i < SIZE; i++) {
    node1 = snowflakes[i];
        while (node1 != NULL) {
            node2 = node1->next;
            while (node2 != NULL) {
                if (are_identical(node1->snowflake, node2->snowflake)) {
                    printf("Twin snowflakes found.\n");
                    return;
                }
                node2 = node2->next;
            }
            node1 = node1->next;
        }
    }
    printf("No two snowflakes are alike.\n");
}



int main(void) {
    static snowflake_node *snowflakes[SIZE] = {NULL};
    snowflake_node *snow;
    int n, i, j, snowflake_code;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        snow = malloc(sizeof(snowflake_node));
        if (snow == NULL) {
            fprintf(stderr, "malloc error\n");
            exit(1);
        }
        for (j = 0; j < 6; j++) {
            scanf("%d", &snow -> snowflake[j]);
        }
        snowflake_code = code(snow -> snowflake);
        snow -> next = snowflakes[snowflake_code];
        snowflakes[snowflake_code] = snow;
    }
    identify_identical(snowflakes);
    free(snow);
    free(*snowflakes);
    return 0;
}
