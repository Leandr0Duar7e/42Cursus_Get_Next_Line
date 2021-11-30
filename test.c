/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:59:09 by leolivei          #+#    #+#             */
/*   Updated: 2021/11/30 14:16:09 by leolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd1;
	int		i;

	if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY);
		i = 1;
		while (i <= 6)
		{
			printf("linha %d\n", i);
			printf("%s\n", get_next_line(fd1));
			i++;
		}
		close(fd1);
	}
	return (0);
}
