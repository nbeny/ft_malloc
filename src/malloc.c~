#include "malloc.h"

/*
**	id_TINY = 0;
**	id_SMALL = 1;
**	id_LARGE = 2;
*/

void	*ft_malloc(size_t size)
{
	static t_page	*page = NULL;
	static t_ptr	*ptr = NULL;

	if (size <= 0 || size > ((2^64) - 1))
		return (NULL);
	if ( ptr != NULL)
		ptr = reload_list_ptr(ptr);
	if (page != NULL)
		page = reload_list_page(page);
	else if (size < 64)
	{
		if (!check_page_tiny(page, ptr, size))
			page = add_page_tiny(page, size, 0);
		if (page != NULL)
			ptr = add_ptr_tiny(page, ptr, size, 0);
	}
	else if (size >= 64 && size < 4096)
	{
		if (!check_page_small(page, ptr, size))
			page = add_page(page, size, 1);
		if (page != NULL)
			ptr = add_ptr_small(page, ptr, size, 1);
	}
	else
		page = add_page(page, size, 2);
	if (page == NULL)
		return (NULL);
	return ((void *)go_to_addr(page, ptr));
}
