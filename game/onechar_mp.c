/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onechar_mp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:31:59 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/23 21:29:58 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_player(t_map *map, t_player *player)
{
	if (map->split_map[map->y][map->x] == 'P')
	{
		player->pos_x = map->x;
		player->pos_y = map->y;
		map->count[0]++;
	}
}

static void	check_collectible_and_exit(t_map *map)
{
	if (map->split_map[map->y][map->x] == 'C')
		map->count[1]++;
	if (map->split_map[map->y][map->x] == 'E')
		map->count[2]++;
}

static void	check_obstacle(t_map *map)
{
	if (map->split_map[map->y][map->x] == '0')
		map->count[3]++;
	if (map->split_map[map->y][map->x] == '1')
		map->count[4]++;
}

// check the number of any members
int	onechar_map(t_map *map, t_player *player)
{
	map->count[0] = 0;
	map->count[1] = 0;
	map->count[2] = 0;
	map->count[3] = 0;
	map->count[4] = 0;
	map->y = 0;
	while (map->split_map[map->y])
	{
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			check_player(map, player);
			check_collectible_and_exit(map);
			check_obstacle(map);
			map->x++;
		}
		map->y++;
	}
	if (map->count[0] != 1 || map->count[1] == 0 || map->count[2] != 1
		|| map->count[3] == 0 || map->count[4] == 0)
		return (1);
	return (0);
}
