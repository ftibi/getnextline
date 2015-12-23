#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int const fd, char **line)
{
	static char	*stock;
	char		*new;
	int		ret;
	char		*str;
	char		*save;

	ft_putstr("stock : ");
	ft_putendl(stock);
	ret = 1;
	while (!ft_strchr(stock, '\n') && ret)	
	{
		new = (char*)ft_memalloc(ft_strlen(stock) + BUFF_SIZE + 1);
		if (stock)
			new = ft_strcpy(new, stock);
		save = new;
		while (*new)
			new++;
		ret = read(fd, new, BUFF_SIZE);
		stock = save;
		ft_putendl("ici");
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
