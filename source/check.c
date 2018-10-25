#include "malloc.h"

int		check_page_tiny(size_t size)
{
	t_page	*s;

	s = g_page;
	while (s != NULL)
	{
//need add mac condition
		if (s->id == 0)
			return (0);
		s = s->next;
	}
	return (1);
}

int		check_page_small(size_t size)
{
	t_page	*s;

	s = g_page;
	while (s != NULL)
	{
//need add mac condition
		if (s->id == 1)
			return (0);
		s = s->next;
	}
	return (1);
}