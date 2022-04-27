#include "gol.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void init_table(struct cell board[Y_AXIS][X_AXIS])
 DESCRIPTION: Prints the defined starting population to the screen
	Input: struct cell board[Y_AXIS][X_AXIS]
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void init_table(struct cell board[Y_AXIS][X_AXIS])
{
    int i, j;
    
    move(0,0);
    
    for (i = 0; i < Y_AXIS; i++)
    {
        for (j = 0; j < X_AXIS; j++)
        {
            if (board[i][j].current == 0)
            {
                printw(".");
                refresh();
            }

            else
            {
                printw("0");
                refresh();
            }
        }
        printw("\n");
    }
}