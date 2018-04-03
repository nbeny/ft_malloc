#include "malloc.h"

/*
**	id_TINY = 0;
**	id_SMALL = 1;
**	id_LARGE = 2;
*/

void	*ft_malloc(size_t size)
{
	void	*ptr;
	t_page	*page;

	ptr = NULL;
	page = NULL;
	if (size <= 0 || size > (ft_power(2, 64) - 1))
		return (NULL);
	else if (size < 64)
	{
		if (check_page_tiny(size))
			page = add_page(size, 0);
		if (page != NULL)
		{
			ft_printf(2, "new page\n");
			ptr = add_ptr(page, size);
		}
	}
	else if (size >= 64 && size < 4096)
	{
		if (check_page_small(size))
			page = add_page(size, 1);
		if (g_page != NULL)
		{
			ft_printf(2, "new page\n");
			ptr = add_ptr(page, size);
		}
	}
	else
	{
		ft_printf(2, "new page\n");
		page = add_page(size, 2);
		return ((void *)(page + sizeof(t_page)));
	}
	if (g_page == NULL)
		return (NULL);
	return ((void *)ptr);
}
