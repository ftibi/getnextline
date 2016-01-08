/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:34:52 by tfolly            #+#    #+#             */
/*   Updated: 2016/01/08 12:51:40 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_stock		*check_fd(const int fd, t_stock *stock, t_stock **save)
{
//	ft_putendl("checkfd");
	if (!stock)
	{
//		ft_putendl("!stock");
		if (!(stock = (t_stock*)malloc(sizeof(t_stock))))
			return (NULL);
		stock->fd = fd;
		stock->str = ft_strdup("");
		stock->status = 1;
		stock->next = NULL;
		*save = stock;
//		ft_putendl("end checkfd");
		return (stock);
	}
//	ft_putendl("stock");
	while ((stock->fd != fd) && stock->next)
		stock = stock->next;
	if (stock->fd == fd)
	{	
//		ft_putendl("fd found");
		return (stock);
	}
	else
	{
//		ft_putendl("else");
		if (!(stock->next = (t_stock*)ft_memalloc(sizeof(t_stock))))
			return (NULL);
		stock = stock->next;
		stock->fd = fd;
		stock->str = ft_strdup("");
		stock->status = 1;
		stock->next = NULL;
		return (stock);
	}
}

static int		delstock(int fd, t_stock *stock)
{
	t_stock	*save;

	if (!stock)
		return (0);
//	ft_putendl("delstock");
	save = stock;
	while (stock && stock->next)
	{
//		ft_putendl("while delstock");
		if (stock->fd == fd)
		{
			save->next = stock->next;
//			ft_putendl("del delstock");
			ft_memdel((void**)&(stock->str));
			ft_memdel((void**)&stock);
			stock = save->next;
		}
		else
		{
			save = stock;
			stock = stock->next;
		}
//		ft_putendl("end delstock");
	}
	return (1);
}

static int		bufcpy(char **line, t_stock *stock, t_stock *stock_save)
{
//	ft_putendl("bufcpy");
	int		n;
//	int		i;
	char	*save;
//	char	*addr;
	char	*tmp;

	if (!stock->str) // cette ligne est a repenser pour les conditions darret
	{
		*line = ft_strdup("");
		return (0);
	}
	tmp = stock->str;
//	ft_putstr("stock : ");
//	ft_putendl(stock->str);
	n = (int)(ft_strchr(tmp, '\n') - tmp);
//	ft_putnbr(n);
//	ft_putendl("");
	n = ((unsigned int)n > (unsigned int)ft_strlen(tmp) + 1) ? ft_strlen(tmp) : n;
//	ft_putnbr(n);
//	ft_putendl("");
	*line = ft_strndup(tmp, n);
	save = tmp;
	tmp += n;
	stock->str = tmp + 1;
	if (!ft_strcmp(stock->str, ft_strdup("")))
		delstock(stock->fd, stock_save);
//	ft_putstr("stock : ");
//	ft_putendl(stock->str);
	return (1);
}

static int		fill_tmp(t_stock *stock)
{
//	ft_putendl("filltmp");
	char	*tmp;
	char	buf[BUF_SIZE];
	int		nbr;
	char	*save;
	int		i;

	//if (stock->status == 0)
	//	return (0);
	nbr = BUF_SIZE;
	i = 0;
//	while (i < BUF_SIZE) //est ce que buff est donnee vide // utiliser memset a la place
//	{
//		buf[i] = 0;
//		i++;
//	}
	tmp = stock->str;
	while ((!ft_strchr(tmp, '\n') || nbr == 0) && nbr == BUF_SIZE)
	{
//		ft_putendl("while filltmp");
		ft_memset(buf, 0, BUF_SIZE);
		nbr = read(stock->fd, buf, BUF_SIZE);
		if (nbr < BUF_SIZE)
			stock->status = 0;
		if (nbr == -1)
			return (nbr);
		save = tmp;
		tmp = (char*)ft_memalloc(ft_strlen(tmp) + BUF_SIZE + 1);
		tmp = ft_strcpy(tmp, save);
		tmp = ft_strcat(tmp, (const char*)buf);
		tmp[ft_strlen(save) + nbr] = '\0';
		//if (save)
		//	ft_memdel((void**)&save);
		stock->str = tmp;
		//ft_putstr(" fill stock : ");
		//ft_putendl(stock->str);
	}
	if (nbr == -1)
		return (-1);
	if (nbr == 0)
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
//	ft_putendl("gnl");
	t_stock			*stock; // penser a travailler avec une adresse de pointeur
	static t_stock	*save;
	
	if (!line)
		return (-1);
//	if (!save)
//		save = (t_stock*)ft_memalloc(sizeof(t_stock));
//	if (!save)
//		return (-1);
	stock = save;
	if (!(stock = check_fd(fd, stock, &save)))
		return (-1);
//	ft_putendl("avant");
	ft_strchr(stock->str, '\n');
//	ft_putendl("apres");
	if (!(ft_strchr(stock->str, '\n'))) // && stock->status == 1)
		stock->status = fill_tmp(stock);
	//ft_putendl(stock->str);
	if (stock->status == -1)
		return (stock->status);
	bufcpy(line, stock, save);
	// il faut mettre a jour str dans la liste chainee
	// penser au cas ou on a copier plsr \n
//	if (fd == 0)
//		stock->status = 0;
	return (stock->status);
}
