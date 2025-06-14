#include "libft.h"

void	ft_memmove(char *stash)
{
	size_t	i;
	size_t	nline;

	i = 0;
	nline = ft_strchr_n(stash) + 1;
	while (stash[i + nline] && nline)
	{
		stash[i] = stash[i + nline];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		stash[i] = '\0';
		i++;
	}
}