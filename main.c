#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	fd2;
	char	*line;

	if (argc == 2)
	{
		ft_putendl("argc == 2");
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
	if (argc == 3)
	{
		ft_putendl("argc == 3");
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		ft_putnbr(get_next_line(fd, &line));
		ft_putstr(" : ");
		ft_putendl(line);
		ft_putnbr(get_next_line(fd2, &line));
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
	if (argc == 1)
	{
		ft_putendl("argc == 1");
		ft_putnbr(get_next_line(0, &line));
		ft_putstr(" : ");
		ft_putendl(line);
	}
	


	
	
	
	
	
	
	
	return (0);
}
