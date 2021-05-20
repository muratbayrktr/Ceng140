#include "stdio.h"
#include "lab2_copy.h"

/* TASK SOLUTIONS */

void to_lower(char * sentence){
    return ;
}

void print_sentence(char * sentence){
    int i=0; char c = *(sentence + i++);
    do {
        putchar(c);
    } while ((c = *(sentence + i++)) != '!' );
    printf("\n");
    return ;
}

void substrings(char * sentence, char * substr, int * arr){
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
