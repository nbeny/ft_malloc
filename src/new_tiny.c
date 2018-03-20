#include "malloc.h"

int		check_page_tiny(t_page *pg, t_size size)
{
	t_pg	*page;

	page = g_pg;
	while (page != NULL)
	{
		if (page->id == 0 && page->size < 1)
			return (1);
		page = page->next;
	}
	return (0);
}
