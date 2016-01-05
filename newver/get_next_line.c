/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:34:52 by tfolly            #+#    #+#             */
/*   Updated: 2016/01/05 15:57:26 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_fd(const int fd, t_stock *stock)
{
	if (!stock) // creer nouvelle chaine
	{
		if (!stock = (t_stock*)malloc(sizeof(t_stock)))
			return (-1);
		stock->fd = fd;
		return (stock->str);
	}
	while (stock->fd != fd && stock->next)
		stock = stock->next;
	if (stock->fd == fd)
		return (stock->str);
	else //creer un nvx maillon
	{

	}
}

int				get_next_line(int const fd, char **line)
{
	return ();
}
