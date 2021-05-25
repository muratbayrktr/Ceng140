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
    int i,k,c,ind;
    int normalizer = count;
    for (i = 0; i < 3; i ++)
    {
        ind = arr[i] - i*normalizer;
        k = 0;
        for(c = count; c > 0; c--) 
        {
            while (*(sentence + ind + k) != '!') 
            {
                *(sentence + ind + k) = *(sentence + ind + k + count);
                /* normalizer = 3; */
                k++;
            }
        }
    }
    return ;
}

void addSome(char * sentence, int * arr, char * substr){
    int i = 0,sub_len = 0;
    int end,ind,j, normalizer;
    while (substr[i++] != '!') {
        sub_len++;
    }  
    normalizer = sub_len;
    for (i = 0; i < 3; i ++)
    {
        ind = arr[i] + normalizer*i;
        
        {
            end = 0;
            while (1) {
                if (sentence[end++] == '!') break;
            }
            while (end != ind) 
            {
                *(sentence + end + sub_len - 1 ) = *(sentence + end - 1);
                end--;
            }
            for (j = 0; j < sub_len; j++) {
                *(sentence + ind + j) = substr[j];
            }
        }
    }
    
    return ;
}

void battle_ship(char map[mapWidth][mapHeight], int prev_moves[prevCount][2], int next_moves[nextCount][2]){
    int i, j, n_ind = 0;
    i = j = 0;
    
    while ((prev_moves[i][0] != -1) || (prev_moves[i][1] != -1))
    {
        int y = prev_moves[i][0];
        int x = prev_moves[i][1];
        
        *(*(map + y)+x) = 'H';
        i++; 
    }
    
    for (i = 0; i < mapHeight; i++)
    {
        for (j = 0; j < mapWidth; j++)
        { 
            if (map[i][j] == 'X') {next_moves[n_ind][0] = i, next_moves[n_ind][1] = j, n_ind++;} 
        }
    }
    next_moves[n_ind][0] = -1, next_moves[n_ind][1] = -1;
    return ;
}
