#ifndef MALLOC_H
# define MALLOC_H
# include "../ft_printf/include/ft_printf.h"
# include <stdlib.h>
# include <sys/mman.h>

typedef struct	s_page
{
	int				id;
	int				size;
	struct s_ptr	*ptr;
	size_t			addr;
	struct s_page	*next;
	struct s_page	*prev;
}				t_page;

typedef struct	s_ptr
{
	int				id;
	int				size;
	int				free;
	size_t			addr;
	struct s_ptr	*next;
	struct s_ptr	*prev;
}				t_ptr;
/*
**globale
*/
struct s_page	g_page;
struct s_ptr	g_ptr;
/*
**page
*/
t_page	*init_page(size_t page, int id);
t_page	*page_prev(t_page *page, t_page *s);
t_page	*add_page(t_page *page, size_t size, int id);

/*
**ptr
*/
t_ptr	*init_ptr(size_t size, int id);
t_ptr	*ptr_prev(t_ptr *ptr, t_ptr *s);
t_ptr	*add_ptr(t_ptr *ptr, size_t *size, int id);

/*
**alloc
*/


/*
**malloc
*/
void	*ft_malloc(size_t size);

/*
**realloc
*/
void	*ft_realloc(void *ptr, size_t size);

/*
**free
*/
void	ft_free(void *ptr);
#endif
