#ifndef MALLOC_H
# define MALLOC_H
# include "../ft_printf/include/ft_printf.h"
# include <stdlib.h>
# include <sys/mman.h>

typedef struct	s_dop
{
	size_t			addr;
	struct s_dop	*next;
	struct s_dop	*prev;
}				t_dop;

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
#endif
