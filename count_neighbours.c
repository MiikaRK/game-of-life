#include "gol.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: int count_neighbours(int i, int j, struct cell board[Y_AXIS][X_AXIS])
 DESCRIPTION: Initializes cell's neighbours positions
	Input: i, j, struct cell board[Y_AXIS][X_AXIS]
	Output: count_neighbours() for calculate_game() - function
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
int count_neighbours(int i, int j, struct cell board[Y_AXIS][X_AXIS])
{
    int neigh;
    
    /*initializes neighbour cells*/
    neigh = board[i - 1][j - 1].current +
            board[i - 1][j    ].current +
            board[i - 1][j + 1].current +
            board[i    ][j - 1].current +
            board[i    ][j + 1].current +
            board[i + 1][j - 1].current +
            board[i + 1][j    ].current +
            board[i + 1][j + 1].current;
}