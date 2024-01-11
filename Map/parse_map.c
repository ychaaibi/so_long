/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:33:42 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/06 12:18:09 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(int fd)
{
	char	*map;
	char	*temp;
	char	**map_split;
	char	buff[1024];
	int		bytes;

	map = NULL;
	if (read(fd, buff, 0) == -1)
		error();
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buff, 1024);
		if (bytes == -1)
			error();
		buff[bytes] = 0;
		temp = map;
		map = ft_strjoin(map, buff);
		free(temp);
	}
	map_split = ft_split(map, '\n');
	check_new_line(map, map_split);
	free(map);
	return (map_split);
}

char	**parse_map(char *map_path, int *length)
{
	char	**map;
	int		fd;

	check_ext(map_path);
	fd = open(map_path, 0);
	if (fd < 0)
		error();
	map = read_map(fd);
	valid_map(map);
	*length = 0;
	while (map[*length])
		(*length)++;
	close(fd);
	return (map);
}
