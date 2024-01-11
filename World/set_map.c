/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:48:15 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 16:11:49 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->ground_img, x * 64, y * 96);
}

void	set_coll(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->collectibe_img, x * 64, y * 96);
}

void	set_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->exit_img, x * 64, y * 96);
}

void	set_player(t_game *game, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
}

void	set_map(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			set_ground(game, x, y);
			if (game->map[y][x] == '1')
				set_wall(game, game->map, x, y);
			else if (game->map[y][x] == 'C')
			{
				game->collectibe_count++;
				set_coll(game, x, y);
			}
			else if (game->map[y][x] == 'E')
				set_exit(game, x, y);
			else if (game->map[y][x] == 'P')
				set_player(game, x, y);
		}
	}
}
