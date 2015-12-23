#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	static char	*stock;
	char		*new;
	int		ret;
	char		*str;
	char		*save;

	while (!ft_strchr(stock, '\n'))	
	{
		new = (char*)ft_memalloc(ft_strlen(stock) + BUFF_SIZE + 1);
		if (stock)
			new = ft_strcpy(new, stock);
		save = new;
		while (*new)
			new++;
		ret = read(fd, new, BUFF_SIZE);
		ft_strdel(&stock);
		stock = save;
	}
	if (stock)
	{
		if ((ret = (int)(ft_strchr(stock, '\n') - ft_strlen(stock))))
		{
			*line = (char*)ft_memalloc(ret + 1);
			*line = ft_strncpy(*line, stock, ret);
			*line[ret] = '\0';
			stock = stock + ret;
			return (1);
		}
	}
	return (0);
}


//	if (!stock)
//	{
//		stock = (char*)malloc(BUFF_SIZE + 1); //rajouter return -1 si erreur
//		ret = read(fd, stock, BUFF_SIZE);     //rajouter return -1 si erreur
//		stock[BUFF_SIZE] = '\0';
//	}
//	if (stock)
//	{
//		if ((ret = (int)(ft_strchr(stock, '\n') - ft_strlen(stock))))
//		{
//			*line = ft_strncpy(*line, stock, ret);
//			*line[ret] = '\0';
//			stock = stock + ret;
//		}
//	}
//	return (0);
//}
