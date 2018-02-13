#include "malloc.h"

t_ptr	*init_ptr(t_ptr *ptr, size_t size, int id)
{
	ptr->id = id;
	ptr->size = ft_power_of(size);
	ptr->free = 0;
	ptr->ptr = ptr;
	ptr->addr = (size_t)ptr;
	ptr->next = NULL;
	ptr->prev = NULL;
}

t_ptr	*ptr_prev(t_ptr *ptr, t_ptr *s)
{
	t_ptr	*pv;

	pv = ptr;
	while (pv->next->next != NULL)
		pv = pv->next;
	s->prev = pv;
	return (ptr);
}

t_ptr	*add_ptr(t_page *page, t_ptr *ptr, size_t size, int id)
{
	t_ptr	*s;
	t_ptr	*pr;

	pr = ptr;
	s = ptr;
	if (ptr == NULL)
	{
		if (!(ptr = init_ptr(page, size, id)))
			return (NULL);
	}
	else
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_ptr_next(ptr, size, id);
		s = s->next;
		if (ptr->next != NULL)
			ptr = ptr_prev(ptr, s);
	}
	return (ptr);
}

