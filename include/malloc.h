#ifndef MALLOC_H
# define MALLOC_H
# include "../ft_printf/include/ft_printf.h"
# include <stdlib.h>
# include <sys/mman.h>

static struct s_page *page = init_page();

typedef struct	s_page
{
	struct s_ptr	*ptr;
	size_t			addr;
	struct s_page	*next;
	struct s_page	*prev;
}				t_page;

typedef struct	s_ptr
{
	size_t			addr;
	struct s_ptr	*next;
	struct s_ptr	*prev;
}				t_ptr;

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
#endif
