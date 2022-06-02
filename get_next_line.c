/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoreira <gmoreira@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 04:13:44 by gmoreira          #+#    #+#             */
/*   Updated: 2022/06/02 03:46:11 by gmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == '\n' || *ptr == '\0')
			return (ptr);
		ptr++;
	}
	return (NULL);
}

char	*get_n_save(char *ans, int fd)
{
	static char	*save[256];
	char *word;
	char *temp;
	int	len;

	if (!ans)
		return(NULL);
	if (save[fd])
	{
		temp = ft_strjoin(save[fd], ans);
		free(ans);
		ans = temp;
		free(save[fd]);
		save[fd] = NULL;
	}
	len = ft_strchr(ans) - ans;
	word = ft_substr(ans, 0, len+1);
	save[fd] = ft_substr(ans, len+1, ft_strlen(ans));
	free(ans);
	return (word);
}

char	*read_line(int fd)
{
	char	line[BUFFER_SIZE + 1];
	char	*ans;
	char	*temp;
	int		ret;

	ret = read(fd, line, BUFFER_SIZE);
	if (ret == -1)
		return(NULL);
	ans = malloc(1 * sizeof(char));
	*ans = 0;
	while(ret && !(ret == -1))
	{
		line[ret] = '\0';
		temp = ft_strjoin(ans, line);
		free(ans);
		ans = temp;
		if (ft_strchr(ans))
			break;
		ret = read(fd, line, BUFFER_SIZE);
	}
	return(ans);
}

char	*get_next_line(int fd)
{
	char *ans;

	ans = read_line(fd);
	ans = get_n_save(ans, fd);
	return(ans);
}