#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int const fd, char **line)
{
	static char	*stock;
	char		*new;
	int		ret;
	char		*save;

	ret = 1;
	while (!ft_strchr(stock, '\n') && ret)	
	{
		new = (char*)ft_memalloc(ft_strlen(stock) + BUF_SIZE + 1);
		if (stock)
			new = ft_strcpy(new, stock);
		save = new;
		while (*new)
			new++;
		ret = read(fd, new, BUF_SIZE);
		if (ret < 1)
			return (ret);
		stock = save;
	}
	if (stock && ret)
	{
		if ((ret = (int)(ft_strchr(stock, '\n') - stock)))
		{
			*line = (char*)ft_memalloc(ret + 1);
			*line = ft_strncpy(*line, stock, ret);
			stock = stock + ret + 1;
			return (1);
		}
		else
		{
			*line = ft_strdup("");
			return (0);
		}
	}
	return (0);
}
