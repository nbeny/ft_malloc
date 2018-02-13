#include "malloc.h"

int		check_page_size(t_page *page, t_ptr *ptr, size_t size)
{
	t_ptr	*s;

	s = page->ptr;
	while (s != NULL)
	{
		
	}
	return (-1);
}

int		check_page_tiny(t_page *g_page, t_ptr *g_ptr, size_t size)
{
	t_page	*s;
	size_t	i;

	s = g_page;
	if (g_page == NULL)
	{
		
	}
	else
	{
		i = (size_t)g_page;
		while (s != NULL && s->id != 0 && !check_page_size(s, s->ptr, size))
			s = s->next;
		if (s->id == 0)
		{
			
		}
		else
			return (0);
	}
	return (-1);
}

t_ptr	*add_ptr_tiny(t_page *g_page, t_ptr *ptr, size_t size, int i)
{
	t_ptr	*s;

	s = g_ptr;
	if (g_ptr != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = s + ft_power_of(s->size) + sizeof(t_ptr *) + 10;
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
