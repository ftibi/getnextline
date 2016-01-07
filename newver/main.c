#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(" : ");
	ft_putendl(line);
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(" : ");
	ft_putendl(line);
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(" : ");
	ft_putendl(line);
//	//fflush(stdout);
//	ft_putnbr(get_next_line(fd, &line));
//	//fflush(stdout);
//	ft_putstr(" : ");
//	//ft_putendl(line);
//	//fflush(stdout);
	


	
	
	
	
	
	
	
	return (0);
}
