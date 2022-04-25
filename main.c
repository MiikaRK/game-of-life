#include "gol.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void)
{
    initscr();
    clear();

    noecho();
    
    //i = y-axis & j = x-axis
    int i, j, neigh;

    struct cell board[Y_AXIS][X_AXIS] = {0, 0};

    init_game(board);

    for (i = 0; i < 30; i++)
    {
        init_table(board);

        sleep(1);

        calculate_game(i, j, board);

        printw("\n");
    }

    getch();
    endwin();

    return 0;
} /* end of main */