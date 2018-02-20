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
	ft_printf(2, "%d::%d\n", ((size_t)4096 - res), (size + sizeof(t_ptr) + (size_t)10));
	if (((size_t)4096 - res) < (size + sizeof(t_ptr) + (size_t)10))
	{
		return (1);
	}
	return (0);
}

int			check_page_tiny(t_page *page, size_t size)
{
	t_page	*s;

	s = page;
	ft_printf(2, "check_page_tiny\n");
	if (page != NULL)
	{
		ft_printf(2, "while\n");
		while (s->next != NULL && s->id != 0 && !check_page_size(s, ft_power_of(size)))
			s = s->next;
		if (check_page_size(s, ft_power_of(size)))
			return (0);
		ft_printf(2, "if(id == 0)\n");
		if (s->id == 0)
			return (1);
		ft_printf(2, "else\n");
		return (0);
	}
	return (0);
}

t_ptr		*add_ptr_tiny(t_page *page, size_t size, int id)
{
	t_ptr	*s;

	s = page->ptr;
	if (page->ptr != NULL)
	{
		ft_printf(2, "add_ptr_tiny_next\n");
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
		ft_printf(2, "add_ptr_tiny_NULL\n");
		page->ptr = (t_ptr *)page;
		page->ptr = init_ptr(page->ptr, size, id);
		return (page->ptr);
	}
	return (s);
}
