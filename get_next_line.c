/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:21 by leolivei          #+#    #+#             */
/*   Updated: 2021/12/03 14:23:10 by leolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*makekeep(char **fdlst, char *rline, int nrr)
{
	char	*line;//variavel a retornar	
	char	*temp;
	int		i;

	if (nrr)
	{
		if (!*fdlst)
			*fdlst = ft_strdup("");
		temp = ft_strjoin(*fdlst, rline);
		//free(fdlst);
		*fdlst = temp;
	}
	i = (int)((ft_strchr(*fdlst, '\n')) - *fdlst);//indice do '\n'
	if (ft_strchr(*fdlst, '\n'))
	{
		line = malloc(i + 1);
		if (!line)
			return 0;
		line = ft_substr(*fdlst, 0, i + 1);
		*fdlst = (ft_strchr(*fdlst, '\n') + 1);
		return (line);
	}
	else if (!nrr)
	{
		line = malloc(i - 1);
		if (!line)
			return (0);
		line = ft_substr(*fdlst, 0, i - 1);
		*fdlst = 0;
		return (line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static	char	*keep[FD_MAX]; //Lista com 4864 file descriptors
	char			*res;
	char			*rbuf;//buffer to receive characters read
	ssize_t			nrlet;//number of chars read
	
	if (fd < 0 || BUFFER_SIZE < 1 || fd > FD_MAX)
		return (NULL);
	rbuf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rbuf)
		return (0);
	nrlet = read(fd, rbuf, (size_t )(BUFFER_SIZE));
	if (nrlet || keep[fd])
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
	return (0);
}
