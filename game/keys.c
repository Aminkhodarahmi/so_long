/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:26:19 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/23 19:46:39 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	a(t_map *map, int x, int y)
{
	static int	m;
	char		*img_path;

	if (m)
	{
		img_path = "./ambient/PL1.xpm";
		m = 0;
	}
	else
	{
		img_path = "./ambient/PL2.xpm";
		m = 1;
	}
	map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr, img_path, \
											&map->show->w, &map->show->h);
	if (!map->show->img)
	{
		ft_putstr_fd("Failed to load player image\n", 2);
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr, \
							map->show->img, x * map->show->w, y * map->show->h);
	mlx_destroy_image(map->show->mlx_ptr, map->show->img);
}

void	d(t_map *map, int x, int y)
{
	static int	m;
	char		*img_path;

	if (m)
	{
		m = 0;
		img_path = "./ambient/PR1.xpm";
	}
	else
	{
		m = 1;
		img_path = "./ambient/PR2.xpm";
	}
	map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr, \
					img_path, &map->show->w, &map->show->h);
	if (map->show->img == NULL)
	{
		ft_putstr_fd("Error: Failed to load player image\n", 2);
		exit(1);
	}
	mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr, \
				map->show->img, x * map->show->w, y * map->show->h);
	mlx_destroy_image(map->show->mlx_ptr, map->show->img);
}

void	load_image(t_map *map, char *path, int x, int y)
{
	map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr, \
							path, &map->show->w, &map->show->h);
	if (!map->show->img)
	{
		ft_putstr_fd("Error\nFailed to load image\n", 2);
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr, \
				map->show->img, x * map->show->w, y * map->show->h);
	mlx_destroy_image(map->show->mlx_ptr, map->show->img);
}

void	w(t_map *map, int x, int y)
{
	static int	m;

	if (m)
	{
		m = 0;
		load_image(map, "./ambient/PU1.xpm", x, y);
	}
	else
	{
		m = 1;
		load_image(map, "./ambient/PU2.xpm", x, y);
	}
}

void	s(t_map *map, int x, int y)
{
	static int	m;

	m = 0;
	if (m)
	{
		m = 0;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr, \
			"./ambient/PD1.xpm", &map->show->w, &map->show->h);
	}
	else
	{
		m = 1;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr, \
			"./ambient/PD2.xpm", &map->show->w, &map->show->h);
	}
	if (!map->show->img)
	{
		ft_putstr_fd("Error\nFailed to load image\n", 2);
		exit(EXIT_FAILURE);
	}
	put_er_img(map);
	mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr, \
		map->show->img, x * map->show->w, y * map->show->h);
	mlx_destroy_image(map->show->mlx_ptr, map->show->img);
}
