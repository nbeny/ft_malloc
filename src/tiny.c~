#include "malloc.h"

t_ptr	*add_ptr_tiny(t_page *page, t_ptr *ptr, size_t size, int i)
{
	t_ptr	*s;

	s = ptr;
	if (ptr != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = s + s->size + sizeof(t_ptr *) + 10;
		s = s->next;
		s = init_ptr(ptr, size, id);
		if (ptr->next != NULL)
			ptr = ptr_prev(ptr, s);
	}
	else
	{
		ptr = page;
		ptr = init_ptr(ptr, size, id);
	}
	return (s);
}
