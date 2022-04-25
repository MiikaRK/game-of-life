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