#include "malloc.h"

t_page		*check_page_tiny(size_t size)
{
	t_page	*s;

	s = g_page;
	while (s != NULL)
	{
//need add mac condition
		ft_printf(2, "[%zu] - [%zu] = {%zu} < [%zu]\n", (size_t)s->pos, (size_t)s->page, (size_t)((size_t)s->pos - (size_t)s->page), TINY);
		if (s->id == 0 && ((size_t)s->page + TINY) - (size_t)s->pos > size + sizeof(t_ptr))
			return (s);
		s = s->next;
	}
	return (NULL);
}

t_page		*check_page_small(size_t size)
{
	t_page	*s;

	s = g_page;
	while (s != NULL)
	{
//need add mac condition
		ft_printf(2, "[%zu] - [%zu] = {%zu} < [%zu]\n", (size_t)s->pos, (size_t)s->page, (size_t)((size_t)s->pos - (size_t)s->page), SMALL);
		if (s->id == 1 && ((size_t)s->page + SMALL) - (size_t)s->pos > size + sizeof(t_ptr))
			return (s);
		s = s->next;
	}
	return (NULL);
}