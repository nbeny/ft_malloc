#include "malloc.h"

void	print_global_info(void)
{
	t_page	*savepage;
	t_ptr	*saveptr;

	savepage = g_page;
	saveptr = NULL;
	while (savepage)
	{
		ft_printf(2, "id = %d\n", savepage->id);
		ft_printf(2, "size = %zu\n", savepage->size);
		ft_printf(2, "page = %p\n", savepage->page);
		ft_printf(2, "ptr = %p\n", savepage->ptr);
		ft_printf(2, "next = %p\n", savepage->next);
		saveptr = savepage->ptr;
		while (saveptr)
		{
			ft_printf(2, "\tptr->size = %zu\n", saveptr->size);
			ft_printf(2, "\tptr->free = %d\n", saveptr->free);
			ft_printf(2, "\tptr->next = %p\n", saveptr->next);
			saveptr = saveptr->next;
		}
		ft_printf(2, "\n");
		savepage = savepage->next;
	}
}

int		main(int ac, char **av)
{
	int		i;
//	int		j;
	char	**s;

	i = 0;
	s = NULL;

	
//	if (ac > 1)
	{
		s = ft_malloc(sizeof(char) * 50);
		s = ft_malloc(sizeof(char) * 50);
		s = ft_malloc(sizeof(char) * 50);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 50);
		s = ft_malloc(sizeof(char) * 50);
		s = ft_malloc(sizeof(char) * 50);
		s = ft_malloc(sizeof(char) * 50);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 5003333);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 500);
		s = ft_malloc(sizeof(char) * 500);
/*
		while (av[i] != NULL)
		{
			s[i] = ft_malloc(sizeof(char) * 10);
			j = 0;
			while (j < 10)
			{
				s[i][j] = '*';
				j++;
			}
			s[i][j] = '\0';
			ft_printf(0, "%s\n", s[i]);
			i++;
		}
*/
	print_global_info();

		ft_printf(2, ">>>>>>>>>>>>>>\n");
		ft_printf(2, ">>>>>>>>>>>>>>\n");
		show_alloc_mem();
		ft_printf(2, ">>>>>>>>>>>>>>\n");
		ft_printf(2, ">>>>>>>>>>>>>>\n");
	}
	return (0);
}
