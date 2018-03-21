#include "malloc.h"

//struct s_pg		*g_pg = NULL;

int		main(int ac, char **av)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;
	char	*e;
	char	*f;
	char	*g;
	char	*h;
	char	*u;
	char	*j;
	char	*k;
	char	*l;
	char	*m;
	char	*n;
	char	*o;
	char	*p;
	char	*q;
	char	*r;
	char	*s;
	char	*t;
	char	*aa;
	char	*bb;
	char	*cc;
	char	*dd;
	int		i;

	(void)ac;
	(void)av;
	i = sizeof(t_pg);
	a = ft_malloc(sizeof(char) * 8);
	b = ft_malloc(sizeof(char) * 8);
	c = ft_malloc(sizeof(char) * 8);
	d = ft_malloc(sizeof(char) * 8);
	aa = ft_malloc(sizeof(char) * 100);
	bb = ft_malloc(sizeof(char) * 100);
	cc = ft_malloc(sizeof(char) * 100);
	dd = ft_malloc(sizeof(char) * 7000);
	q = ft_malloc(sizeof(char) * 8);
	r = ft_malloc(sizeof(char) * 8);
	s = ft_malloc(sizeof(char) * 8);
	t = ft_malloc(sizeof(char) * 8);
	e = ft_malloc(sizeof(char) * 8);
	f = ft_malloc(sizeof(char) * 8);
	g = ft_malloc(sizeof(char) * 8);
	h = ft_malloc(sizeof(char) * 8);
	u = ft_malloc(sizeof(char) * 8);
	j = ft_malloc(sizeof(char) * 8);
	k = ft_malloc(sizeof(char) * 8);
	l = ft_malloc(sizeof(char) * 8);
	m = ft_malloc(sizeof(char) * 8);
	n = ft_malloc(sizeof(char) * 8);
	o = ft_malloc(sizeof(char) * 8);
	p = ft_malloc(sizeof(char) * 8);
	i = 0;
	while (i < 7)
	{
		a[i] = 40;
		b[i] = 41;
		c[i] = 42;
		d[i] = 43;
		e[i] = 44;
		f[i] = 45;
		g[i] = 46;
		h[i] = 47;
		u[i] = 48;
		j[i] = 49;
		k[i] = 50;
		l[i] = 51;
		m[i] = 52;
		n[i] = 53;
		o[i] = 54;
		p[i] = 55;
		q[i] = 56;
		r[i] = 57;
		s[i] = 58;
		t[i] = 59;
		i++;
	}
	a[i] = 0;
	b[i] = 0;
	c[i] = 0;
	d[i] = 0;
	e[i] = 0;
	f[i] = 0;
	g[i] = 0;
	h[i] = 0;
	u[i] = 0;
	j[i] = 0;
	k[i] = 0;
	l[i] = 0;
	m[i] = 0;
	n[i] = 0;
	o[i] = 0;
	p[i] = 0;
	q[i] = 0;
	r[i] = 0;
	s[i] = 0;
	t[i] = 0;
	i = 0;
	while (i < 99)
	{
		aa[i] = 50;
		bb[i] = 51;
		cc[i] = 52;
		i++;
	}
	aa[i] = 0;
	bb[i] = 0;
	cc[i] = 0;
	i = 0;
	while (i < 6999)
	{
		dd[i] = 53;
		i++;
	}
	dd[i] = 0;
/*
	ft_printf(0, "%s\n", a);
	ft_printf(0, "%s\n", b);
	ft_printf(0, "%s\n", c);
	ft_printf(0, "%s\n", d);
	ft_printf(0, "%s\n", aa);
	ft_printf(0, "%s\n", bb);
	ft_printf(0, "%s\n", cc);
	ft_printf(0, "%s\n", dd);
	ft_printf(0, "%s\n", e);
	ft_printf(0, "%s\n", f);
	ft_printf(0, "%s\n", g);
	ft_printf(0, "%s\n", h);
	ft_printf(0, "%s\n", u);
	ft_printf(0, "%s\n", j);
	ft_printf(0, "%s\n", k);
	ft_printf(0, "%s\n", l);
	ft_printf(0, "%s\n", m);
	ft_printf(0, "%s\n", n);
	ft_printf(0, "%s\n", o);
	ft_printf(0, "%s\n", p);
	ft_printf(0, "%s\n", q);
	ft_printf(0, "%s\n", r);
	ft_printf(0, "%s\n", s);
	ft_printf(0, "%s\n", t);
*/
	show_alloc_mem();
	return (0);
}
