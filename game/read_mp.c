/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:33:23 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/22 21:11:42 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(int fd, t_map *map)
{
	char	*line;
	char	**split_map;

	map->str = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->str = ft_strjoin(map->str, line);
		free(line);
	}
	split_map = ft_split(map->str, '\n');
	if (split_map == NULL)
	{
		ft_putstr_fd("Error\nFailed to split map\n", 2);
		exit(EXIT_FAILURE);
	}
	return (split_map);
}
