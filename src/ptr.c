#include "malloc.h"

t_ptr	*init_ptr(size_t size, int id)
{
	static t_ptr	*ptr = NULL;

	if (!(ptr = mmap(0, size + sizeof(t_ptr), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ptr->id = id;
	ptr->free = 0;
	ptr->ptr = NULL;
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

t_ptr	*add_ptr(t_ptr *ptr, size_t size, int id)
{
	t_ptr	*s;
	t_ptr	*pr;
	
	pr = ptr;
	s = ptr;
	if (ptr == NULL)
	{
		if (!(ptr = init_ptr(size, id)))
			return (NULL);
	}
	else
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_ptr(size, id);
		s = s->next;
		if (ptr->next != NULL)
			ptr = ptr_prev(ptr, s);
	}
	return (ptr);
}
