/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:22:32 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/24 18:39:20 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <fcntl.h>
# include "./mlx/mlx.h"

typedef struct s_show
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	int			w;
	int			h;
}				t_show;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
}				t_player;

typedef struct s_map
{
	int			fd;
	char		*str;
	char		**split_map;
	int			y;
	int			x;
	int			lines;
	int			len;
	char		**dup_map;
	int			count[5];
	int			check_c;
	int			keycode;
	int			mov;
	t_show		*show;
	t_player	*player;
}				t_map;

/*So_long*/
void			ft_path(t_map *map);
char			**read_map(int fd, t_map *map);
int				composed_map(t_map *map);
int				onechar_map(t_map *map, t_player *player);
int				rectangular_map(t_map *map);
int				no_line(t_map *map);
int				wall_map(t_map *map);
void			flood_fill_p(int pos_x, int pos_y, char **map);
void			flood_fill_e(int pos_x, int pos_y, char **map);
int				check_path(t_map *map, char c);
int				name_map(char *name);
void			all_check(t_map *map, t_player *player);
void			put_img(t_map *map, char *path_img, char c);
void			showmap(t_map *map);
int				move_map(int keycode, t_map *map);
int				count_line(t_map *map);
char			**map_dup(t_map *map);
int				ft_strchr_wm(char *split_map, int c);
void			print_m(t_map *map);
void			a(t_map *map, int x, int y);
void			d(t_map *map, int x, int y);
void			w(t_map *map, int x, int y);
void			s(t_map *map, int x, int y);
void			move_sup(t_map *map);
void			put_er_img(t_map *map);
void			run_game_loop(t_map *map);
void			setup_mlx(t_map *map);
char			*ft_itoa2(int n);
void			show_count(t_map *map);
#endif
