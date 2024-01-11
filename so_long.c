/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:39:27 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/06 15:16:42 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_over(void)
{
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 2 || keycode == 0 || keycode == 1 || keycode == 13)
		player_move(keycode, game);
	else if (keycode == 53)
		exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		*game;
	char		**map;
	int			length;

	if (ac != 2)
		error();
	map = parse_map(av[1], &length);
	game = init_game(length, ft_strlen(map[0]), map);
	set_map(game);
	moves_count(game);
	mlx_hook(game->window, 2, 0, key_hook, game);
	mlx_hook(game->window, 17, 0, game_over, NULL);
	mlx_loop_hook(game->mlx, anime, game);
	mlx_loop(game->mlx);
	return (0);
}
