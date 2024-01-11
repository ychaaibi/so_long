/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:59:26 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 08:14:11 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_left(t_game *game, int y)
{
	void	*img;

	if (y == 0)
	{
		img = get_image("Xpm/top_left.xpm", game);
		mlx_put_image_to_window(game->mlx, game->window, img, 0, y * 96);
	}
	else if (game->map[y + 1])
	{
		img = get_image("Xpm/left.xpm", game);
		mlx_put_image_to_window(game->mlx, game->window, img, 0, y * 96);
	}
	else if (!game->map[y + 1])
	{
		img = get_image("Xpm/bottom_left.xpm", game);
		mlx_put_image_to_window(game->mlx, game->window, img, 0, y * 96);
	}
}

void	set_top(t_game *game, int x)
{
	void	*img;

	if (game->map[0][x + 1])
	{
		img = get_image("Xpm/top.xpm", game);
		mlx_put_image_to_window(game->mlx, game->window, img, x * 64, 0);
	}
	else if (!game->map[0][x + 1])
	{
		img = get_image("Xpm/top_right.xpm", game);
		mlx_put_image_to_window(game->mlx, game->window, img, x * 64, 0);
	}
}

void	set_bottom(t_game *game, int x, int y)
{
	void	*img;

	if (!game->map[y][x + 1])
	{
		img = get_image("Xpm/bottom_right.xpm", game);
		mlx_put_image_to_window(game->mlx, game->window, img, x * 64, y * 96);
	}
	else
	{
		img = get_image("Xpm/bottom.xpm", game);
		mlx_put_image_to_window(game->mlx, game->window,
			img, x * 64, y * 96 + 12);
	}
}

void	set_right(t_game *game, int x, int y)
{
	void	*img;

	img = get_image("Xpm/right.xpm", game);
	mlx_put_image_to_window(game->mlx, game->window, img, x * 64, y * 96);
}

void	set_wall(t_game *game, char **map, int x, int y)
{
	void	*img;

	if (x == 0)
		set_left(game, y);
	else if (y == 0)
		set_top(game, x);
	else if (!map[y + 1])
		set_bottom(game, x, y);
	else if (!map[y][x + 1])
		set_right(game, x, y);
	else
	{
		img = get_image("Xpm/obstacle.xpm", game);
		mlx_put_image_to_window(game->mlx, game->window, img, x * 64, y * 96);
	}
}
