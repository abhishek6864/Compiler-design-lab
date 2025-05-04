#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int label[20];
int no = 0;

int check_label(int k) {
    for (int i = 0; i < no; i++) {
        if (k == label[i]) return 1;
    }
    return 0;
}

int main() {
    FILE *fp1, *fp2;
    char fname[10], op[10];
    char operand1[8], operand2[8], result[8];
    int i = 0, j = 0;

    printf("\nEnter filename of the intermediate code: ");
    scanf("%s", fname);

    fp1 = fopen(fname, "r");
    fp2 = fopen("target.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("\nError opening the file");
        exit(0);
    }

    while (!feof(fp1)) {
        fprintf(fp2, "\n");
        fscanf(fp1, "%s", op);
        i++;

        if (check_label(i))
            fprintf(fp2, "\nlabel#%d", i);

        if (strcmp(op, "print") == 0) {
            fscanf(fp1, "%s", result);
            fprintf(fp2, "\n\tOUT %s", result);
        }

        else if (strcmp(op, "goto") == 0) {
            fscanf(fp1, "%s %s", operand1, operand2);
            fprintf(fp2, "\n\tJMP %s, label#%s", operand1, operand2);
            label[no++] = atoi(operand2);
        }

        else if (strcmp(op, "[]=") == 0) {
            fscanf(fp1, "%s %s %s", operand1, operand2, result);
            fprintf(fp2, "\n\tSTORE %s[%s], %s", operand1, operand2, result);
        }

        else if (strcmp(op, "uminus") == 0) {
            fscanf(fp1, "%s %s", operand1, result);
            fprintf(fp2, "\n\tLOAD -%s, R1", operand1);
            fprintf(fp2, "\n\tSTORE R1, %s", result);
        }

        else {
            switch (op[0]) {
                case '*':
                    fscanf(fp1, "%s %s %s", operand1, operand2, result);
                    fprintf(fp2, "\n\tLOAD %s, R0", operand1);
                    fprintf(fp2, "\n\tLOAD %s, R1", operand2);
                    fprintf(fp2, "\n\tMUL R1, R0");
                    fprintf(fp2, "\n\tSTORE R0, %s", result);
                    break;

                case '+':
                    fscanf(fp1, "%s %s %s", operand1, operand2, result);
                    fprintf(fp2, "\n\tLOAD %s, R0", operand1);
                    fprintf(fp2, "\n\tLOAD %s, R1", operand2);
                    fprintf(fp2, "\n\tADD R1, R0");
                    fprintf(fp2, "\n\tSTORE R0, %s", result);
                    break;

                case '-':
                    fscanf(fp1, "%s %s %s", operand1, operand2, result);
                    fprintf(fp2, "\n\tLOAD %s, R0", operand1);
                    fprintf(fp2, "\n\tLOAD %s, R1", operand2);
                    fprintf(fp2, "\n\tSUB R1, R0");
                    fprintf(fp2, "\n\tSTORE R0, %s", result);
                    break;

                case '/':
                    fscanf(fp1, "%s %s %s", operand1, operand2, result);
                    fprintf(fp2, "\n\tLOAD %s, R0", operand1);
                    fprintf(fp2, "\n\tLOAD %s, R1", operand2);
                    fprintf(fp2, "\n\tDIV R1, R0");
                    fprintf(fp2, "\n\tSTORE R0, %s", result);
                    break;

                case '%':
                    fscanf(fp1, "%s %s %s", operand1, operand2, result);
                    fprintf(fp2, "\n\tLOAD %s, R0", operand1);
                    fprintf(fp2, "\n\tLOAD %s, R1", operand2);
                    fprintf(fp2, "\n\tDIV R1, R0");
                    fprintf(fp2, "\n\tSTORE R0, %s", result);
                    break;

                case '=':
                    fscanf(fp1, "%s %s", operand1, result);
                    fprintf(fp2, "\n\tSTORE %s, %s", operand1, result);
                    break;

                case '>':
                    j++;
                    fscanf(fp1, "%s %s %s", operand1, operand2, result);
                    fprintf(fp2, "\n\tLOAD %s, R0", operand1);
                    fprintf(fp2, "\n\tJGT %s, label#%s", operand2, result);
                    label[no++] = atoi(result);
                    break;

                case '<':
                    fscanf(fp1, "%s %s %s", operand1, operand2, result);
                    fprintf(fp2, "\n\tLOAD %s, R0", operand1);
                    fprintf(fp2, "\n\tJLT %s, label#%s", operand2, result);
                    label[no++] = atoi(result);
                    break;
            }
        }
    }

    fclose(fp2);
    fclose(fp1);

    // Display the generated machine code
    fp2 = fopen("target.txt", "r");
    if (fp2 == NULL) {
        printf("Error opening the output file\n");
        exit(0);
    }

    char ch;
    while ((ch = fgetc(fp2)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp2);
    return 0;
}
