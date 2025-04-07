#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX 100 
 
int stack[MAX], top = -1; 
char input[MAX]; 
int i = 0, len; 
 
void push(int state) { 
    if (top < MAX - 1) 
        stack[++top] = state; 
    else 
        printf("Stack Overflow\n"); 
} 
 
void pop() { 
    if (top >= 0) 
        top--; 
    else 
        printf("Stack Underflow\n"); 
} 
 
int get_top() { 
    if (top >= 0) 
        return stack[top]; 
    return -1; 
} 
 
void display_stack() { 
    for (int j = 0; j <= top; j++) 
        printf("%d ", stack[j]); 
    printf("\n"); 
} 
 
int parse_slr() { 
    push(0); 
    printf("Stack\tInput\tAction\n"); 
 
    while (i < len) { 
        int state = get_top(); 
        printf("%d\t%s\t", state, input + i); 
 
        if (state == 0 && input[i] == 'i') { 
            push(5);  // Shift to state 5 
            printf("Shift to 5\n"); 
            i++; 
        } else if (state == 0 && input[i] == '(') { 
            push(4);  // Shift to state 4 
            printf("Shift to 4\n"); 
            i++; 
        } else if (state == 5 && input[i] == '+') { 
            pop();    // Reduce F -> id 
            pop(); 
            push(2);  // Goto state 2 
            printf("Reduce F -> id, Goto 2\n"); 
        } else if (state == 4 && input[i] == 'i') { 
            push(5);  // Shift to state 5 
            printf("Shift to 5\n"); 
            i++; 
        } else if (state == 2 && input[i] == '*') { 
            push(6);  // Shift to state 6 
            printf("Shift to 6\n"); 
            i++; 
        } else if (state == 6 && input[i] == 'i') { 
            push(5);  // Shift to state 5 
            printf("Shift to 5\n"); 
            i++; 
        } else if (state == 5 && (input[i] == '*' || input[i] == '+' || input[i] == ')')) { 
            pop();    // Reduce F -> id 
            pop(); 
            push(2);  // Goto state 2 
            printf("Reduce F -> id, Goto 2\n"); 
        } else if (state == 2 && input[i] == ')') { 
            pop(); 
            printf("Reduce E -> T\n"); 
            return 1;  // Successful parse 
        } else { 
            printf("Error: Invalid input\n"); 
            return 0; 
        } 
 
        display_stack(); 
    } 
    return 0; 
} 
 
int main() { 
    printf("Enter input string (e.g., i+i*i): "); 
    scanf("%s", input); 
    len = strlen(input); 
 
    if (parse_slr()) 
        printf("Parsing Successful!\n"); 
    else 
        printf("Parsing Failed!\n"); 
 
    return 0; 
} 
