#include "malloc.h"

size_t	ft_power_of(size_t size)
{
	size_t	i;

	i = 1;
	if (size <= 0 || size > (ft_power(2, 64) - 1))
		return (-1);
	while (size >= ft_power(2, i))
		i++;
	return ((size_t)ft_power(2, i));
}
