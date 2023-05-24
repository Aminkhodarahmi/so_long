/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_mp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:38:23 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/22 20:38:28 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wall_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->split_map[y])
	{
		x = 0;
		while (map->split_map[y][x])
		{
			if (x == 0 || y == 0 || x == (int)ft_strlen(map->split_map[y]) - 1
				|| y == count_line(map) - 1)
			{
				if (map->split_map[y][x] != '1')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
