/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:36:07 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/22 20:36:30 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_dup(t_map *map)
{
	int	i;

	i = 0;
	map->dup_map = malloc((map->lines + 1) * (sizeof(char *)));
	while (map->split_map[i])
	{
		map->dup_map[i] = ft_strdup(map->split_map[i]);
		i++;
	}
	map->dup_map[i] = 0;
	return (map->dup_map);
}

int	ft_strchr_wm(char *split_map, int c)
{
	while (*split_map)
	{
		if (*split_map == c)
			return (1);
		split_map++;
	}
	return (0);
}

int	count_line(t_map *map)
{
	map->lines = 0;
	while (map->split_map[map->lines])
		map->lines++;
	return (map->lines);
}

void	put_er_img(t_map *map)
{
	if (!map->show->img)
	{
		write(STDERR_FILENO, "Error\nImg does not exist\n", 25);
		exit(1);
	}
}
