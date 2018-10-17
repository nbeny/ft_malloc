#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_page
{
    int             id;
    int             size;
    struct s_ptr    *ptr;
    size_t          addr;
    struct s_page   *next;
    struct s_page   *prev;
}               t_page;

typedef struct  s_ptr
{
    int             id;
    int             size;
    int             free;
    size_t          addr;
    struct s_ptr    *next;
    struct s_ptr    *prev;
}               t_ptr;
/*
**globale
*/
struct s_page	*g_page;
//struct s_ptr    g_ptr;

t_page	*init_page(t_page *page)
{
	if(!(page = (t_page *)malloc(sizeof(t_page))))
		 return (NULL);
	page->size = 64;
	page->addr = (size_t)page;
	page->next = NULL;
	page->prev = NULL;
	return (page);
}



t_page	*add_page(t_page *page)
{
	t_page	*s;

	s = page;
	if (page == NULL)
		page = init_page(page);
	else
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_page(page);
	}
	return (page);
}

int		main(int ac, char **av)
{
	t_page	*s;

	g_page = add_page(g_page);
	g_page = add_page(g_page);
	g_page = add_page(g_page);
	g_page = add_page(g_page);
	g_page = add_page(g_page);
	g_page = add_page(g_page);
	g_page = add_page(g_page);
	g_page = add_page(g_page);
	g_page = add_page(g_page);
	g_page = add_page(g_page);
	s = g_page;
	while (s != NULL)
	{
		printf("%i\n", s->size);
		s = s->next;
	}
	return (0);
}
