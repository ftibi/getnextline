#include "get_next_line.h"
#include <unistd.h>

int	fill_stock(int fd, char **stock)
{
	char	*tmp;
	char	*new;
	char	*save;
	int	ret;
	
	tmp = *stock;
	while (ret && !ft_strchr(tmp, '\n'))
	{
		new = (char*)ft_memalloc(ft_strlen(tmp) + BUF_SIZE + 1);
		if (tmp)
			new = ft_strcpy(new, tmp);
		save = new;
		while (*new)
			new++;
		ret = read(fd, new, BUF_SIZE);
		if (ret < 1)
			return (ret);
		tmp = save;
	}
	*stock = tmp;
	return (1);
}

int	fill_line()

int	get_next_line(int fd, char **line)
{

}
