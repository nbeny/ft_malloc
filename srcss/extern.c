#include "test.h"

t_var	*init_var()
{
	t_var		*s;
	static int	i = 0;

	if(!(s = (t_var *)malloc(sizeof(t_var))))
		return (NULL);
	s->i = i++;
	s->s = NULL;
	s->next = NULL;
	return (s);
}

void	ft_extern(void)
{
	t_var	*s;

	s = g_var;
	if (g_var == NULL)
		g_var = init_var();
	else
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_var();
	}
}
