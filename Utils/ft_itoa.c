/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:11:27 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/01/04 11:31:35 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	len(int n)
{
	int				l;
	unsigned int	nb;

	l = 1;
	if (n < 0)
	{
		l++;
		nb = -n;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	nb;
	int				l;

	l = len(n);
	num = (char *)malloc(sizeof(char) * (l + 1));
	if (!num)
		return (NULL);
	num[l] = 0;
	num[0] = '-';
	l--;
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (nb >= 10)
	{
		num[l--] = nb % 10 + 48;
		nb /= 10;
	}
	num[l] = nb % 10 + 48;
	return (num);
}
