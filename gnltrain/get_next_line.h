#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUF_SIZE 32
# define FD_SIZE 100
# include "libft.h"
# include "fcntl.h"
int	get_next_line(int const fd, char **line);

typedef struct		s_stock
{
	int	fd[FD_SIZE];
	char	str[FD_SIZE][BUF_SIZE];
}			t_stock;

#endif
