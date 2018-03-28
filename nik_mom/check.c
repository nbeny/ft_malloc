#include "malloc.h"

int		check_page_tiny(t_page *page, size_t size)
{
	t_page	*s;

	s = page;
	while (s != NULL)
	{
		if (s->id == 0)
			return (-1);
		s = s->next;
	}
	return (0);
}

int		check_page_small(t_page *page, size_t size)
{
	t_page	*s;

	s = page;
	while (s != NULL)
	{
		if (s->id == 1)
			return (-1);
		s = s->next;
	}
	return (0);
}
