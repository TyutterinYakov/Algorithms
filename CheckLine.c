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

        int endPreffix = 0;
        int startSuffix = lengthInput - 1;


        while(endPreffix < lengthCorrect && correct.charAt(endPreffix) == input.charAt(endPreffix)) {
            endPreffix++;
        }

        while (startSuffix >= 1 && correct.charAt(startSuffix - 1) == input.charAt(startSuffix)) {
            startSuffix--;
        }

        int suffixLength = lengthInput - startSuffix - 1;

        int total = endPreffix - startSuffix + 1;

        if (total < 0) {
            total = 0;
        }
        System.out.println(total);

        if (total > 0) {
            StringBuilder sb = new StringBuilder();
            sb.append(lengthInput - suffixLength);
            for (int i = 1; i < total; i++) {
                sb.append(" ").append(i + lengthInput - suffixLength);
            }
            sb.append("\n");
            System.out.println(sb);
        }
    }
}
*/