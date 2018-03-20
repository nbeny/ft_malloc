#include "malloc.h"

int		check_page_tiny(t_pg *g_pg, size_t size)
{
	t_pg	*s;

	s = g_pg;
	while (s != NULL)
	{
		if (s->id == 0 && s->size < 24)
			return (1);
		s = s->nxt;
	}
	return (0);
}

int		check_page_small(t_pg *g_pg, size_t size)
{
	t_pg	*s;

	s = g_pg;
	while (s != NULL)
	{
		if (s->id == 1 && s->size < 3)
			return (1);
		s = s->nxt;
	}
	return (0);
}

t_pg	*get_ptr_tiny(t_pg *ptr)
{
	size_t	i;

	i = ptr->size;
	while (i != 0)
	{
		ptr += sizeof(t_pg) + 100;
		i -= 1;
	}
	return ((void *)ptr);
}

t_pg	*get_ptr_small(t_pg *ptr)
{
	size_t	i;

	i = ptr->size;
	while (i != 0)
	{
		ptr += sizeof(t_pg) + 100;
		i -= 1;
	}
	return ((void *)ptr);
}
