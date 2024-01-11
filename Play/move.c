/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:00:12 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 16:09:44 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_win(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->ground_img, game->player->x * 64, game->player->y * 96);
	mlx_put_image_to_window(game->mlx, game->window,
		game->exit_open_img, game->player->x * 64, game->player->y * 96);
	game->end = 1;
}

void	player_move(int keycode, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->ground_img,
		game->player->x * 64, game->player->y * 96);
	if (game->map[game->player->y][game->player->x] == 'E')
		set_exit(game, game->player->x, game->player->y);
	if (keycode == 2)
		player_move_right(game);
	else if (keycode == 0)
		player_move_left(game);
	else if (keycode == 13)
		player_move_up(game);
	else if (keycode == 1)
		player_move_down(game);
	if (game->map[game->player->y][game->player->x] == 'C')
	{
		game->collectibe_count--;
		game->map[game->player->y][game->player->x] = '0';
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->player->current_anime->img,
		game->player->x * 64, game->player->y * 96);
	if (game->map[game->player->y][game->player->x] == 'E'
		&& !game->collectibe_count)
		player_win(game);
	moves_count(game);
}
