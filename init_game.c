#include "gol.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void init_game(struct cell board[Y_AXIS][X_AXIS])
 DESCRIPTION: sets the starting population the grid
	Input: struct cell board[Y_AXIS][X_AXIS]
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void init_game(struct cell board[Y_AXIS][X_AXIS])
{
    /*starting point*/
    board[1][2].current = 1;
    board[2][2].current = 1;
    board[3][0].current = 1;
    board[3][3].current = 1;
    board[3][4].current = 1;
    board[4][3].current = 1;
    board[4][4].current = 1;
}