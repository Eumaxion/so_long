/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:43:30 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/02 12:43:44 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
ssize_t	ft_strchr_n(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *line, char *stash);
void	ft_memmove(char *stash);
char	*release(char *line, char *stash);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif