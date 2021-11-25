#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd1;
	char	*s;

	if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY);
		printf("%s\n", get_next_line(fd1));
		printf("done");
		close(fd1);
	}
	return (0);
}
