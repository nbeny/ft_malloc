#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_ptr
{
    size_t          addr;
    struct s_ptr    *next;
    struct s_ptr    *prev;
}               t_ptr;

typedef struct  s_page
{
    struct s_ptr    *ptr;
    size_t          addr;
    struct s_page   *next;
    struct s_page   *prev;
}               t_page;

int		main(int ac, char **av)
{
	int		i;
	size_t		nb;
	char	c;
	t_page	*page;

	c = 42;
	page = (t_page *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	
	return (0);
}
