#ifndef MALLOC_H
# define MALLOC_H
# include "../ft_printf/include/ft_printf.h"
# include <stdlib.h>
# include <sys/mman.h>
# define TAB (4 * getpagesize())
# define TINY (2 * getpagesize())
# define SMALL (8 * getpagesize())
# define PROT (PROT_READ | PROT_WRITE)
# define MAP (MAP_ANON | MAP_PRIVATE)

typedef struct	s_page
{
    int             id;
    size_t          page;
    size_t          addr;
	struct s_page	*next;
}				t_page;

t_page  *g_page;
/*
**malloc.c
*/
void    *ft_malloc(size_t size);
/*
**tools.c
*/
size_t	ft_power_of(size_t size);
/*
**check
*/
int		check_page_tiny(size_t size);
int		check_page_small(size_t size);
#endif