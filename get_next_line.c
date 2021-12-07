/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:21 by leolivei          #+#    #+#             */
/*   Updated: 2021/12/07 18:54:05 by leolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

static char	*makekeep(char **fdlst, char *rline, int nrr)
{
	char	*line;//variavel a retornar	
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
	i = (int)((ft_strchr(*fdlst, '\n')) - *fdlst);//indice do '\n'
	if (ft_strchr(*fdlst, '\n'))
	{
		line = ft_substr(*fdlst, 0, i + 1);
		temp = (ft_substr(*fdlst, i + 1, ft_strlen(*fdlst)));
		free(*fdlst);
		*fdlst = temp;
		if (**fdlst == '\0')
		{
			free(*fdlst);
			*fdlst = NULL;
		}
		return (line);
	}
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
	static	char	*keep[OPEN_MAX]; //Lista com 4864 file descriptors
	char			*res;
	char			*rbuf;//buffer to receive characters read
	ssize_t			nrlet;//number of chars read
	
	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	rbuf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rbuf)
		return (0);
	nrlet = read(fd, rbuf, (size_t )(BUFFER_SIZE));
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
