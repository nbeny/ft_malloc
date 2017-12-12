#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;
	size_t		nb;
	char	c;
	char	*str;

	nb = atoi(av[2]);
	c = av[1][0];
	str = (char *)mmap(0, nb + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	i = 0;
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	printf("%s\n", str);
	return (0);
}
