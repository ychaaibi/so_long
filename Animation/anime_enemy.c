/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:33:12 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/06 15:36:16 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	protect(t_game *game)
{
	if (game->map[game->enemy->y / 96][game->enemy->x / 64] == 'E')
		set_exit(game, game->enemy->x / 64, game->enemy->y / 96);
	if (game->map[game->enemy->y / 96][game->enemy->x / 64 + 1] == 'E')
		set_exit(game, game->enemy->x / 64 + 1, game->enemy->y / 96);
	if (game->map[game->enemy->y / 96][game->enemy->x / 64 - 1] == 'E')
		set_exit(game, game->enemy->x / 64 - 1, game->enemy->y / 96);
	if (game->map[game->enemy->y / 96][game->enemy->x / 64] == 'C')
		set_coll(game, game->enemy->x / 64, game->enemy->y / 96);
	if (game->map[game->enemy->y / 96][game->enemy->x / 64 + 1] == 'C')
		set_coll(game, game->enemy->x / 64 + 1, game->enemy->y / 96);
	if (game->map[game->enemy->y / 96][game->enemy->x / 64 - 1] == 'C')
		set_coll(game, game->enemy->x / 64 - 1, game->enemy->y / 96);
	if (game->map[game->enemy->y / 96][game->enemy->x / 64 + 1] == '1')
		set_wall(game, game->map, game->enemy->x / 64 + 1, game->enemy->y / 96);
}

void	anime_char(t_game *game)
{
	int	check;

	game->enemy->count = 0;
	mlx_put_image_to_window(game->mlx, game->window, game->ground_img,
		(game->enemy->x / 64) * 64, game->enemy->y);
	check = game->enemy->x / 64 + game->enemy->dir;
	if (!(game->enemy->x % 64)
		&& game->map[game->enemy->y / 96][check] == '1')
		game->enemy->dir = game->enemy->dir ^ -1 ^ 1;
	else
	{
		mlx_put_image_to_window(game->mlx, game->window, game->ground_img,
			(game->enemy->x / 64 + 1) * 64, game->enemy->y);
		protect(game);
		game->enemy->x += game->enemy->dir;
		mlx_put_image_to_window(game->mlx, game->window, game->ground_img,
			(game->enemy->x / 64) * 64, game->enemy->y);
	}
	protect(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->enemy->current_anime->img,
		game->enemy->x, game->enemy->y);
}

void	anime_enemy(t_game *game)
{
	if (game->enemy->count > 500)
	{
		if (!game->enemy->current_anime || !game->enemy->current_anime->next)
		{
			if (game->enemy->dir == 1)
				game->enemy->current_anime = game->enemy->right_anime;
			else
				game->enemy->current_anime = game->enemy->left_anime;
		}
		else
			game->enemy->current_anime = game->enemy->current_anime->next;
		anime_char(game);
	}
	else
		game->enemy->count++;
}
