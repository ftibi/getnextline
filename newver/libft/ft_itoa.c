/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:38:50 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 16:13:58 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_pow(unsigned int x, unsigned int n)
{
	if (n == 0)
		return (1);
	return (x * ft_pow(x, n - 1));
}

static int				charness(unsigned int n)
{
	unsigned char req;

	req = 1;
	if (n >= 1000000000)
		return (10);
	while (n >= ft_pow(10, req))
	{
		req++;
	}
	return ((n == req) ? req + 1 : req);
}

static void				remplissage(unsigned int nb, int i, char *res)
{
	while (i > 0 || nb != 0)
	{
		*res = nb / ft_pow(10, i - 1) + '0';
		nb = nb % ft_pow(10, i - 1);
		i--;
		res++;
	}
	*res = '\0';
}

char					*ft_itoa(int n)
{
	unsigned int	nb;
	int				signe;
	char			*res;
	char			*save;
	int				i;

	signe = (n >= 0) ? 1 : -1;
	nb = (n >= 0) ? n : -n;
	i = charness(nb);
	res = (char*)malloc(sizeof(char) * (i + 1 + (signe == -1)));
	if (!res)
		return (NULL);
	save = res;
	if (signe == -1)
	{
		*res = '-';
		res++;
	}
	remplissage(nb, i, res);
	return (save);
}
