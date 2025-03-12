#include <stdio.h>
#include <ctype.h>

void FIRSTfunc(char);
int count = 0;
char prodn[10][10], firstTerms[10];

int main() {
    int i, choice;
    char c, ch;
    printf("How many productions? : ");
    scanf("%d", &count);

    printf("Enter %d productions epsilon = '$' :\n", count);
    for (i = 0; i < count; i++) {
        scanf("%s", prodn[i]);
    }

    do {
        n = 0;
        printf("\nElement : ");
        scanf(" %c", &c);
        FIRSTfunc(c);

        printf("\nFIRST(%c) = { ", c);
        for (i = 0; i < n; i++) {
            printf("%c ", firstTerms[i]);
        }
        printf("}\n");

        printf("Press 1 to continue: ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}

void FIRSTfunc(char c) {
    int i;
    if (!isupper(c)) {
        firstTerms[n++] = c;  // FIRST of terminal = itself
        return;
    }

    for (i = 0; i < count; i++) {
        if (prodn[i][0] == c) {
            if (prodn[i][2] == '$') {
                firstTerms[n++] = '$';  // Epsilon case
            } else if (islower(prodn[i][2])) {
                firstTerms[n++] = prodn[i][2];  // Terminal directly in production
            } else {
                FIRSTfunc(prodn[i][2]);  // Recursive call for non-terminal
            }
        }
    }
}
