#include <unistd.h>
#include <stdlib.h>
//#include <sys/man.h>
#include <stdio.h>

struct header_t {
	size_t size;
	unsigned is_free;
	struct header_t *next;
};

struct header_t *head, *tail;

pthread_attr_t global_malloc_lock;

struct header_t *

struct header_t *get_free_block(size_t size)
{
	struct header_t *curr = head;
	while(curr) {
		if (curr->is_free && curr->size >= size)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

void *ft_malloc(size_t size)
{
	size_t total_size;
	void *block;
	struct header_t *header;
	if (!size)
		return NULL;
	pthread_mutex_lock(&global_malloc_lock);
	header = get_free_block(size);
	if (header) {
		header->is_free = 0;
		pthread_mutex_unlock(&global_malloc_lock);
		return (void*)(header + 1);
	}
	total_size = sizeof(struct header_t) + size;
	block = sbrk(total_size);
	if (block == (void*) -1) {
		pthread_mutex_unlock(&global_malloc_lock);
		return NULL;
	}
	header = block;
	header->size = size;
	header->is_free = 0;
	header->next = NULL;
	if (!head)
		head = header;
	if (tail)
		tail->next = header;
	tail = header;
	pthread_mutex_unlock(&global_malloc_lock);
	struct header_t *s;
	s = header;
	printf("total_size:: %i\n", total_size);
	printf("block:: %p\n", block);
	while (s)
	{
		printf("%p:[%i][%i]\n", s, s->size, s->is_free);
		s = s->next;
	}
	return (void*)(header + 1);
}

int		main(int ac, char **av)
{
	char	*str;
	char	*s;
	char	*ss;
	char	*sss;

	str = ft_malloc(sizeof(char) * 4);
	printf("*%p*\n", str);
	s = ft_malloc(sizeof(char) * 5000000000000000);
	printf("*%p*\n", str);
	ss = ft_malloc(sizeof(char) * 6);
	printf("*%p*\n", str);
	sss = ft_malloc(sizeof(char) * 7);
	printf("*%p*\n", str);
	return (0);
}
