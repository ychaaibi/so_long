/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:03:57 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 16:04:42 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_move_up(t_game *game)
{
	if (game->map[game->player->y - 1][game->player->x] != '1')
	{
		game->player->moves++;
		game->player->y--;
	}
}

void	player_move_down(t_game *game)
{
	if (game->map[game->player->y + 1][game->player->x] != '1')
	{
		game->player->moves++;
		game->player->y++;
	}
}

void	player_move_right(t_game *game)
{
	if (game->map[game->player->y][game->player->x + 1] != '1')
	{
		if (game->player->dir)
		{
			game->player->current_anime = game->player->right_anime;
			game->player->dir = !game->player->dir;
		}
		game->player->moves++;
		game->player->x++;
	}
}

void	player_move_left(t_game *game)
{
	if (game->map[game->player->y][game->player->x - 1] != '1')
	{
		if (!game->player->dir)
		{
			game->player->current_anime = game->player->left_anime;
			game->player->dir = !game->player->dir;
		}
		game->player->moves++;
		game->player->x--;
	}
}
