#include "malloc.h"

t_page	*init_page()
{
	static t_page	*page = NULL;

	return (page);
}

t_ptr	*init_ptr()
{
	static t_ptr	*ptr = NULL;

	return (ptr);
}

void	*ft_malloc(size_t size)
{
	t_page	*page;

	page = init_page();
	if (size <= 0 && size < ft_power(2, 64) - 1)
		return (NULL);
	else if (size < 64)
	{
		if (check_page_tiny(page, size))
			page = add_page(page, TINY, 0);
	}
	else if (size >= 64 && size < 1024)
	{
		if (check_page_small(page, size, 1))
			page = add_page(page, SMALL, 1);
	}
	else
	{
		
	}
	return ((void *));
}
