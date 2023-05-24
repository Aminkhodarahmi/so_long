/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_mp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:32:44 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/23 21:40:23 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill_p(int pos_x, int pos_y, char **map)
{
	if (map[pos_y][pos_x] != '0' && map[pos_y][pos_x] != 'C'
		&& map[pos_y][pos_x] != 'P')
		return ;
	map[pos_y][pos_x] = 'F';
	flood_fill_p(pos_x + 1, pos_y, map);
	flood_fill_p(pos_x, pos_y + 1, map);
	flood_fill_p(pos_x, pos_y - 1, map);
	flood_fill_p(pos_x - 1, pos_y, map);
	return ;
}

void	flood_fill_e(int pos_x, int pos_y, char **map)
{
	if (map[pos_y][pos_x] != '0' && map[pos_y][pos_x] != 'F'
		&& map[pos_y][pos_x] != 'E')
		return ;
	map[pos_y][pos_x] = 'I';
	flood_fill_e(pos_x + 1, pos_y, map);
	flood_fill_e(pos_x, pos_y + 1, map);
	flood_fill_e(pos_x, pos_y - 1, map);
	flood_fill_e(pos_x - 1, pos_y, map);
	return ;
}

int	check_path(t_map *map, char c)
{
	map->y = 0;
	while (map->dup_map[map->y])
	{
		map->x = 0;
		while (map->dup_map[map->y][map->x])
		{
			if (map->dup_map[map->y][map->x] == c)
				return (1);
			map->x++;
		}
		map->y++;
	}
	return (0);
}
