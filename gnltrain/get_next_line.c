#include "get_next_line.h"


int	check_fd(const int fd, t_stock *stock)
{
	int	i;

	i = 0;
	while (stock->fd[i] != fd && i < FD_SIZE)
		i++;
	if (i == FD_SIZE)
	{
		i = 0;
		while (stock->fd[i] != 0)
			i++;
	}
	return (i); //il faudrait ajouter un retour -1 si tous les fd sont utilises
}

int	bufcpy(char **line, char **tmp)
{
	int	n;
	int	i;
	char	*save;
	char	*addr;

	n = (int)(ft_strchr(*tmp, '\n') - *tmp);
	*line = ft_strndup(*tmp, n);
	save = *tmp;
	*tmp += n;
	i = 0;
	while (i < n) //repenser la maniere de mettre a jour tmp car ca c pas correct
	{
		addr = save + i;
		ft_memdel((void**)&addr);
		i++;
		
	}
	return (1);
}

int	fill_tmp()
{

	return (1);
}

int	get_next_line(int const fd, char **line) //penser a verifier que stock str est bien init a 0
{
	t_stock		*stock;
	char		*tmp;
	int		i;

	i = check_fd(fd, stock);
	tmp = ft_strndup(stock->str[i], BUF_SIZE);
	if (!(ft_strchr(tmp, '\n') || ft_strchr(tmp, '\n')))
		fill_tmp();
	bufcpy(line, &tmp);
	ft_strcpy(stock->str[i], tmp);
	ft_memdel((void**)&tmp);
	return (1);
}
