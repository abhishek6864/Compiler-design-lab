#include <stdio.h>
#include <string.h>

int m = 0, n = 0, i = 0, j = 0;
char a[10][10], followResult[10];

void follow(char c);
void first(char c);
void addToResult(char);

int main() {
    int choice;
    char c, ch;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter %d productions:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    do {
        m = 0;
        printf("\nFind FOLLOW of --> ");
        scanf(" %c", &c);
        follow(c);

        printf("\nFOLLOW(%c) = { ", c);
        for (i = 0; i < m; i++) {
            printf("%c ", followResult[i]);
        }
        printf("}\n");

        printf("Do you want to continue (Press 1 to continue)? ");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}

void follow(char c) {
    if (a[0][0] == c)
        addToResult('$');

    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}

void first(char c) {
    int i;
    if (!isupper(c)) {
        addToResult(c);
    }

    for (i = 0; i < n; i++) {
        if (a[i][0] == c) {
            if (a[i][2] == '$')
                addToResult('$');
            else if (islower(a[i][2]))
                addToResult(a[i][2]);
            else
                first(a[i][2]);
        }
    }
}

void addToResult(char c) {
    int i;
    for (i = 0; i < m; i++)
        if (followResult[i] == c)
            return;
    followResult[m++] = c;
}
