/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:43:27 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/01/03 16:12:28 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_path_anime(char	*path, int index)
{
	char	ind[3];
	int		i;

	i = 0;
	if (index < 10)
		ind[i++] = index + 48;
	else
	{
		ind[i++] = index / 10 + 48;
		ind[i++] = index % 10 + 48;
	}
	ind[i] = 0;
	ft_strlcat(path, ind, 40);
	ft_strlcat(path, ".xpm", 40);
	return (path);
}

t_anime	*init_anime(void *img)
{
	t_anime	*anime;

	anime = (t_anime *)malloc(sizeof(t_anime));
	if (!anime)
		error();
	anime->img = img;
	anime->next = NULL;
	return (anime);
}

void	append_anime(t_anime **head, t_anime *anime)
{
	t_anime	*anim;

	if (!*head)
	{
		*head = anime;
		return ;
	}
	anim = *head;
	while (anim->next)
		anim = anim->next;
	anim->next = anime;
}
