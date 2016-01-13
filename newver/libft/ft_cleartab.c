/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleartab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:32:24 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 17:01:10 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//libere la memoire d un tableau et ses pointeurs a 0

void	ft_cleartab(void **tab, size_t size)
{
	size_t	i;
	void	*save;
	void	*tmp;

	i = 0;
	tmp = *tab;
	while (i < size)
	{
		save = tmp;
		ft_strdel(tmp);
		i++;
		if (i < size)
			tmp = save + 1;
	}
	ft_memdel(tab);
	tab = NULL;
}
