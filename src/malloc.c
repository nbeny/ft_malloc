//#include "malloc.h"
#include <stdlib.h>
#include <sys/mman.h>
#include <stdio.h>

typedef struct	s_dop
{
	int				a;
	char			*str;
	struct s_dop	*next;
}				t_dop;

void	*ft_malloc(size_t size)
{
	void	*mem;

	mem = mmap(0, size, PROT_READ | PROT_WRITE,\
				MAP_ANON | MAP_PRIVATE, -1, 0);
	return (mem);
}

int		main(int ac, char **av)
{
	t_dop	*dop;

	dop = (t_dop *)ft_malloc(sizeof(t_dop));
	dop->a = 1;
	dop->str = (char *)ft_malloc(sizeof(char));
	dop->str[0] = '1';
	dop->str[1] = '2';
	dop->str[2] = '3';
	dop->str[3] = '4';
	dop->str[4] = '\0';
	printf("%s %i\n", dop->str, dop->a);
	return (0);
}
