/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:39:49 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/23 10:24:34 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t			i;
	size_t			j;
	size_t			rtn;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (!dest && !size)
		return (i);
	while (dest[j])
		j++;
	if (j <= size)
		rtn = i + j;
	else
		rtn = i + size;
	i = 0;
	while (src[i] && j + 1 < size)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (rtn);
}
