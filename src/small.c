#include "malloc.h"

static int	check_page_size(t_page *page, size_t size)
{
	t_ptr	*s;
	size_t	res;

	res = 0;
	s = page->ptr;
	while (s != NULL)
	{
		if (s->free == 0)
			res += s->size + sizeof(t_ptr) + 10;
		else if (s->free == 1 && s->size >= size)
			return (1);
		s = s->next;
	}
	if (((size_t)4068 - res) > (size + sizeof(t_ptr) + 10))
		return (1);
	return (0);
}

int			check_page_small(t_page *page, size_t size)
{
	t_page	*s;

	s = page;
	if (page != NULL)
	{
		while (s != NULL && s->id != 1 && !check_page_size(s, ft_power_of(size)))
			s = s->next;
		if (s->id == 1)
			return (1);
		return (0);
	}
	return (0);
}

t_ptr		*add_ptr_small(t_page *page, size_t size, int id)
{
	t_ptr	*s;

	s = page->ptr;
	if (page->ptr != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = s + s->size + sizeof(t_ptr *) + 10;
		s = s->next;
		s = init_ptr(s, size, id);
//		if (s->next != NULL)
//			s = ptr_prev(page->ptr, s);
	}
	else
	{
		page->ptr = (t_ptr *)page;
		page->ptr = init_ptr(page->ptr, size, id);
		return (page->ptr);
	}
	return (s);
}
