/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:33:45 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/06 14:53:33 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	anime_player(t_game *game)
{
	if (game->player->count > 500)
	{
		if (!game->player->current_anime || !game->player->current_anime->next)
		{
			if (!game->player->dir)
				game->player->current_anime = game->player->right_anime;
			else
				game->player->current_anime = game->player->left_anime;
		}
		else
			game->player->current_anime = game->player->current_anime->next;
		mlx_put_image_to_window(game->mlx, game->window, game->ground_img,
			game->player->x * 64, game->player->y * 96);
		if (game->map[game->player->y][game->player->x] == 'E' && !game->end
			&& (game->collectibe_count
			||game->map[game->player->x][game->player->y] != 'E'))
			set_exit(game, game->player->x, game->player->y);
		mlx_put_image_to_window(game->mlx, game->window,
			game->player->current_anime->img,
			game->player->x * 64, game->player->y * 96);
		game->player->count = 0;
	}
	else
		game->player->count++;
}
