#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *c);

#endif