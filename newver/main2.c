#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	int ret;
	char *line;
	int i;

	i = 0;

//	fd = open(av[1], O_RDONLY);
	ac = 0;
	fd = 0;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putendl("main2");
		printf("|%d|->|%d|\t|%s|\n", ret, fd, line);
		ft_putendl("main2 strdel");
		//ft_strdel(&line);
	}
	ft_putendl("main2 sortie while");
	printf("ret:|%d|\tline:|%s|\n", ret, line);

	close(fd);
	return (0);
}
