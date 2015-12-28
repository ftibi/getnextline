/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:58:33 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/07 15:02:12 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void				*save;

	save = ft_memalloc(len);
	if (!save)
		return (NULL);
	save = ft_memcpy(save, src, len);
	dst = ft_memcpy(dst, save, len);
	ft_memdel(&save);
	return (dst);
}
