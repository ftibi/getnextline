#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUF_SIZE 10
# include "libft.h"
# include "fcntl.h"
int	get_next_line(int const fd, char **line);

typedef struct			s_stock
{
	char				*str;
	int					fd;
	int					status;
	struct s_stock		*next;
}						t_stock;

#endif
