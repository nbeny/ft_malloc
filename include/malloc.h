#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>
# include <sys/mman.h>

typedef struct	s_dop
{
}				t_dop;
void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
#endif
