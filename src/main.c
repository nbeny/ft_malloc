#include "malloc.h"

struct s_tty	tty
{
	int				i;
	char			c;
	struct s_tty	*next;
}				t_tty;

int		main(int ac, char **av)
{
	t_tty	*tty;

	(t_tty *)ft_malloc(sizeof(t_tty *));
	tty->i = 45;
	tty->c = '*';
	return (0);
}
