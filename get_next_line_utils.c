/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoreira <gmoreira@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 04:13:25 by gmoreira          #+#    #+#             */
/*   Updated: 2022/06/02 03:25:39 by gmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	unsigned int	count;

	count = 0;
	while (c[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	index;
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	while (*s2)
	{
		str[index] = *s2++;
		index++;
	}
	str[index] = '\0';
	return (str);
}

static int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	while (src[index] && index + 1 < size)
	{
		dest[index] = src[index];
		index++;
	}
	if (size > 0)
		dest[index] = '\0';
	index = ft_strlen(src);
	return (index);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	size;

	size = ft_strlen(src) + 1;
	copy = malloc(size * sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, src, size);
	return (copy);
}


char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;
	size_t	index;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (NULL);
	if (len > (len_s - start))
		len = len_s - start;
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	index = 0;
	while (s[index] && index < len)
	{
		substr[index] = s[start + index];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}