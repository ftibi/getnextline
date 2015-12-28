/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:25:25 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 17:18:51 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_strsplit(char const *str, char c)
{
	char	**tab;
	t_list	*newlst;
	t_list	*newelem;

	tab = ft_strsplit(str, c);
	newlst = ft_lstnew(*tab, ft_strlen(*tab));
	(*tab)++;
	while (*tab)
	{
		newelem = ft_lstnew(*tab, ft_strlen(*tab));
		ft_lstadd_end(&newlst, newelem);
		(*tab)++;
	}
	return (newlst);
}
