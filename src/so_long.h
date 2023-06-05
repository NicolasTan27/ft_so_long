/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:09:41 by ntan              #+#    #+#             */
/*   Updated: 2022/03/17 13:28:13 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define MAX_MAP 20480

typedef struct s_xy {
	int	x;
	int	y;
}	t_xy;

typedef struct s_image {
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_xy	size;
}				t_image;	

typedef struct s_4sides {
	int			side;
	t_image		up;
	t_image		down;
	t_image		right;
	t_image		left;
}				t_4sides;

typedef struct s_anim {
	t_image		img_1;
	t_image		img_2;
	t_image		img_3;
	t_image		img_4;
	t_image		img_5;
}				t_anim;

typedef struct s_sprites {
	t_image		s_0;
	t_image		s_1;
	t_image		s_e;
	t_image		s_c;
	t_4sides	s_f;
	t_4sides	s_p;
	t_4sides	s_m;
	t_anim		pok_anim;
}				t_sprites;

typedef struct s_map {
	char	**map;
	t_xy	size;
	int		m;
	int		c;
	int		max_c;
	int		moves;
	t_xy	p_pos;
	t_xy	f_pos;
	t_xy	m_pos;
	int		pok_anim_state;
	t_xy	anim_pos;
	int		end_status;
	int		max_x;
	int		max_y;
}			t_map;

typedef struct s_win {
	void	*win;
	t_xy	size;
}			t_win;

typedef struct s_data {
	void		*mlx;
	t_win		win;
	t_map		map;
	t_sprites	sprites;
}				t_data;

t_win	new_window(void *mlx, int widht, int height, char *name);
t_image	create_sprite(t_data *prog, void *mlx, char *path);
int		keyboard_input(int key, void *param);
int		check_map(t_map *map);
int		parse_map(t_map *map, char *path);
void	print_map(t_map map);
t_map	get_player_pos(t_map map);
t_map	get_mechant_pos(t_map map);
int		move_up(t_map *map);
int		move_down(t_map *map);
int		move_left(t_map *map);
int		move_right(t_map *map);
int		follow(t_map *map);
void	init_sprites(t_data *prog);
void	init_sprites_3(t_data *prog);
void	display(t_data *prog);
void	pok_anim(t_data *prog);
int		update(void *param);
void	le_mechant(t_map *map);
void	check_lose(t_map *map);
char	*ft_itoa(int n);
int		ft_strlen(char *str);
int		ending(t_data *prog);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		check_extent(char *av);
void	free_map(t_data *prog);

#endif