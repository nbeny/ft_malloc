#include "malloc.h"

t_pg	*init_page(size_t size, int id)
{
	t_pg	*page;

	if (!(page = (t_pg *)mmap(0, getpagesize() + sizeof(t_pg),\
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	page->id = id;
	ft_printf(2, "page->id = %d\n", page->id);
	ft_printf(2, "id = %d\n", id);
	page->size = 0;
	if (id == 2)
		page->size = size;
	page->i = 0;
	while (page->i < 20)
	{
		page->tab[page->i] = 0;
		page->i++;
	}
	page->i = 0;
	page->nxt = NULL;
	return (page);
}

t_pg	*add_page(size_t size, int id)
{
	t_pg	*page;

	page = g_pg;
	if (g_pg == NULL)
	{
		ft_printf(2, "g_pg == NULL\n");
		g_pg = init_page(size, id);
			ft_printf(2, "\nOOPS**********************%d\n", g_pg->id );
		return (g_pg);
	}
	else
	{
		ft_printf(2, "g_pg != NULL\n");
		while (page->nxt != NULL)
			page = page->nxt;
		page->nxt = init_page(size, id);
		page = page->nxt;
		return (page);
	}
	return (NULL);
}
