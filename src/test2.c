#include <unistd.h>
#include <stdio.h>

void	*ft_malloc(size_t size)
{
	void *block;
	block = sbrk(size);
	if (block == (void*) -1)
		return (NULL);
	return (block);
}

int		main(int ac, char **av)
{
	char *str;
	int i;

	str = ft_malloc(2);
	printf("%p\n", str);
	i = 0;
	while (i < 41939720)
	{
		printf("[%i]", i);fflush(stdout);
		str[i] = 42;
		i++;
	}
	return (0);
}
