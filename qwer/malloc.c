#include "malloc.h"

void	*ft_malloc(size_t size)
{
	t_page	*page;

	page = init_page();
	if (size < 1 && size > (ft_power(2, 64) - 1))
		return (NULL);
	else if (size < 64)
	{
		if (!check_page_tiny(page, size))
			page = add_page(page, size, 0);
		if (page != NULL)
			;
	}
	else if (size >= 64 && size < 1024)
	{
		
	}
	else
	{
		
	}
	return ((void *));
}
