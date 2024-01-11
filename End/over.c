/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:53:11 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 16:48:30 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_end	g_end;

int	fin1(t_game *game)
{
	if (g_end.x < game->width && !g_end.fin[0])
	{
		game->player->dir = 0;
		game->player->x = g_end.x;
		game->player->y = g_end.y;
		mlx_put_image_to_window(game->mlx, game->window,
			game->ground_img, (g_end.x++ - 1) * 64, g_end.y * 96);
		return (-1);
	}
	if (!g_end.fin[0])
	{
		g_end.fin[0] = 1;
		g_end.x--;
		g_end.y++;
	}
	return (-2);
}

int	fin2(t_game *game)
{
	if (g_end.y < game->height && !g_end.fin[1])
	{
		game->player->x = g_end.x;
		game->player->y = g_end.y;
		mlx_put_image_to_window(game->mlx, game->window,
			game->ground_img, g_end.x * 64, (g_end.y++ - 1) * 96);
		return (-1);
	}
	if (!g_end.fin[1])
	{
		g_end.fin[1] = 1;
		g_end.x--;
		g_end.y--;
	}
	return (-2);
}

int	fin3(t_game *game)
{
	if (g_end.x >= g_end.start_x && !g_end.fin[2])
	{
		game->player->dir = 1;
		game->player->x = g_end.x;
		game->player->y = g_end.y;
		mlx_put_image_to_window(game->mlx, game->window,
			game->ground_img, (g_end.x-- + 1) * 64, g_end.y * 96);
		return (-1);
	}
	if (!g_end.fin[2])
	{
		g_end.fin[2] = 1;
		g_end.y--;
		g_end.x++;
	}
	return (-2);
}

int	fin4(t_game *game)
{
	if (g_end.y > g_end.start_y)
	{
		game->player->x = g_end.x;
		game->player->y = g_end.y;
		mlx_put_image_to_window(game->mlx, game->window,
			game->ground_img, g_end.x * 64, (g_end.y-- + 1) * 96);
		return (-1);
	}
	return (-2);
}

int	over(t_game *game)
{
	if (game->end_count < 250)
	{
		game->end_count++;
		return (0);
	}
	game->end_count = 0;
	if (fin1(game) == -1)
		return (-1);
	if (fin2(game) == -1)
		return (-1);
	if (fin3(game) == -1)
		return (-1);
	if (fin4(game) == -1)
		return (-1);
	g_end.fin[0] = 0;
	g_end.fin[1] = 0;
	g_end.fin[2] = 0;
	game->width--;
	game->height--;
	g_end.start_x++;
	g_end.start_y++;
	g_end.x = g_end.start_x;
	g_end.y = g_end.start_y;
	return (0);
}
