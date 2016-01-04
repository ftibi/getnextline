#include "get_next_line.h"
#include <unistd.h>

// rempli stock jusqu a un \n ou EOF
// devrait aussi nettoyer lancienne version de stock
int	fill_stock(int fd, char **stock, int *lec)
{
	char	*tmp;
	char	*new;
	char	*save;
	int	ret;
	
	tmp = *stock;
	ret = 1;
	while (ret && !ft_strchr(tmp, '\n'))
	{
		ft_putendl("remplissage stock");
		if (!(new = (char*)ft_memalloc(ft_strlen(tmp) + BUF_SIZE + 1)))
			return (-1);
		if (tmp)
			new = ft_strcpy(new, tmp);
		save = new;
		while (*new)
			new++;
		ret = read(fd, new, BUF_SIZE);
		if (ret < 0)
			return (ret);
		if (ft_strlen(new) != BUF_SIZE)
		{
			ft_putendl("fin lecture");
		//	*lec = 1;
			//ret = 0;
		}
	//	if (ret == 0)
	//		return (0);
		tmp = save;
		ft_putendl("fin du remplissage stock");
	}
	*stock = tmp;
	return ((ret >= 1) ? 1 : 0);
}

//rempli line avec stock et met stock a jour
int	fill_line(char **line, char **stock, int ret)
{
	ft_putendl("fill_line");	
	if (ret == 0)
	{
		*line = ft_strdup(*stock);
		return (0);
	}
	if ((ret = (int)(ft_strchr(*stock, '\n') - *stock)))
	{
		ft_putstr("stock ***");
		ft_putstr(*stock);
		ft_putendl("***");
		if (!(*line = (char*)ft_memalloc(ret + 1)))
				return (-1);
		*line = ft_strncpy(*line, *stock, ret);
		*stock += ret + 1;
		return (1);
	}
	else
	{
		ft_putendl("fin de lec");
		*line = ft_strdup("");
		*stock = NULL;
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*stock;
	int		ret;
	static int	lec;
	
	if (lec == 0)
		ret = fill_stock(fd, &stock, &lec);
	if (ret < 0)
	{
		ft_putstr("err_fil_stock");
		return (ret);
	}
	ret = fill_line(line, &stock, ret);
	if (ret == -1)
		ft_putstr("err_fil_line");
	return (ret);
}
