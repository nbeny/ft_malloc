#include "malloc.h"

void	*ft_malloc(size_t size)
{
	t_pg	*ptr;

	ptr = NULL;
	if (size <= 0 && size > (ft_power(2, 64) - 1))
		return (NULL);
	else if (size < 64)
	{
		ft_printf(2, "tiny\n");
		if (!check_page_tiny(g_pg, size))
			ptr = add_page(g_pg, size, 0);
		ptr = get_ptr_tiny(ptr);
	}
	else if (size >= 64 && size < 1024)
	{
		ft_printf(2, "small\n");
		if (!check_page_small(g_pg, size))
			ptr = add_page(g_pg, size, 1);
		ptr = get_ptr_small(ptr);
	}
	else
	{
		ft_printf(2, "large\n");
		ptr = add_page(g_pg, size, 2);
		ft_printf(2, "%p\n", ptr);
	}
	if (ptr == NULL)
		return (NULL);
	return ((void *)ptr);
}
