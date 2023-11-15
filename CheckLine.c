#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prefix_length(char s1[], char s2[]) {
    int i = 1;
    while (s1[i] == s2[i])
        i++;
    return i - 1;
}

int suffix_length(char s1[], char s2[], int len) {
    int i = len;
    while (i >= 2 && s1[i] == s2[i-1])
        i--;
    return len - i;
}


#define SIZE 1000000
int main(void) {
    static char s1[SIZE + 2], s2[SIZE + 2];
    int len, prefix, suffix, total;
    gets(&s1[1]);
    gets(&s2[1]);
    len = strlen(&s1[1]);
    prefix = prefix_length(s1, s2);
    suffix = suffix_length(s1, s2, len);
    total = (prefix + 1) - (len - suffix) + 1;
    if (total < 0)
        total = 0;
    printf("%d\n", total);
    for (int i = 0; i < total; i++) {
        printf("%d", i + len - suffix);
        if (i < total - 1)
        printf(" ");
        else
        printf("\n");
    }
    return 0;
}


/* WITH JAVA

import java.util.*;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);


    public static void main(String[] args) {
        String input = scanner.nextLine();
        String correct = scanner.nextLine();

        removeSymbol(input, correct);
    }

    private static void removeSymbol(String input, String correct) {
        int lengthInput = input.length();
        int lengthCorrect = correct.length();

        int start = 0;
        int end = lengthInput - 1;


        while(start < lengthCorrect && correct.charAt(start) == input.charAt(start)) {
            start++;
        }

        while (end >= 1 && correct.charAt(end - 1) == input.charAt(end)) {
            end--;
        }

        int prefixLength = start;
        int suffixLength = lengthInput - end - 1;

        int total = (prefixLength + 1) - (lengthInput - suffixLength) + 1;

        if (total < 0) {
            total = 0;
        }
        System.out.println(total);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < total; i++) {
            sb.append(i + lengthInput - suffixLength);
            if (i < total - 1)
                sb.append(" ");
            else
                sb.append("\n");
        }
        System.out.println(sb);
    }
}


*/