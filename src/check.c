#include "ft_malloc.h"

int     check_size_page(t_page *s, size_t size)
{
    if (s->end - s->addr > size)
        return (1);
    return (0);
}

void	*check_page_tiny(size_t size)
{
	t_page	*s;

	s = g_page;
	ft_printf(2, "%zu\n", size);
	while (s != NULL)
	{
//need add mac condition
//check if we can insert in page
		if (s->id == 0 && check_size_page(s, size))
			return ((void *)s);
		s = s->next;
	}
	ft_printf(2, "malloc_tiny\n");
	return (NULL);
}

void	*check_page_small(size_t size)
{
	t_page	*s;

	s = g_page;
	ft_printf(2, "%zu\n", size);
	while (s != NULL)
	{
//need add mac condition
//check if we can insert in page
		if (s->id == 1 && check_size_page(s, size))
			return ((void *)s);
		s = s->next;
	}
	ft_printf(2, "malloc_small\n");
	return (NULL);
}