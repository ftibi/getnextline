/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:02:14 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 14:42:35 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	char	*str;
	char	*save;
	char	**first;

	if (as != NULL && *as != NULL)
	{
		str = *as;
		first = as;
		while (*str != '\0')
		{
			save = str;
			ft_memdel((void**)&str);
			str++;
			save = NULL;
		}
		ft_memdel((void**)&str);
		str = NULL;
		*first = NULL;
	}
}
