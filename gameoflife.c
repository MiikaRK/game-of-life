#include <stdio.h>

#define Y_AXIS 9
#define X_AXIS 9

struct cell
{
    int current;
    int future;
};

void init_table(struct cell board[Y_AXIS][X_AXIS]);
void init_game(struct cell board[Y_AXIS][X_AXIS]);
int count_neighbours(int i, int j, struct cell board[Y_AXIS][X_AXIS]);
void calculate_game(int i, int j, struct cell board[Y_AXIS][X_AXIS]);

int main(void)
{
    //i = y-axis & j = x-axis
    int i, j, neigh;

    struct cell board[Y_AXIS][X_AXIS] = {0, 0};

    init_game(board);

    for (i = 0; i < 10; i++)
    {
        init_table(board);

        calculate_game(i, j, board);

        printf("\n");
    }

    return 0;
}

/*****FUNCTIONS*****/

void init_game(struct cell board[Y_AXIS][X_AXIS])
{
    //starting point
    board[1][2].current = 1;
    board[2][2].current = 1;
    board[3][0].current = 1;
    board[3][3].current = 1;
    board[3][4].current = 1;
    board[4][3].current = 1;
    board[4][4].current = 1;
}

void init_table(struct cell board[Y_AXIS][X_AXIS])
{
    
    for (int i = 0; i < Y_AXIS; i++)
    {
        for (int j = 0; j < X_AXIS; j++)
        {
            if (board[i][j].current == 0)
            {
                printf(".");
            }

            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}

int count_neighbours(int i, int j, struct cell board[Y_AXIS][X_AXIS])
{
    int neigh;
    //i = y axis & j = x axis
    //neighbour cells
    neigh = board[i - 1][j - 1].current +
            board[i - 1][j    ].current +
            board[i - 1][j + 1].current +
            board[i    ][j - 1].current +
            board[i    ][j + 1].current +
            board[i + 1][j - 1].current +
            board[i + 1][j    ].current +
            board[i + 1][j + 1].current;

    //return neigh;
}

void calculate_game(int i, int j, struct cell board[Y_AXIS][X_AXIS])
{
    int neigh;

    for (i = 0; i < Y_AXIS; i++)
    {
        for (j = 0; j < X_AXIS; j++)
        {
            neigh = count_neighbours(i, j, board);

            //rules for cells
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
    }
    
    for (i = 0; i < Y_AXIS; i++)
    {
        for (j = 0; j < X_AXIS; j++)
        {
            board[i][j].current = board[i][j].future;
        }
    }
}