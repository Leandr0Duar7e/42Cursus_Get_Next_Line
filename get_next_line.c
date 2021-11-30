/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:21 by leolivei          #+#    #+#             */
/*   Updated: 2021/11/30 14:16:06 by leolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*makekeep(char **fdlst, char *rline, int fd, int nrr)
{
	char	*line;//variavel a retornar	
	int		i;

	if (nrr)
	{
		if (!fdlst[fd])
			fdlst[fd] = "";
		//fdlst[fd] = malloc(nrr + ft_strlen(fdlst[fd]));
		if (!fdlst[fd])
			return 0;
		fdlst[fd] = ft_strjoin(fdlst[fd], rline);
	}
	i = 0;
	while (fdlst[fd][i])
	{
		if (fdlst[fd][i] == '\n')
		{
			line = malloc(i + 1);
			if (!line)
				return 0;
			line = ft_substr(fdlst[fd], 0, i + 1);
			fdlst[fd] = (ft_strchr(fdlst[fd], '\n') + 1);
			return (line);
		}
		i++;
	}
	if (!nrr && !fdlst[i])
	{
		line = malloc(i - 1);
		if (!line)
			return (0);
		line = ft_substr(fdlst[fd], 0, i - 1);
		fdlst[fd] = 0;
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

	rbuf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!rbuf)
		return (0);
	nrlet = read(fd, rbuf, (size_t )BUFFER_SIZE);
	if (nrlet || keep[fd])
	{
		res = makekeep(keep, rbuf, fd, nrlet);
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
