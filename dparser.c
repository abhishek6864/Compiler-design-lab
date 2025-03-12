#include<stdio.h>
#include<conio.h>
#include<string.h>

char input[100]; 
int i = 1;

int EO();
int FO();
int EPO();
int TO();
int TPO();

int main() {
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nE -> TE\nE -> TE' @ \nT -> FT\nT -> FT' @ \nF -> (E) | ID\n");
    printf("\nEnter the string to be checked: ");
    gets(input);

    if (EO()) {
        if (input[i] == '\0')
            printf("\nString is accepted");
        else
            printf("\nString is not accepted");
    } else {
        printf("\nString is not accepted");
    }

    getch();
    return 0;
}

int EO() {
    if (TO()) {
        if (EPO())
            return 1;
        else
            return 0;
    } else {
        return 0;
    }
}

int EPO() {
    if (input[i] == '+') {
        i++;
        if (TO()) {
            if (EPO())
                return 1;
            else
                return 0;
        } else {
            return 0;
        }
    } else {
        return 1;  // ε production
    }
}

int TO() {
    if (FO()) {
        if (TPO())
            return 1;
        else
            return 0;
    } else {
        return 0;
    }
}

int TPO() {
    if (input[i] == '*') {
        i++;
        if (FO()) {
            if (TPO())
                return 1;
            else
                return 0;
        } else {
            return 0;
        }
    } else {
        return 1;  // ε production
    }
}

int FO() {
    if (input[i] == '(') {
        i++;
        if (EO()) {
            if (input[i] == ')') {
                i++;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
        i++;
        return 1;
    } else {
        return 0;
    }
}
