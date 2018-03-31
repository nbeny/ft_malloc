#include "malloc.h"

t_page	*init_var_page(t_page *page, int id)
{
	static t_ptr	*pr = NULL;

	page->id = 0;
	page->size = 0;
	page->ptr = pr;
	page->next = NULL;
	return (page);
}

t_page	*add_page(t_page *page, size_t size, int id)
{
	t_page	*s;

	s = page;
	if (page == NULL)
	{
		if (!(page = (t_page *)mmap(0, size, PROT, MAP, -1, 0)))
			return (NULL);
		page = init_var_page(page, id);
	}
	else
	{
		while (page->next != NULL)
			page = page->next;
		if (!(page->next = (t_page *)mmap(0, size, PROT, MAP, -1, 0)))
			return (page);
		page = page->next;
		
	}
}
