#include "malloc.h"

int		main(int ac, char **av)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = NULL;
	if (ac > 1)
	{
		s = ft_malloc(sizeof(char *) * 500);
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
		ft_printf(2, ">>>>>>>>>>>>>>\n");
		ft_printf(2, ">>>>>>>>>>>>>>\n");
		show_alloc_mem();
		ft_printf(2, ">>>>>>>>>>>>>>\n");
		ft_printf(2, ">>>>>>>>>>>>>>\n");
	}
	
	return (0);
}
