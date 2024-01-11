/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:53:09 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/11/09 11:59:15 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*add;
	size_t			len;

	len = count * size;
	add = (unsigned char *)malloc(len);
	if (!add)
		return (NULL);
	while (len >= 0)
		add[--len] = 0;
	return (add);
}
