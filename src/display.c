/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:25:48 by ntan              #+#    #+#             */
/*   Updated: 2022/03/07 13:35:01 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_p(t_data *prog, int x, int y)
{
	if (prog->sprites.s_p.side == 0)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_p.down.image, x * 64, y * 64);
	else if (prog->sprites.s_p.side == 1)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_p.up.image, x * 64, y * 64);
	else if (prog->sprites.s_p.side == 2)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_p.right.image, x * 64, y * 64);
	else if (prog->sprites.s_p.side == 3)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_p.left.image, x * 64, y * 64);
}

void	display_f(t_data *prog, int x, int y)
{
	if (prog->sprites.s_f.side == 0)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_f.down.image, x * 64, y * 64);
	else if (prog->sprites.s_f.side == 1)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_f.up.image, x * 64, y * 64);
	else if (prog->sprites.s_f.side == 2)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_f.right.image, x * 64, y * 64);
	else if (prog->sprites.s_f.side == 3)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_f.left.image, x * 64, y * 64);
}

void	display_m(t_data *prog, int x, int y)
{
	if (prog->sprites.s_m.side == 0)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_m.down.image, x * 64, y * 64);
	else if (prog->sprites.s_m.side == 1)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_m.up.image, x * 64, y * 64);
	else if (prog->sprites.s_m.side == 2)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_m.right.image, x * 64, y * 64);
	else if (prog->sprites.s_m.side == 3)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_m.left.image, x * 64, y * 64);
}

void	display2(t_data *prog, int x, int y)
{
	if (prog->map.map[y][x] == '0')
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_0.image, x * 64, y * 64);
	else if (prog->map.map[y][x] == '1')
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_1.image, x * 64, y * 64);
	else if (prog->map.map[y][x] == 'E')
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_e.image, x * 64, y * 64);
	else if (prog->map.map[y][x] == 'C')
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_c.image, x * 64, y * 64);
	else if (prog->map.map[y][x] == 'P')
		display_p(prog, x, y);
	else if (prog->map.map[y][x] == 'F')
		display_f(prog, x, y);
	else if (prog->map.map[y][x] == 'M')
		display_m(prog, x, y);
}

void	display(t_data *prog)
{
	int	x;
	int	y;

	y = 0;
	while (y < prog->map.size.y)
	{
		x = 0;
		while (x < prog->map.size.x)
		{
			display2(prog, x, y);
			x++;
		}
		y++;
	}
}
