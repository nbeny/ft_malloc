#include "malloc.h"

int		main(int ac, char **av)
{
	char	*tty;
	char	*a;
	char	*b;
	char	*c;
//	char	*d;
//	char	*e;
//	char	*f;
	int		i;

	i = 0;
	tty = NULL;
	tty = (char *)ft_malloc(sizeof(char) * 10);
	a = (char *)ft_malloc(sizeof(char) * 10);
	b = (char *)ft_malloc(sizeof(char) * 41);
	c = (char *)ft_malloc(sizeof(char) * 41);
//	d = (char *)ft_malloc(sizeof(char) * 41);
//	e = (char *)ft_malloc(sizeof(char) * 41);
//	f = (char *)ft_malloc(sizeof(char) * 41);
	while (i < 40)
	{
		b[i] = 'b';
		c[i] = 'c';
//		d[i] = 'd';
//		e[i] = 'e';
//		f[i] = 'f';
		i++;
	}
	b[i] = 0;
	c[i] = 0;
//	d[i] = 0;
//	e[i] = 0;
//	f[i] = 0;
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
	ft_printf(0, "%s\n", c);
	show_alloc_mem();
	/*
	t_page	*page;
	t_ptr	*ptr;

	page = g_page;
	while (page != NULL)
	{
		ptr = page->ptr;
		while (page != NULL && ptr != NULL)
		{
			ft_printf(0, "[%p]\n", ptr);fflush(stdin);
			ft_printf(0, "qwer\n");fflush(stdin);
			ptr = ptr->next;
		}
		ft_printf(0, "{%p}\n", page);fflush(stdin);
		ft_printf(0, "asdf\n");fflush(stdin);
		page = page->next;
	}
	ft_printf(0, "zxcv\n");fflush(stdin);
	*/
	return (0);
}
