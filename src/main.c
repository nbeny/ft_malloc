#include "malloc.h"

int		main(int ac, char **av)
{
	char	*tty;
	char	*a;
	char	*b;
	int		i;

	i = 0;
	tty = NULL;
	tty = (char *)ft_malloc(sizeof(char) * 10);
	a = (char *)ft_malloc(sizeof(char) * 10);
	b = (char *)ft_malloc(sizeof(char) * 16);
	while (i < 15)
	{
		b[i] = '7';
		i++;
	}
	b[i] = 0;
	a[0] = 65;
	a[1] = 65;
	a[2] = 65;
	a[3] = 65;
	a[4] = 65;
	a[5] = 65;
	a[6] = 65;
	a[7] = 65;
	a[8] = 65;
	a[9] = 0;
	tty[0] = 42;
	tty[1] = 42;
	tty[2] = 42;
	tty[3] = 42;
	tty[4] = 42;
	tty[5] = 42;
	tty[6] = 42;
	tty[7] = 42;
	tty[8] = 42;
	tty[9] = 0;
	ft_printf(0, "%s\n", tty);
	ft_printf(0, "%s\n", a);
	ft_printf(0, "%s\n", b);
	t_page *page;
	page = g_page;
	while (page != NULL)
	{
		ft_printf(0, "%d\n", page->addr);
		page = page->next;
	}
	return (0);
}
