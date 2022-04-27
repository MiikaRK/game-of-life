#include "gol.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void calculate_game(int i, int j, struct cell board[Y_AXIS][X_AXIS])
 DESCRIPTION: Calculates the rules for population surviving or dying 
	Input: i, j, struct cell board[Y_AXIS][X_AXIS]
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void calculate_game(int i, int j, struct cell board[Y_AXIS][X_AXIS])
{
    int neigh;

    for (i = 0; i < Y_AXIS; i++)
    {
        for (j = 0; j < X_AXIS; j++)
        {
            neigh = count_neighbours(i, j, board);

            /*rules for cells*/
            if (board[i][j].current == 1 && neigh < 2)
            {
                board[i][j].future = 0;
            }
            else if (board[i][j].current == 1 && neigh >= 4)
            {
                board[i][j].future = 0;
            }
            else if (board[i][j].current == 1 && neigh == 2 || neigh == 3)
            {
                board[i][j].future = 1;
            }
            else if (board[i][j].current == 0 && neigh == 3)
            {
                board[i][j].future = 1;
            }
        }
    
    refresh();
    }
    
    for (i = 0; i < Y_AXIS; i++)
    {
        for (j = 0; j < X_AXIS; j++)
        {
            board[i][j].current = board[i][j].future;
        }
    }
    
    refresh();
}