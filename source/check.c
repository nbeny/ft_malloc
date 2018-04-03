#include "malloc.h"

int		check_page_tiny(size_t size)
{
	t_page	*s;

	s = g_page;
	ft_printf(2, "%zu\n", size);
	while (s != NULL)
	{
//need add mac condition
		if (s->id == 0)
			return (0);
		s = s->next;
	}
	ft_printf(2, "malloc_tiny\n");
	return (1);
}

int		check_page_small(size_t size)
{
	t_page	*s;

	s = g_page;
	ft_printf(2, "%zu\n", size);
	while (s != NULL)
	{
//need add mac condition
		if (s->id == 1)
			return (0);
		s = s->next;
	}
	ft_printf(2, "malloc_small\n");
	return (1);
}
