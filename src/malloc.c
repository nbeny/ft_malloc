#include "ft_malloc.h"

t_page	*init_page(size_t size, int id, size_t s_malloced)
{
    t_page  *page;

    page = NULL;
	if (!(page = (void *)mmap(0, size, PROT, MAP, -1, 0)))
		return (NULL);
	page->id = id;
    page->start = (void *)sizeof(t_page);
    if (id == 0)
        page->end = (void *)(sizeof(t_page) + 2 * getpagesize());
    else if (id == 1)
        page->end = (void *)(sizeof(t_page) + 8 * getpagesize());
    else
        page->end = (void *)(sizeof(t_page) + size);
    page->addr = (void *)(sizeof(t_page) + s_malloced);
    page->prev = NULL;
	page->next = NULL;
    return (page);
}

void	*add_page(size_t size, int id)
{
	t_page	*s;

	s = g_page;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		if (id == 0)
			s->next = init_page(TINY, id, size);
		else if (id == 1)
			s->next = init_page(SMALL, id, size);
		else if (id == 2)
			s->next = init_page(size + sizeof(t_page), id, size);
		return ((void *)(s->next + sizeof(t_page)));
	}
	else
	{
		if (id == 0)
			g_page = init_page(TINY, id, size);
		else if (id == 1)
			g_page = init_page(SMALL, id, size);
		else if (id == 2)
			g_page = init_page(size + sizeof(t_page), id, size);
		return ((void *)(g_page + sizeof(t_page)));
	}
	return (NULL);
}

void    *ft_malloc(size_t size)
{
    size_t  power;
    void    *ptr;
    t_page  *page;

    ptr = NULL;
    page = NULL;
    power = ft_power_of(size);
    if (size <= 0 || size > (ft_power(2, 64) - 1))
        return (NULL);
    else if (size < 64)
    {
        page = check_page_tiny(power);
        if (page == NULL)
            ptr = add_page(power, 0);
        else
        {
            ptr = (void *)page->addr;
            page->addr += power;
        }
    }
    else if (size >= 64 && size <= 4096)
    {
        page = check_page_small(power);
        if (page == NULL)
            ptr = add_page(power, 1);
        else
        {
            ptr = (void *)page->addr;
            page->addr += power;
        }
    }
    else
        ptr = add_page(size, 2);
    return ((void *)ptr);
}