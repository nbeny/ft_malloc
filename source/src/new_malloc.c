#include "malloc.h"

void	*ft_malloc(size_t size)
{
	if (g_pg == NULL)
		add_pg(g_pg);
	else if (size < 64)
	{
		if (!check_page_tiny(g_pg, size))
			g_pg = add_page(g_pg, size, 0);
		if (g_pg != NULL)
			g_pg = 
	}
	else if (size >= 64 && size < 4096)
	{
		
	}
	else
	{
		
	}
	return ((void *));
}
