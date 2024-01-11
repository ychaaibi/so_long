/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:49:51 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 16:48:35 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_game *game)
{
	static int		fin = 0;
	static int		stay = 0;

	if (!fin && !stay)
	{
		stay = 1;
		fin = game->width * game->height;
	}
	if (fin)
		fin += over(game);
	else
		exit(0);
}
