#include "malloc.h"

struct s_pg		*g_pg = NULL;

void	*ft_malloc(size_t size)
{
	t_pg	*ptr;

	ptr = NULL;
	if (size <= 0)//&& size > (ft_power(2, 64) - 1))
		return (NULL);
	else if (size < 64)
	{
		if (!check_page_tiny(g_pg, size))
			ptr = add_page(g_pg, size, 0);
		ptr = get_ptr_tiny(ptr);
	}
	else if (size >= 64 && size < 1024)
	{
		if (!check_page_small(g_pg, size))
			ptr = add_page(g_pg, size, 1);
		ptr = get_ptr_small(ptr);
	}
	else
	{
		ptr = add_page(g_pg, size, 2);
	}
	if (ptr == NULL)
		return (NULL);
	return ((void *)ptr);
}
