#include "malloc.h"

void	ft_free(void *ptr)
{
	t_pg	*page;
	int		i;

	i = 0;
	if(munmap(ptr, length))
		return ;
	page = g_pg;
	while (page != NULL)
	{
		while (i != page->i)
		{
			page->tab[page->i] == 'a';
			if ((size_t)ptr == page->tab[page->i])
				;
			i++;
			
		}
		page = page->next;
	}
}
