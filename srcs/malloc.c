#include "malloc.h"

void	*ft_malloc(size_t size)
{
	t_pg	*ptr;

	ptr = NULL;
	if (size <= 0 && size > (ft_power(2, 64) - 1))
		return (NULL);
	else if (size < 64)
	{
		ft_printf(2, "ZZZZZZZZZZZ%p\n", g_pg);
		if (!check_page_tiny(size))
		{
			ft_printf(2, "add_page\n");
			ptr = add_page(size, 0);
		}
		ft_printf(2, "\n---------------%d\n", g_pg->id);
		ptr = get_ptr_tiny(ptr);
	}
	else if (size >= 64 && size < 1024)
	{
		if (!check_page_small(size))
			ptr = add_page(size, 1);
		ptr = get_ptr_small(ptr);
	}
	else
	{
		ptr = add_page(size, 2);
	}
	if (ptr == NULL)
		return (NULL);
	ft_printf(2, "%pXXXXXXXXXXXX\n", g_pg);
	return ((void *)ptr);
}
