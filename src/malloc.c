#include "malloc.h"

/*
**	id_TINY = 0;
**	id_SMALL = 1;
**	id_LARGE = 2;
*/

void	*ft_malloc(size_t size)
{
	if (size <= 0 || size > (ft_power(2, 64) - 1))
		return (NULL);
	if (g_ptr != NULL)
		g_ptr = reload_list_ptr(g_ptr);
	if (g_page != NULL)
		g_page = reload_list_page(g_page);
	else if (size < 64)
	{
		if (!check_page_tiny(g_page, g_ptr, size))
			g_page = add_page_tiny(g_page, size, 0);
		if (page != NULL)
			g_ptr = add_ptr_tiny(g_page, g_ptr, size, 0);
	}
	else if (size >= 64 && size < 4096)
	{
		if (!check_page_small(g_page, g_ptr, size))
			g_page = add_page(g_page, size, 1);
		if (page != NULL)
			g_ptr = add_ptr_small(g_page, g_ptr, size, 1);
	}
	else
		g_page = add_page(g_page, size, 2);
	if (g_page == NULL)
		return (NULL);
	return ((void *)go_to_addr(g_page, g_ptr));
}
