#include "malloc.h"

t_page	*init_page(size_t size, int id)
{
	t_page	*page;

	if (!(page = (t_page *)mmap(0, size, PROT, MAP, -1, 0)))
		return (NULL);
	page->id = 0;
	if (id == 2)
		page->size = size;
	else
		page->size = 0;
	page->whereami = (void *)(page + sizeof(t_page));
	page->ptr = NULL;
	page->next = NULL;
	return (page);
}

t_page	*add_page(size_t size, int id)
{
	t_page	*s;

	s = g_page;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		if (id == 0)
			s->next = init_page(TINY, id);
		else if (id == 1)
			s->next = init_page(SMALL, id);
		else if (id == 2)
			s->next = init_page(size + sizeof(t_page), id);
		return (s);
	}
	else
	{
		if (id == 0)
			g_page = init_page(TINY, id);
		else if (id == 1)
			g_page = init_page(SMALL, id);
		else if (id == 2)
			g_page = init_page(size + sizeof(t_page), id);
		return (g_page);
	}
	return (NULL);
}
