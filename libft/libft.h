#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	    ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
ssize_t	ft_strchr_n(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *line, char *stash);
void	ft_memmove(char *stash);
char	*release(char *line, char *stash);

#endif