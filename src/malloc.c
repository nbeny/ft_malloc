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
		if (!check_page_tiny(g_page, size))
		{
			ft_printf(2, "new_page_tiny\n");
			g_page = add_page(g_page, (size_t)getpagesize(), 0);
		}
		if (g_page != NULL)
		{
			ft_printf(2, "tiny\n");
			ptr = add_ptr_tiny(g_page, size, 0);
		}
	}
	else if (size >= 64 && size < 4096)
	{
		ft_printf(2, "small\n");
		if (!check_page_small(g_page, size))
		{
			ft_printf(2, "new_page_small\n");
			g_page = add_page(g_page, (size_t)getpagesize(), 1);
		}
		if (g_page != NULL)
		{
			ft_printf(2, "tiny\n");
			ptr = add_ptr_small(g_page, size, 1);
		}
	}
	else
	{
		ft_printf(2, "large\n");
		page = add_page_large(g_page, size, 2);
		return ((void *)page);
	}
	if (g_page == NULL)
		return (NULL);
	return ((void *)ptr);
}
