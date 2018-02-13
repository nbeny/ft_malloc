#include "malloc.h"

t_page	*init_page(size_t size, int id)
{
	if (!(g_page = (t_page *)mmap(0, size + sizeof(t_page), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	g_page->id = id;
	g_page->ptr = NULL;
	g_page->addr = (size_t)g_page;
	g_page->next = NULL;
	g_page->prev = NULL;
	return (page);
}

t_page	*page_prev(t_page *page, t_page *s)
{
	t_page	*pv;

	pv = page;
	while (pv->next->next != NULL)
		pv = pv->next;
	s->prev = pv;
	return (page);
}

t_page	*add_page(t_page *page, size_t size, int id)
{
	t_page	*s;
	t_page	*pr;

	pr = page;
	s = page;
	if (page == NULL)
	{
		if (!(page = init_page(size, id)))
			return (NULL);
	}
	else
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_page(size, id);
		s = s->next;
		if (page->next != NULL)
			page = do_prev(page, s);
	}
	return (page);
}
