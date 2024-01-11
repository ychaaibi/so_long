/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:14:20 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/05 08:58:08 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collision(t_game *game)
{
	if ((game->enemy->x / 64 == game->player->x
			|| game->enemy->x / 64 + 1 == game->player->x)
		&& game->enemy->y / 96 == game->player->y)
		game->end = -1;
}
