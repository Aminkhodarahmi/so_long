/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:43:41 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/24 11:43:02 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	show_count(t_map *map)
{
	char	*count;

	count = ft_itoa2(map->mov);
	map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
			"./ambient/1.xpm", &map->show->w, &map->show->h);
	put_er_img(map);
	mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
		map->show->img, 0 * map->show->w, 0 * map->show->h);
	mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	mlx_string_put(map->show->mlx_ptr, map->show->win_ptr, 25, 25, 0xff0000,
		count);
	free(count);
}
