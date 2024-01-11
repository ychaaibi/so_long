/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:12:52 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 16:19:20 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*get_image(char *path, t_game *game)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &game->w, &game->h);
	return (img);
}

void	player_anime(t_game *game)
{
	void	*img;
	int		i;
	char	path_left[40];
	char	path_right[40];

	path_left[0] = 0;
	path_right[0] = 0;
	ft_strlcat(path_left, "Animation/Player/Go_Left/", 40);
	ft_strlcat(path_right, "Animation/Player/Go_Right/", 40);
	i = -1;
	while (++i < 5)
	{
		img = get_image(get_path_anime(path_right, i), game);
		if (!img)
			error();
		append_anime(&game->player->right_anime, init_anime(img));
		img = get_image(get_path_anime(path_left, i), game);
		if (!img)
			error();
		append_anime(&game->player->left_anime, init_anime(img));
		path_right[26] = 0;
		path_left[25] = 0;
	}
}

void	enemy_anime_right(t_game *game)
{
	void	*img;
	int		i;
	char	path[100];

	i = 0;
	path[0] = 0;
	ft_strlcat(path, "Animation/Enemy/Walk/Go_Right/", 100);
	while (i < 10)
	{
		img = get_image(get_path_anime(path, i), game);
		if (!img)
			error();
		append_anime(&game->enemy->right_anime, init_anime(img));
		path[30] = 0;
		i++;
	}
}

void	enemy_anime_left(t_game *game)
{
	void	*img;
	int		i;
	char	path[100];

	path[0] = 0;
	ft_strlcat(path, "Animation/Enemy/Walk/Go_Left/", 100);
	i = 0;
	while (i < 10)
	{
		img = get_image(get_path_anime(path, i), game);
		if (!img)
			error();
		append_anime(&game->enemy->left_anime, init_anime(img));
		path[29] = 0;
		i++;
	}
}

void	enemy_anime(t_game *game)
{
	enemy_anime_left(game);
	enemy_anime_right(game);
}
