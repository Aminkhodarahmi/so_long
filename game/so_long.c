/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:35:20 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/24 18:38:29 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_arg(int argc, char *argv[], t_map *map)
{
	map->fd = open(argv[1], O_RDONLY);
	if (argc != 2 || name_map(argv[1]) == 1 || map->fd < 0)
	{
		ft_putstr_fd("Error:\nInvalid argument or file\n \
		Try ./so_long 'map.ber'", 2);
		exit(1);
	}
}

void	setup_mlx(t_map *map)
{
	map->show->mlx_ptr = mlx_init();
	map->len = ft_strlen(map->split_map[0]);
	map->show->win_ptr = mlx_new_window(map->show->mlx_ptr, \
				70 * map->len, 70 * map->lines, "So_long");
	map->keycode = 2;
	showmap(map);
	map->check_c = 0;
	map->mov = 0;
	mlx_hook(map->show->win_ptr, 2, 0, move_map, map);
	mlx_hook(map->show->win_ptr, 17, 0, (void *)exit, map);
}

void	run_game_loop(t_map *map)
{
	mlx_loop(map->show->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_map		m;
	t_player	player;
	t_show		s;

	check_arg(argc, argv, &m);
	m.show = &s;
	m.player = &player;
	m.split_map = read_map(m.fd, &m);
	all_check(&m, &player);
	setup_mlx(&m);
	run_game_loop(&m);
	return (0);
}
