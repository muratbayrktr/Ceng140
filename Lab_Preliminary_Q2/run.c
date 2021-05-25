#include <stdio.h>
#include "lab2_copy.h"

int main()
{
    char map[mapHeight][mapWidth] = {{'.','.','X','X','X'}, {'X','X','.','.','.'}, {'.', '.', '.', '.', '.'}, {'X', 'X', 'X', '.', 'X'}, {'.', '.', '.', '.', 'X'}};

	int prev_moves[prevCount][2] = {{0,2}, {0,3}, {0,4}, {1,1}, {4,4}, {2,2}, {2,3}, {3,1}, {3,2}, {2,4}, {-1,-1}};

	int next_moves[nextCount][2];

	int i =0;

	battle_ship(map, prev_moves, next_moves);

    while ((next_moves[i][0] != -1) || (next_moves[i][1] != -1))
    {
        int y = next_moves[i][0];
        int x = next_moves[i][1];
        printf("(y,x) = %d,%d\n",y,x);
        i++; 
    }
    return 0;
}