#include<stdio.h>
#include<string.h>

char prod[7][10] = {"S", "A", "A", "B", "B", "C", "C"};
char prod1[7][10] = {"aA", "bA","cAd","AB","d","Cc","@"};
char first[7][10] = {"a","b","c","a","d","c","@"};
char follow[7][10]= {"$","d","a$","a$", "d$","c$","d$"};
char table[5][6][10];

int numbr (char c){
    switch(c){
        case 'S': return 0;
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case '$': return 4;
    }
    return 5;
}

int main(){
    int i, j, k;
    for(i = 0; i <5;i++){
        for(j = 0; j <6; j++){
            strcpy(table[i][j], " ");
        }
    }
    
    printf("The following grammar is used for parsing table:\n");
    
    for(i = 0; i < 7; i++){
        printf("%s->%s\n", prod[i],prod1[i]);
    }
    printf("\nPredective parsing table:\n");
    
    for(i = 0; i < 7; i++){
        k = strlen(first[i]);
        for(j = 0; j < k; j++){
            if(first[i][j] != '@'){
                strcpy(table[numbr(prod[i][0])+1][numbr(follow[i][j])+1], prod1[i]);
            }
        }
        }
        
        for(i = 0; i < 7; i++){
            if(strlen(first[i]) == 1 && first[i][0] == '@'){
                k = strlen(follow[i]);
                for(j = 0; j <k;j++){
                    strcpy(table[numbr(prod[i][0]) +1][numbr(follow[i][j])+1], prod1[i]);
                }
            }
        }
        
        strcpy(table[0][0], " ");
        strcpy(table[0][1], "a");
        strcpy(table[0][2], "b");
        strcpy(table[0][3], "c");
        strcpy(table[0][4], "d");
        strcpy(table[0][5], "$");
        strcpy(table[1][0], "S");
        strcpy(table[2][0], "A");
        strcpy(table[3][0], "B");
        strcpy(table[4][0], "C");
        
        printf("\n---------------------------------------------------------\n");
        for(i = 0; i <5; i++){
            for(j = 0 ; j < 6; j++){
                printf("%-10s",table[i][j]);
                if(j == 5)
                 printf("\n---------------------------------------------------------\n");
            }
            
                       
        }
        
        return 0;
}
