#include "malloc.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (size <= 0 && size > (ft_power(2, 64) - 1))
		return (NULL);
	else if (size < 64)
	{
		if (!check_page_tiny(size))
			g_pg = add_page(size, 0);
		ptr = get_ptr_tiny();
	}
	else if (size >= 64 && size < 2048)
	{
		if (!check_page_small(size))
			g_pg = add_page(size, 1);
		ptr = get_ptr_small();
	}
	else
	{
		g_pg = add_page_large(size, 2);
	}
	if (g_pg == NULL)
		return (NULL);
	return (ptr);
}
