#include "malloc.h"

int		check_page_tiny(size_t size)
{
	t_pg	*s;
	int		i;

	s = g_pg;
	while (s != NULL)
	{
		ft_printf(2, "!!!!!!!!!%p!\n", s);
//		ft_printf(2, "<%d>\n", s->i);
		i = 0;
		while (i < 20)
		{
			ft_printf(2, "[%p]", (void *)s->tab[i]);
			i++;
		}
		ft_printf(2, "\n###%d#%d##\n", g_pg->id, s->i);
		if (s->id == 0 && s->i < 20)
			return (1);
		s = s->nxt;
	}
	return (0);
}

int		check_page_small(size_t size)
{
	t_pg	*s;

	s = g_pg;
	while (s != NULL)
	{
		if (s->id == 1 && s->i < 3)
			return (1);
		s = s->nxt;
	}
	return (0);
}

t_pg	*get_ptr_tiny(t_pg *ptr)
{
	size_t	i;

	i = ptr->i;
	while (i != 0)
	{
		ptr += sizeof(t_pg) + 100;
		i -= 1;
	}
	ptr->tab[ptr->i] = (size_t)ptr;
	ptr->i++;
	return ((void *)ptr);
}

t_pg	*get_ptr_small(t_pg *ptr)
{
	size_t	i;

	i = ptr->i;
	while (i != 0)
	{
		ptr += sizeof(t_pg) + 100;
		i -= 1;
	}
	ptr->tab[ptr->i] = (size_t)ptr;
	ptr->i++;
	return ((void *)ptr);
}
