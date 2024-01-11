/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 09:48:52 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 17:01:49 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <string.h>

int	anime(t_game *game)
{
	static int	fix;

	if (!game->end)
	{
		anime_player(game);
		if (game->enemy->exist)
			anime_enemy(game);
		collision(game);
	}
	else if (game->end == 1)
	{
		if (!fix && ++fix)
			write(1, "You Win !!\n", 11);
		end_game(game);
	}
	else
	{
		if (!fix)
			write(1, "You Lose !!\n", 12);
		if (fix++ < 1000 && game->enemy->exist)
			anime_enemy(game);
		end_game(game);
	}
	return (0);
}
