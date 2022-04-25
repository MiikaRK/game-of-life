#include "gol.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void init_table(struct cell board[Y_AXIS][X_AXIS])
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void init_table(struct cell board[Y_AXIS][X_AXIS])
{
    move(0,0);
    
    for (int i = 0; i < Y_AXIS; i++)
    {
        for (int j = 0; j < X_AXIS; j++)
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