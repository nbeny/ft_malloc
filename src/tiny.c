#include "malloc.h"

t_ptr	*add_ptr_tiny(t_page *g_page, t_ptr *g_ptr, size_t size, int i)
{
	t_ptr	*s;

	s = g_ptr;
	if (g_ptr != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = s + s->size + sizeof(t_ptr *) + 10;
		s = s->next;
		s = init_ptr(g_ptr, size, id);
		if (g_ptr->next != NULL)
			g_ptr = ptr_prev(g_ptr, s);
	}
	else
	{
		g_ptr = g_page;
		g_ptr = init_ptr(g_ptr, size, id);
	}
	return (s);
}
