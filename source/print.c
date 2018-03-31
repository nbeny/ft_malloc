#include "malloc.h"

int		check_exist_id(int id)
{
	t_page	*page;

	page = g_page;
	while (page != NULL)
	{
		if (page->id == id)
			return (1);
		page = page->next;
	}
	return (0);
}

void	print_tiny(void)
{
	t_page	*page;
	t_ptr	*ptr;
	int		i;

	i = 0;
	page = g_page;
	ptr = NULL;
	if (check_exist_id(0))
		ft_printf(0, "TINY\n");
	while (page != NULL)
	{
		if (page->id == 0)
		{
			i++;
			ft_printf(0, "Page_%d : %p\n", i, page);
			ptr = page->ptr;
			while (ptr != NULL)
			{
				ft_printf(0, "\t%p - Ox%X : %zu octets\n",\
					ptr, ((size_t)ptr + ptr->size + sizeof(ptr)),\
					ptr->size);
				ptr = ptr->next;
			}
		}
		page = page->next;
	}
}

void	print_small(void)
{
	t_page	*page;
	t_ptr	*ptr;
	int		i;

	i = 0;
	page = g_page;
	ptr = NULL;
	if (check_exist_id(1))
		ft_printf(0, "SMALL\n");
	while (page != NULL)
	{
		if (page->id == 1)
		{
			i++;
			ft_printf(0, "Page_%d : %p\n", i, page);
			ptr = page->ptr;
			while (ptr != NULL)
			{
				ft_printf(0, "\t%p - Ox%X : %zu octets\n",\
					ptr, ((size_t)ptr + ptr->size + sizeof(ptr)),\
					ptr->size);
				ptr = ptr->next;
			}
		}
		page = page->next;
	}
}

void	print_large(void)
{
	t_page	*page;
	int		i;

	i = 0;
	page = g_page;
	if (check_exist_id(2))
		ft_printf(0, "LARGE\n");
	while (page != NULL)
	{
		if (page->id == 2)
		{
			ft_printf(0, "\t%p - Ox%X : %zu octets\n",\
				page, ((size_t)page + page->size + sizeof(page)),\
				page->size);
		}
		page = page->next;
	}
}

void	show_alloc_mem(void)
{
	print_tiny();
	print_small();
	print_large();
}
