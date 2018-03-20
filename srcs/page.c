#include "malloc.h"

t_pg	*init_page(size_t size, int id)
{
	t_pg	*page;

	if (!(page = (t_pg *)mmap(0, getpagesize() + sizeof(t_pg),\
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	page->id = id;
	page->size = 0;
	page->free = 0;
	page->nxt = NULL;
	return (page);
}

t_pg	*add_page(t_pg *g_pg, size_t size, int id)
{
	t_pg	*page;

	page = g_pg;
	if (g_pg == NULL)
	{
		if (!(g_pg = init_page(size, id)))
			return (NULL);
		return (g_pg);
	}
	else
	{
		while (page->nxt != NULL)
			page = page->nxt;
		if(!(page->nxt = init_page(size, id)))
			return (NULL);
		page = page->nxt;
		return (page);
	}
	return (NULL);
}
