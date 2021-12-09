/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:15:03 by leolivei          #+#    #+#             */
/*   Updated: 2021/12/09 12:33:37 by leolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <limits.h>

static char	*makeline(char **fdlst, char **line, char **temp, int i)
{
	*line = ft_substr(*fdlst, 0, i + 1);
	*temp = (ft_substr(*fdlst, i + 1, ft_strlen(*fdlst)));
	free(*fdlst);
	*fdlst = *temp;
	if (**fdlst == '\0')
	{
		free(*fdlst);
		*fdlst = NULL;
	}
	return (*line);
}

static char	*makekeep(char **fdlst, char *rline, int nrr)
{
	char	*line;
	char	*temp;
	int		i;

	if (nrr > 0)
	{
		if (!*fdlst)
			*fdlst = ft_strdup("");
		temp = ft_strjoin(*fdlst, rline);
		free(*fdlst);
		*fdlst = temp;
	}
	i = (int)((ft_strchr(*fdlst, '\n')) - *fdlst);
	if (ft_strchr(*fdlst, '\n'))
		return (makeline(fdlst, &line, &temp, i));
	else if (!nrr)
	{
		line = ft_substr(*fdlst, 0, i);
		free(*fdlst);
		*fdlst = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*keep[OPEN_MAX];
	char		*res;
	char		*rbuf;
	ssize_t		nrlet;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	rbuf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rbuf)
		return (0);
	nrlet = read(fd, rbuf, (size_t)(BUFFER_SIZE));
	if (nrlet > 0 || keep[fd])
	{
		rbuf[nrlet] = '\0';
		res = makekeep(&keep[fd], rbuf, nrlet);
		free(rbuf);
		if (!res)
		{
			return (get_next_line(fd));
		}
		return (res);
	}
	free(rbuf);
	return (NULL);
}
