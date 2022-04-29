/***************************************************************************
 *   Copyright (C) 2022 by Miika Rinta-Korkeamäki  *
 *   miikark@nic.fi   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME

    Game Of Life

 2.  DESCRIPTION

    Simplest evolution model by John Conway

 3.  VERSIONS
       Original:
         26.4.2022 / MRK
         29.4.2022 / MRK

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
/* Control flags */
#define DEBUG

/* Global constants */
#define Y_AXIS 9
#define X_AXIS 9
#define COLUMN 9

/* Global variables */

/* Global structures */

struct cell
{
    int current;
    int future;
};

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
void init_table(struct cell board[Y_AXIS][X_AXIS]);
void init_game(struct cell board[Y_AXIS][X_AXIS]);
int count_neighbours(int i, int j, struct cell board[Y_AXIS][X_AXIS]);
void calculate_game(int i, int j, struct cell board[Y_AXIS][X_AXIS]);

/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/

int main(void)
{
    // i = y-axis & j = x-axis
    int i, j, num;

    // start ncurses
    initscr();
    clear();

    noecho();

    // asks user input how many rounds program do
    printw("Insert number of rounds: ");
    scanw("%d", &num);

    struct cell board[Y_AXIS][X_AXIS] = {0, 0};

    init_game(board);

    for (i = 0; i < num; i++)
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

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

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
    // HARDCODED STARTING POSITION (alternative)
    
    /*board[1][2].current = 1;
    board[2][2].current = 1;
    board[3][0].current = 1;
    board[3][3].current = 1;
    board[3][4].current = 1;
    board[4][3].current = 1;
    board[4][4].current = 1;*/

    FILE *fp;
    char state_c;
    int state, j = 0, i = 0;

    fp = fopen("gameoflife.txt", "r");

    while (!feof(fp))
    {
        fscanf(fp, "%c", &state_c);
        state = state_c - '0';

        board[i][j].current = state;

        j++;

        if (j == COLUMN)
        {
            i++;
            j = 0;

            fscanf(fp, "%c", &state_c);             
        }
    }
}

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
    move(0, 0);

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

    // initializes neighbour cells
    neigh = board[i - 1][j - 1].current +
            board[i - 1][j    ].current +
            board[i - 1][j + 1].current +
            board[i    ][j - 1].current +
            board[i    ][j + 1].current +
            board[i + 1][j - 1].current +
            board[i + 1][j    ].current +
            board[i + 1][j + 1].current;
}

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

            // rules for cells
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