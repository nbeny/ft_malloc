#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int sz = getpagesize();
	printf("%d\n", sz);
	return (0);
}
