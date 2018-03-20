#include "malloc.h"

int		main(int ac, char **av)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;
	int		i;

	(void)ac;
	(void)av;
	a = ft_malloc(sizeof(char) * 8);
	b = ft_malloc(sizeof(char) * 8);
	c = ft_malloc(sizeof(char) * 8);
	d = ft_malloc(sizeof(char) * 8);
	i = 0;
	while (i < 7)
	{
		a[i] = 42;
		b[i] = 42;
		c[i] = 42;
		d[i] = 42;
		i++;
	}
	a[i] = 0;
	b[i] = 0;
	c[i] = 0;
	d[i] = 0;
	ft_printf(0, "%s\n", a);
	ft_printf(0, "%s\n", b);
	ft_printf(0, "%s\n", c);
	ft_printf(0, "%s\n", d);
	return (0);
}
