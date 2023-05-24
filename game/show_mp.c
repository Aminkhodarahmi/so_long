/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:34:54 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/22 21:05:30 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_m(t_map *map)
{
	ft_putstr_fd("the cureent number of mouvements: ", 1);
	ft_putnbr_fd(map->mov, 1);
	ft_putchar_fd('\n', 1);
}

void	put_img(t_map *map, char *path_img, char c)
{
	int	y;
	int	x;

	y = 0;
	while (map->split_map[y])
	{
		x = 0;
		while (map->split_map[y][x])
		{
			if (map->split_map[y][x] == c)
			{
				map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr, \
				path_img, &map->show->w, &map->show->h);
				put_er_img(map);
				mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr, \
										map->show->img, x * map->show->w, \
										y * map->show->h);
				mlx_destroy_image(map->show->mlx_ptr, map->show->img);
			}
			x++;
		}
		y++;
	}
}

void	ft_path(t_map *map)
{
	char	c;
	char	*path;

	c = map->split_map[map->y][map->x];
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
	{
		path = NULL;
		if (c == '0')
		path = "./ambient/0.xpm";
		else if (c == '1')
		path = "./ambient/1.xpm";
		else if (c == 'C')
		path = "./ambient/C1.xpm";
		else if (c == 'E')
		path = "./ambient/E0.xpm";
		else if (c == 'P')
		path = "./ambient/PI.xpm";
		put_img(map, path, c);
	}
}

void	showmap(t_map *map)
{
	print_m(map);
	map->y = -1;
	while (map->split_map[++map->y])
	{
		map->x = -1;
		while (map->split_map[map->y][++map->x])
		{
			ft_path(map);
		}
	}
}

void	move_sup(t_map *map)
{
	char	*curr_row;
	char	*curr_tile;

	curr_row = map->split_map[0];
	while (*curr_row)
	{
		curr_tile = curr_row;
		while (*curr_tile)
		{
			if (*curr_tile == 'E' && map->check_c == map->count[1])
			{
				put_img(map, "./ambient/E1.xpm", 'E');
			}
			curr_tile++;
		}
		curr_row += map->len + 1;
	}
}
