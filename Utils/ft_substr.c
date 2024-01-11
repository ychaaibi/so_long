/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:54:12 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 13:23:28 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		error();
	i = -1;
	while (++i < len && s[i])
		substr[i] = s[i + start];
	substr[i] = 0;
	return (substr);
}
