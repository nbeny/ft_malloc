#ifndef MALLOC_H
# define MALLOC_H
# include "../ft_printf/include/ft_printf.h"
# include <stdlib.h>
# include <sys/mman.h>
# define TINY (2 * getpagesize() + sizeof(t_page))
# define SMALL (8 * getpagesize() + sizeof(t_page))
# define PROT (PROT_READ | PROT_WRITE)
# define MAP (MAP_ANON | MAP_PRIVATE)

typedef struct	s_page
{
	int						id;
	size_t					size;
	void					*whereami;
	void					*ptr;
	struct s_page			*prev;
	struct s_page			*next;
}				t_page;

typedef struct	s_ptr
{
	size_t			size;
	int				free;
	struct s_ptr	*next;
}				t_ptr;

typedef struct	s_pg
{
	int			id;
	size_t		size;
	size_t		tab[20];
	int			i;
	struct s_pg	*nxt;
}				t_pg;
/*
**globale
*/
//extern t_pg		g_pg;
t_page		*g_page;
//struct s_ptr	*g_ptr;

/*
**tools
*/
size_t	ft_power_of(size_t size);
/*
**page
*/
//t_ptr	*init_ptr(t_ptr *ptr, size_t size);
t_page	*init_page(size_t size, int id);
//t_page	*page_prev(t_page *page, t_page *s);
t_page	*add_page(size_t size, int id);
//t_page	*add_page_large(size_t size, int id);
/*
**ptr
*/
t_ptr	*init_ptr(t_ptr *ptr, size_t size);
void	*add_ptr(t_page *page, size_t size);
/*
**check
*/
int		check_page_tiny(size_t size);
int		check_page_small(size_t size);
/*
**tiny
*/
//int		check_page_tiny(size_t size);
//t_ptr	*add_ptr_tiny(size_t size, int id);
/*
**small
*/
//int		check_page_small(size_t size);
//t_ptr	*add_ptr_small(size_t size, int id);
/*
**malloc
*/
void	*ft_malloc(size_t size);
/*
**realloc
*/
//void	*ft_realloc(void *ptr, size_t size);
/*
**free
*/
void	ft_free(void *ptr);
/*
**print
*/
int		check_exist_id(int id);
void	print_tiny(void);
void	print_small(void);
void	print_large(void);
void	show_alloc_mem(void);
/*
t_pg	*init_page(size_t size, int id);
t_pg	*add_page(size_t size, int id);
int		check_page_tiny(size_t size);
int		check_page_small(size_t size);
t_pg	*get_ptr_tiny(t_pg *pg);
t_pg	*get_ptr_small(t_pg *pg);
void	*ft_malloc(size_t size);
void	show_alloc_mem(void);
*/
#endif
