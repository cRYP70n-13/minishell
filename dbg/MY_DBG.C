///////////////////////////

// # include <stdio.h>
// # include <stdlib.h>
# include <stdbool.h>
# include "minishell.h"
# include "my_dbg.h"

///////////////////////////

void exitfunc(int sig)
{
    _exit(0);
}

void    ft_exitTime(int argc, char **argv)
{
    int exitTime;

    exitTime = 20;
    if (argv[1][0] == 't' && argv[1][1] == '=')
        exitTime = atoi(&argv[1][2]);
    signal(SIGALRM, exitfunc);
    alarm(exitTime);
}

bool    nothing() {return 0;} //Yeah, I know..

void    debugMem(void *mem)
{
    ;
}