/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:53:54 by tfolly            #+#    #+#             */
/*   Updated: 2016/01/13 19:44:41 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2
# include "libft.h"
# include "fcntl.h"

int						get_next_line(int const fd, char **line);

typedef struct			s_stock
{
	char				*str;
	int					fd;
	int					status;
	struct s_stock		*next;
}						t_stock;

#endif
