/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:21 by leolivei          #+#    #+#             */
/*   Updated: 2021/11/23 15:07:34 by leolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*makekeep(char **fdlst, char *rline, int fd)
{
	char	*line;//variavel a retornar
	char	*rest;//guardar o pos /n e colocar no keep
	int		i;

	if (rline)
	{
		if (!fdlst[fd])
			fdlst[fd] = "";
		fdlst[fd] = ft_strjoin(fdlst[fd], rline);
	}
	printf("if1\n");
	i = 0;
	while (fdlst[fd][i])
	{
		if (fdlst[fd][i] == '\n')
		{
			printf("%d\n", i);
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

	nrlet = read(fd, rbuf, BUFFER_SIZE);
	if (nrlet || keep[fd])
	{
		res = makekeep(keep, rbuf, fd);
		return (res);
	}
	return (0);
}
