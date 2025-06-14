#include "so_long.h"

int check_map(char *arg)
{
    int i;
    int exits;
    int player;
    int colectables;

    i = open(arg, O_RDONLY);
    exits = 0;
    player = 0;
    colectables = 0;
    if (exit != 1)
    {
        printf("more than 1 or no exit\n");
        return(1);
    }
    if (player != 1)
    {
        printf("more than 1 or no player\n");
        return(1);
    }
    if (colectables < 1)
    {
        printf("must be at least one colectable\n");
        return(1);
    }
}