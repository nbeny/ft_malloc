#include "malloc.h"

/*
**	id_TINY = 0;
**	id_SMALL = 1;
**	id_LARGE = 2;
*/

void	*ft_malloc(size_t size)
{
	static t_page	*page = NULL;

	if (size <= 0 || size > 18446744073709551615)
		return (NULL);
	else if (size < 64)
	{
		
	}
	else if (size >= 64 && size < 4096)
	{
		
	}
	else
		page = add_page(page, size, 2);
	if (page == NULL)
		return (NULL);
	return ((void *)go_to_addr(page));
}
