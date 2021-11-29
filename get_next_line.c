/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:21 by leolivei          #+#    #+#             */
/*   Updated: 2021/11/29 16:16:37 by leolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*makekeep(char **fdlst, char *rline, int fd, int nrr)
{
	char	*line;//variavel a retornar
	char	*rest;//guardar o pos /n e colocar no keep
	int		i;

	if (rline)
	{
		if (!fdlst[fd])
			fdlst[fd] = malloc(sizeof(char) * BUFFER_SIZE);
		fdlst[fd] = ft_strjoin(fdlst[fd], rline);
	}
	i = 0;
	while (fdlst[fd][i])
	{
		//printf("%c\n", fdlst[fd][i]);
		if (fdlst[fd][i] == '\n')
		{
			//printf("%d\n", i);
			line = ft_substr(fdlst[fd], 0, i + 1);
			fdlst[fd] = (ft_strchr(fdlst[fd], '\n') + 1);
			return (line);
		}
		i++;
	}
	return (line);
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
	//printf("%s\n", keep[fd]);
	if (nrlet || keep[fd])
	{
		res = makekeep(keep, rbuf, fd, nrlet);
		free(rbuf);
		if (!res)
			return (get_next_line(fd));
		return (res);
	}
	free(rbuf);
	return (0);
}
