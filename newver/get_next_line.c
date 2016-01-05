/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:34:52 by tfolly            #+#    #+#             */
/*   Updated: 2016/01/05 18:19:55 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_stock		*check_fd(const int fd, t_stock *stock)
{
	ft_putendl("appel de check_fd");
	if (!stock)
	{
		if (!(stock = (t_stock*)malloc(sizeof(t_stock))))
			return (NULL);
		stock->fd = fd;
		stock->str = ft_strdup("");
		return (stock);
	}
	while ((stock->fd != fd) && stock->next)
		stock = stock->next;
	if (stock->fd == fd)
	{
		return (stock);
	}
	else
	{
		if (!(stock->next = (t_stock*)malloc(sizeof(t_stock))))
			return (NULL);
		stock = stock->next;
		stock->fd = fd;
		stock->str = ft_strdup("");
		return (stock);
	}
}

static int		bufcpy(char **line, t_stock *stock)
{
	ft_putendl("appel de bufcpy");
	int		n;
	int		i;
	char	*save;
	char	*addr;
	char	*tmp;

	tmp = stock->str;
	n = (int)(ft_strchr(tmp, '\n') - *tmp);
	*line = ft_strndup(tmp, n);
	save = tmp;
	tmp += n;
	i = 0;
	while (i < n) //repenser la maniere de mettre a jour tmp car ca c pas correct
	{
		addr = save + i;
		ft_memdel((void**)&addr);
		i++;
		
	}
	return (1);
}

static int		fill_tmp(t_stock *stock)
{
	ft_putendl("appel de fill_tmp");
	char	*tmp;
	char	buf[BUF_SIZE];
	int		nbr;
	char	*save;
	int		i;

	nbr = 1;
	i = 0;
	while (i < BUF_SIZE)
	{
		buf[i] = 0;
		i++;
	}
	tmp = stock->str;
	while (!(ft_strchr(buf, '\n') || ft_strchr(buf, -1) || nbr == 0))
	{
		nbr = read(stock->fd, buf, BUF_SIZE);
		save = tmp;
		tmp = (char*)ft_memalloc(ft_strlen(tmp) + BUF_SIZE);
		tmp = ft_strcpy(tmp, save);
		tmp = ft_strcat(tmp, (const char*)buf);
		ft_memdel((void**)&save);
		ft_putendl(tmp);
	}
	if (nbr == -1)
		return (-1);
	if (nbr == 0)
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_stock	*stock;
	int				status;
	t_stock			*tmp;

	if (!(tmp = check_fd(fd, stock)))
		return (-1);
	if (!(ft_strchr(tmp->str, '\n') || ft_strchr(tmp->str, -1)))
	{
		status = fill_tmp(tmp);
	}
	ft_putstr("stock->str : ");
	ft_putendl(tmp->str);
	bufcpy(line, tmp);
	// il faut mettre a jour str dans la liste chainee
	// penser au cas ou on a copier plsr \n
	return (1);
}

//manipuler chaine de char meilleur que manip stock directement car pas dupdate!!!
