#include "malloc.h"

/*
**ft_power_of(size_t size)
*/

t_ptr	*init_ptr(t_ptr *ptr, size_t size)
{
	ptr->size = ft_power_of(size);
	ptr->free = 0;
	ptr->next = NULL;
	return (ptr);
}

void	*add_ptr(t_page *page, size_t size)
{
	t_ptr	*s;
	void	*ret;

	s = page->ptr;
	ret = NULL;
	if (page->ptr == NULL)
	{
		page->ptr = (t_ptr *)(page + sizeof(t_page));
		page->ptr = init_ptr(page->ptr, size);
		ret = page->ptr + sizeof(t_ptr);
		return (ret);
	}
	else
	{
		while (s->next != NULL)
			s = s->next;
		s = init_ptr(s, size);
		s->next = (t_ptr *)(s + sizeof(t_ptr) + s->size + 10);
		s = s->next;
		s = init_ptr(s, size);
		ret = s + sizeof(t_ptr);
		return (ret);
	}
	return (NULL);
}
