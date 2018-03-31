#include "malloc.h"

t_page	*init_page()
{
	static t_page	*page = NULL;

	return (page);
}

t_page	*nmap_page(t_page *page, size_t size, int id)
{
	if (!(page = mmap(0, TINY, PROT, MAP, -1, 0)))
		return (NULL);
	
	return (page);
}

t_page	*add_page(t_page *page, size_t size, int id)
{
	if (page == NULL)
	{
		
	}
	return (NULL);
}
