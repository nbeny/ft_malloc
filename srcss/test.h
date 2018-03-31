#ifndef MALLOC_H
# define MALLOC_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct      s_var
{
    int             i;
    char            *s;
    struct s_var    *next;
}               t_var;

struct s_var        *g_var;

void    ft_extern(void);
#endif
