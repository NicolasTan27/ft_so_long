/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:00:18 by ntan              #+#    #+#             */
/*   Updated: 2022/03/17 13:26:37 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_2(t_data *prog)
{
	if (prog->sprites.s_f.right.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_f.right.image);
	if (prog->sprites.s_f.left.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_f.left.image);
	if (prog->sprites.s_m.up.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_m.up.image);
	if (prog->sprites.s_m.down.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_m.down.image);
	if (prog->sprites.s_m.right.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_m.right.image);
	if (prog->sprites.s_m.left.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_m.left.image);
	if (prog->sprites.s_0.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_0.image);
	if (prog->sprites.s_1.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_1.image);
	if (prog->sprites.s_e.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_e.image);
	if (prog->sprites.s_c.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_c.image);
}

void	destroy(t_data *prog)
{
	if (prog->sprites.pok_anim.img_1.image)
		mlx_destroy_image(prog->mlx, prog->sprites.pok_anim.img_1.image);
	if (prog->sprites.pok_anim.img_2.image)
		mlx_destroy_image(prog->mlx, prog->sprites.pok_anim.img_2.image);
	if (prog->sprites.pok_anim.img_3.image)
		mlx_destroy_image(prog->mlx, prog->sprites.pok_anim.img_3.image);
	if (prog->sprites.pok_anim.img_4.image)
		mlx_destroy_image(prog->mlx, prog->sprites.pok_anim.img_4.image);
	if (prog->sprites.pok_anim.img_5.image)
		mlx_destroy_image(prog->mlx, prog->sprites.pok_anim.img_5.image);
	if (prog->sprites.s_p.up.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_p.up.image);
	if (prog->sprites.s_p.down.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_p.down.image);
	if (prog->sprites.s_p.right.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_p.right.image);
	if (prog->sprites.s_p.left.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_p.left.image);
	if (prog->sprites.s_f.up.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_f.up.image);
	if (prog->sprites.s_f.down.image)
		mlx_destroy_image(prog->mlx, prog->sprites.s_f.down.image);
	destroy_2(prog);
}

void	free_map(t_data *prog)
{
	int	i;

	i = 0;
	while (i < prog->map.size.y)
		free(prog->map.map[i++]);
	free(prog->map.map);
}

int	ending(t_data *prog)
{
	if (&prog->sprites)
		destroy(prog);
	if (prog->map.map)
		free_map(prog);
	if (prog->win.win)
		mlx_destroy_window(prog->mlx, prog->win.win);
	if (prog->mlx)
	{
		mlx_destroy_display(prog->mlx);
		free(prog->mlx);
	}
	exit(0);
	return (1);
}
