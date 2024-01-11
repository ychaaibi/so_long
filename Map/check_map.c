/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:01:36 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/06 14:44:36 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_ext(char *map_path)
{
	int	i;

	i = 0;
	while (map_path[i])
		i++;
	if (i < 4)
		error();
	if (ft_strcmp(map_path + i - 4, ".ber"))
		error();
}

void	check_new_line(char *full_map, char **line_map)
{
	int	full_len;
	int	total_line_len;
	int	line_count;

	line_count = 0;
	total_line_len = 0;
	full_len = ft_strlen(full_map);
	while (line_map[line_count])
		total_line_len += ft_strlen(line_map[line_count++]);
	if (total_line_len + line_count - 1 != full_len)
		error();
}

void	init_zeros(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		arr[i++] = 0;
}

void	check_map(char *line, int *cep, int y, int *dim)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if ((x * y == 0 || x == dim[1] - 1
				|| y == dim[0] - 1) && line[x] != '1')
			error();
		else if (line[x] == 'C')
			cep[0]++;
		else if (line[x] == 'E')
			cep[1]++;
		else if (line[x] == 'P')
			cep[2]++;
		else if (line[x] != '1' && line[x] != '0')
			error();
		x++;
	}
}

void	valid_map(char **map)
{
	int	y;
	int	dim[2];
	int	cep[3];

	y = 0;
	if (!map[0][0])
		error();
	dim[1] = ft_strlen(map[0]);
	dim[0] = 0;
	while (map[dim[0]])
		dim[0]++;
	init_zeros(cep, 3);
	while (map[y])
	{
		if (dim[1] != ft_strlen(map[y]))
			error();
		check_map(map[y], cep, y, dim);
		y++;
	}
	if (!cep[0] || !cep[1] || cep[2] != 1)
		error();
}
