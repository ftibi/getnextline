#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	**line;

	line = (char**)ft_memalloc(sizeof(char*));
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(" : ");
	ft_putendl(*line);
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(" : ");
	ft_putendl(*line);
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(" : ");
	ft_putendl(*line);
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(" : ");
	ft_putendl(*line);
	


	
	
	
	
	
	
	
	return (0);
}
