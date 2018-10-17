#include "malloc.h"

/*
**	id_TINY = 0;
**	id_SMALL = 1;
**	id_LARGE = 2;
*/

void	*ft_malloc(size_t size)
{
	t_ptr	*ptr;
	t_page	*page;

	ptr = NULL;
	page = NULL;
	if (size <= 0 || size > (ft_power(2, 64) - 1))
		return (NULL);
	else if (size < 64)
	{
		if (!check_page_tiny(size))
			g_page = add_page((size_t)getpagesize(), 0);
		if (g_page != NULL)
			ptr = add_ptr_tiny(g_page, size, 0);
	}
	else if (size >= 64 && size < 4096)
	{
		if (!check_page_small(g_page, size))
			g_page = add_page(g_page, (size_t)getpagesize(), 1);
		if (g_page != NULL)
			ptr = add_ptr_small(g_page, size, 1);
	}
	else
	{
		page = add_page_large(g_page, size, 2);
		return ((void *)page);
	}
	if (g_page == NULL)
		return (NULL);
	return ((void *)ptr);
}
