#include "malloc.h"

t_page		*check_page_tiny(size_t size)
{
	t_page	*s;

	s = g_page;
	while (s != NULL)
	{
//need add mac condition
		if (s->id == 0 && (size_t)((size_t)s->pos - (size_t)s->page) < size)
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
		if (s->id == 1 && (size_t)((size_t)s->pos - (size_t)s->page) < size)
			return (s);
		s = s->next;
	}
	return (NULL);
}