#include "malloc.h"

static int		check_exist_id(int id)
{
	t_pg	*page;

	page = g_pg;
	while (page != NULL)
	{
		if (page->id == id)
			return (1);
		page = page->nxt;
	}
	return (0);
}

static void		print_tiny(void)
{
	t_pg	*page;
	int		i;
	int		j;

	i = 0;
	j = 0;
	page = g_pg;
	if (check_exist_id(0))
		ft_printf(0, "TINY\n");
	while (page != NULL)
	{
		if (page->id == 0)
		{
			i++;
			ft_printf(0, "Page_%d : %p\n", i, page);
			j = 0;
			while (j <= page->i)
			{
				ft_printf(0, "\tOx%X - Ox%X : %zu octets\n",\
					page->tab[j], (page->tab[j] + 64 + sizeof(t_pg)), 64);
				j++;
			}
		}
		page = page->nxt;
	}
}

static void		print_small(void)
{
	t_pg	*page;
	int		i;
	int		j;

	i = 0;
	j = 0;
	page = g_pg;
	if (check_exist_id(1))
		ft_printf(0, "SMALL\n");
	while (page != NULL)
	{
		if (page->id == 1)
		{
			i++;
			ft_printf(0, "Page_%d : %p\n", i, page);
			j = 0;
			while (j <= page->i)
			{
				ft_printf(0, "\tOx%X - Ox%X : %zu octets\n",\
					page->tab[j], page->tab[j] + 64 + sizeof(t_pg),\
					1024);
				j++;
			}
		}
		page = page->nxt;
	}
}

static void		print_large(void)
{
	t_pg	*page;
	int		i;

	i = 0;
	page = g_pg;
	if (check_exist_id(2))
		ft_printf(0, "LARGE\n");
	while (page != NULL)
	{
		if (page->id == 2)
		{
			ft_printf(0, "\tOx%X - Ox%X : %zu octets\n",\
					  page, (size_t)page + page->size + sizeof(t_pg),\
				page->size);
		}
		page = page->nxt;
	}
}

void			show_alloc_mem(void)
{
	print_tiny();
	print_small();
	print_large();
}
