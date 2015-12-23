#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	**line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	ft_putnbr(get_next_line(fd, line));
	ft_putchar('\n');
	ft_putendl(*line);
	return (0);
}
