#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAX_PRODUCTIONS 10

#define MAX_SYMBOLS 10

#define MAX_STATES 10

typedef struct {

 char lhs[20];

 char rhs[20];

} Production;

Production productions[MAX_PRODUCTIONS];

char symbols[MAX_SYMBOLS][20];

char parsing_table[MAX_STATES][MAX_SYMBOLS][20];

int num_productions = 0;

int num_symbols = 0;

int num_states = 0;

int is_terminal(char* symbol) {

 // TODO: Implement the logic to check if a symbol is a terminal

 return 0;

}
int is_non_terminal(char* symbol) {

 // TODO: Implement the logic to check if a symbol is a non-terminal

 return 0;

}

void add_symbol(char* symbol) {

 int i;

 for (i = 0; i < num_symbols; i++) {

 if (strcmp(symbol, symbols[i]) == 0) {

 return;

 }

 }

 strcpy(symbols[num_symbols], symbol);

 num_symbols++;

}

void add_state(char* symbol, char* action, int state) {

 int symbol_index = -1;

 int i;

 for (i = 0; i < num_symbols; i++) {

 if (strcmp(symbol, symbols[i]) == 0) {

 symbol_index = i;

 break;

 }

 }

 if (symbol_index == -1) {
strcpy(symbols[num_symbols], symbol);

 symbol_index = num_symbols;

 num_symbols++;

 }

 strcpy(parsing_table[state][symbol_index], action);

}

void build_parsing_table() {

 // TODO: Implement the construction of the parsing table

}

void print_parsing_table() {

 int i, j;

 printf("Parsing Table:\n");

 printf("--------------\n\n");

 printf(" |");

 for (i = 0; i < num_symbols; i++) {

 printf(" %s |", symbols[i]);

 }

 printf("\n");

 for (i = 0; i < num_states; i++) {

 printf(" %d|", i);

 for (j = 0; j < num_symbols; j++) {
printf(" %s |", parsing_table[i][j]);

 }

 printf("\n");

 }

}

int main() {

 int i;

 printf("Enter the number of productions: ");

 scanf("%d", &num_productions);

 printf("Enter the productions (in the form A->X):\n");

 for (i = 0; i < num_productions; i++) {

 scanf("%s", productions[i].lhs);

 scanf("%s", productions[i].rhs);

 add_symbol(productions[i].lhs);

 add_symbol(productions[i].rhs);

 }

 build_parsing_table();

 print_parsing_table();

 return 0;

}
