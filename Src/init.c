/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:47:36 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/06 12:23:44 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_enemy(t_game *game)
{
	int	x;
	int	y;

	y = game->height - 1;
	while (y >= 0)
	{
		x = 1;
		while (x < game->width)
		{
			if (game->map[y][x] == '0'
				&& game->map[y][x - 1] != 'P'
			&& game->map[y][x + 1] != 'P')
			{
				game->enemy->x = x * 64;
				game->enemy->y = y * 96;
				game->enemy->exist = 1;
				return ;
			}
			x++;
		}
		y--;
	}
}

void	init_images(t_game *game)
{
	game->ground_img = get_image("Xpm/ground.xpm", game);
	if (!game->ground_img)
		error();
	game->collectibe_img = get_image("Xpm/collectibe.xpm", game);
	if (!game->ground_img)
		error();
	game->exit_img = get_image("Xpm/exit.xpm", game);
	if (!game->exit_img)
		error();
	game->exit_open_img = get_image("Xpm/exit_open.xpm", game);
	if (!game->exit_open_img)
		error();
}

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		error();
	player->x = 1;
	player->y = 1;
	player->moves = 0;
	player->left_anime = NULL;
	player->right_anime = NULL;
	player->current_anime = NULL;
	player->count = 501;
	player->dir = 0;
	return (player);
}

t_enemy	*init_enemy(void)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!enemy)
		error();
	enemy->exist = 0;
	enemy->x = 5 * 64;
	enemy->y = 96 * 2;
	enemy->dir = 1;
	enemy->count = 751;
	enemy->right_anime = NULL;
	enemy->left_anime = NULL;
	enemy->current_anime = NULL;
	enemy->curr_anime_ind = 0;
	return (enemy);
}

t_game	*init_game(int h, int w, char **map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error();
	game->mlx = mlx_init();
	if (!game->mlx)
		error();
	game->window = mlx_new_window(game->mlx, w * 64, h * 96, "So Long");
	if (!game->window)
		error();
	game->width = w;
	game->height = h;
	game->player = init_player();
	game->enemy = init_enemy();
	game->map = map;
	game->collectibe_count = 0;
	game->end_count = 0;
	game->end = 0;
	init_images(game);
	player_anime(game);
	set_enemy(game);
	enemy_anime(game);
	return (game);
}
