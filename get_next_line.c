/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:34:52 by tfolly            #+#    #+#             */
/*   Updated: 2016/01/08 21:10:50 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_stock		*check_fd(const int fd, t_stock *stock, t_stock **save)
{
	if (!stock)
	{
		if (!(stock = (t_stock*)malloc(sizeof(t_stock))))
			return (NULL);
		stock->fd = fd;
		stock->str = ft_strdup("");
		stock->status = 1;
		stock->next = NULL;
		*save = stock;
		return (stock);
	}
	while ((stock->fd != fd) && stock->next)
		stock = stock->next;
	if (stock->fd != fd)
	{
		if (!(stock->next = (t_stock*)ft_memalloc(sizeof(t_stock))))
			return (NULL);
		stock = stock->next;
		stock->fd = fd;
		stock->str = ft_strdup("");
		stock->status = 1;
		stock->next = NULL;
	}
	return (stock);
}

static int			delstock(int fd, t_stock *stock)
{
	t_stock	*save;

	if (!stock)
		return (0);
	save = stock;
	while (stock && stock->next)
	{
		if (stock->fd == fd)
		{
			save->next = stock->next;
			if (stock->str) //verifier que c bien utile
				ft_memdel((void**)&(stock->str));
			ft_memdel((void**)&stock);
			stock = save->next;
		}
		else
		{
			save = stock;
			stock = stock->next;
		}
	}
	return (1);
}

static int			bufcpy(char **line, t_stock *stock, t_stock *stock_save)
{
	int		n;
	char	*save;
	char	*tmp;

	if (!stock->str)
	{
		*line = ft_strdup("");
		return (0);
	}
	tmp = stock->str;
	n = (int)(ft_strchr(tmp, '\n') - tmp);
	n = ((unsigned int)n > ft_strlen(tmp) + 1) ? ft_strlen(tmp) : n;
	*line = ft_strndup(tmp, n);
	save = tmp;
	tmp += n + 1;
	tmp = ft_strdup(tmp);
//	if (save)
//		ft_memdel((void**)&save);
	stock->str = tmp;
	if (!ft_strcmp(stock->str, ft_strdup("")) && !stock->status)
		delstock(stock->fd, stock_save);
	return (1);
}

static int			fill_tmp(t_stock *stock)
{
	char	*tmp;
	char	buf[BUF_SIZE];
	int		nbr;
	char	*save;
	int		len;

	nbr = BUF_SIZE;
	tmp = stock->str;
	while ((!ft_strchr(tmp, '\n') || nbr == 0) && nbr == BUF_SIZE)
	{
		ft_memset(buf, 0, BUF_SIZE);
		if ((nbr = read(stock->fd, buf, BUF_SIZE)) == -1)
			return (nbr);
		if (nbr < BUF_SIZE)
			stock->status = 0;
		save = tmp;
		len = ft_strlen(tmp);
		if (!(tmp = (char*)ft_memalloc(len + BUF_SIZE + 1)))
			return (-1);
		tmp = ft_strcpy(tmp, save);
		tmp = ft_strncat(tmp, (const char*)buf, BUF_SIZE);
		if (save)
			ft_memdel((void**)&save);
		stock->str = tmp;
	}
	return ((nbr <= 0) ? nbr : 1);
}

int					get_next_line(int const fd, char **line)
{
	t_stock			*stock;
	static t_stock	*save;

	if (!line)
		return (-1);
	stock = save;
	if (!(stock = check_fd(fd, stock, &save)))
		return (-1);
	ft_strchr(stock->str, '\n');
	if (!(ft_strchr(stock->str, '\n')))
		stock->status = fill_tmp(stock);
	if (stock->status == -1)
		return (stock->status);
	bufcpy(line, stock, save);
	return (stock->status);
}
