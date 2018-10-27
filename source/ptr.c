#include "malloc.h"

/*
**ft_power_of(size_t size)
*/

t_ptr	*init_ptr(t_ptr *ptr, size_t size)
{
	ptr->size = size;
	ptr->power = ft_power_of(size);
	ptr->ptr = (void *)((size_t)ptr + (size_t)sizeof(t_ptr));
	ptr->free = 0;
	ptr->next = NULL;
	return (ptr);
}

void	*add_ptr(t_page *page, size_t size)
{
	t_ptr	*s;
	void	*ret;

	ft_printf(2, "page: %p\n", page);
	s = NULL;
	ret = NULL;
	if (page->ptr == NULL)
	{
		page->ptr = (t_ptr *)((size_t)(page) + (size_t)sizeof(t_page));
		page->ptr = init_ptr(page->ptr, size);
		ret = (void *)page->ptr->ptr;
		ft_printf(2, "page->ptr NULL: %p\n", page->ptr);
		return (ret);
	}
	else
	{
		s = page->ptr;
		while (s->next != NULL)
			s = s->next;
		s = init_ptr(s, size);
		s->next = (t_ptr *)(s + sizeof(t_ptr) + s->size + 10);
		s = s->next;
		s = init_ptr(s, size);
		ret = s + sizeof(t_ptr);
		ft_printf(2, "page->ptr OTHER: %p\n", page->ptr);
		page->pos = (t_ptr *)s;
		return (ret);
	}
	return (NULL);
}
