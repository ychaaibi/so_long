/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:35:26 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 17:02:41 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moves_count(t_game *game)
{
	char	*moves;
	char	*string_put;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, "Xpm/back.xpm", &game->w, &game->h);
	mlx_put_image_to_window(game->mlx, game->window, img,
		(game->width / 2 - 1) * 64, 0);
	mlx_destroy_image(game->mlx, img);
	moves = ft_itoa(game->player->moves);
	string_put = ft_strjoin("moves : ", moves);
	write(1, moves, ft_strlen(moves));
	write(1, "\n", 1);
	free(moves);
	mlx_string_put(game->mlx, game->window,
		(game->width / 2 - 1) * 64, 0, 0, string_put);
	free(string_put);
}
