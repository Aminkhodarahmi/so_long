/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:30:52 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/24 11:44:34 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_di(t_map *map, int x, int y)
{
	if (map->keycode == 0 || map->keycode == 123)
		a(map, x, y);
	else if (map->keycode == 2 || map->keycode == 124)
		d(map, x, y);
	else if (map->keycode == 1 || map->keycode == 125)
		s(map, x, y);
	else
		w(map, x, y);
}

static void	put_p(t_map *map, int y, int x)
{
	if (map->split_map[y][x] == '0')
	{
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./ambient/0.xpm", &map->show->w, &map->show->h);
		put_er_img(map);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
	else if (map->split_map[y][x] == 'P')
		put_di(map, x, y);
}

static void	mis_p(t_map *map, int pos_x, int pos_y)
{
	map->split_map[map->player->pos_y][map->player->pos_x] = '0';
	map->split_map[pos_y][pos_x] = 'P';
	put_p(map, map->player->pos_y, map->player->pos_x);
	put_p(map, pos_y, pos_x);
	map->player->pos_y = pos_y;
	map->player->pos_x = pos_x;
}

static void	move(t_map *map, int pos_y, int pos_x)
{
	char	cell;

	cell = map->split_map[pos_y][pos_x];
	if (cell == '0' || cell == 'C')
	{
		map->mov += 1;
		print_m(map);
		if (cell == 'C')
			map->check_c++;
		mis_p(map, pos_x, pos_y);
	}
	else if (cell == 'E' && map->check_c == map->count[1])
	{
		write(1, "        W               W   IIIIIIII  N       N \n", 50);
		write(1, "        W       W       W      I      N   N   N  \n", 51);
		write(1, "        W      W W      W      I      N    N  N  \n", 51);
		write(1, "        W     W   W     W      I      N     N N  \n", 51);
		write(1, "        W    W     W    W      I      N      NN  \n", 51);
		write(1, "         W  W       W  W       I      N       N  \n", 51);
		write(1, "          WW         WW     IIIIIIII  N       N \n", 50);
		write(1, "\n", 1);
		exit(0);
	}
	move_sup(map);
	show_count(map);
}

int	move_map(int keycode, t_map *map)
{
	int	new_y;
	int	new_x;

	new_y = map->player->pos_y;
	new_x = map->player->pos_x;
	if (keycode == 53)
		exit(0);
	else if (keycode == 13 || keycode == 126)
		new_y--;
	else if (keycode == 0 || keycode == 123)
		new_x--;
	else if (keycode == 1 || keycode == 125)
		new_y++;
	else if (keycode == 2 || keycode == 124)
		new_x++;
	else
		return (0);
	map->keycode = keycode;
	move(map, new_y, new_x);
	return (0);
}
