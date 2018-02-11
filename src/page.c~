#include "malloc.h"

t_page	*init_page(size_t size, int id)
{
	static t_page	*page = NULL;

	if (!(page = (t_page *)mmap(0, size + sizeof(t_page), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	page->id = id;
	page->ptr = NULL;
	page->addr = (size_t)page;
	page->next = NULL;
	page->prev = NULL;
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
