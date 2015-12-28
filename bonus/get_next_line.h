#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUF_SIZE 32
# include "libft.h"
# include "fcntl.h"
int	get_next_line(int const fd, char **line);

typedef struct		s_stock
{
	int	*fd;
	char	**stock;
}			t_stock;

#endif
