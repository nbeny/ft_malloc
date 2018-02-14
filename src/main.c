#include "malloc.h"

int		main(int ac, char **av)
{
	char	*tty;

	tty = NULL;
	tty = (char *)ft_malloc(sizeof(char) * 10);
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
	return (0);
}
