#include <stdio.h>

int main() {
    int a, count = 0;

    printf("Enter the number of characters in the expression::\n");
    scanf("%d", &a);
    char c[a];

    printf("Enter the expression::");
    for (int i = 0; i < a; i++) {
        scanf(" %c", &c[i]);

        if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '>' || 
            c[i] == '<' || c[i] == '/' || c[i] == '=') {
            count++;
        }
    }

    printf("The number of operators in the expression are: %d", count);
    return 0;
}
