#include "stdio.h"
#include "lab2_copy.h"

/* TASK SOLUTIONS */
/* done */
void to_lower(char * sentence){
    int i=0; char * c = (sentence + i);
    do {
        if ((*c >= 'A') && (*c <= 'Z')) *c += 32;
    } while (*(c = (sentence + i++)) != '!' );
    return ;
}
/* done */
void print_sentence(char * sentence){
    int i=0; char c = *(sentence + i++);
    do {
        putchar(c);
    } while ((c = *(sentence + i++)) != '!' );
    printf("\n");
    return ;
}
/* done */
void substrings(char * sentence, char * substr, int * arr){
    int i=0, index = 0; char * c; 
    while (*(c = (sentence + i++)) != '!')
    {
        if (*c == substr[0])
        {
            int k = 0;
            int check = 1;
            while (substr[k] != '!') 
            {
                if (substr[k] != *(c+k)) {check = 0; break;}
                k++;
            }
            if (check) {
                arr[index++] = i - 1;
            }
        }
    }

    return ;
}

void removeX(char * sentence, int * arr, int count){

    return ;
}

void addSome(char * sentence, int * arr, char * substr){
    return ;
}

void battle_ship(char map[mapWidth][mapHeight], int prev_moves[prevCount][2], int next_moves[nextCount][2]){
    return ;
}
