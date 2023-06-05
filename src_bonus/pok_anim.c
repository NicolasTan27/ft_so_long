/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pok_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:56:18 by ntan              #+#    #+#             */
/*   Updated: 2022/03/09 16:15:40 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pok_anim_2(t_data *prog, int frame)
{
	if (frame <= 18000)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_3.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 24000)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_4.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 30000)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_5.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 36000)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_f.down.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
}

void	pok_anim(t_data *prog)
{
	static int	frame = 0;

	if (frame <= 6000)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_1.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 12000)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_2.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 18000)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_3.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 24000)
		pok_anim_2(prog, frame);
	else if (frame <= 30000)
		pok_anim_2(prog, frame);
	else if (frame <= 36000)
		pok_anim_2(prog, frame);
	else if (frame > 36000)
		prog->map.pok_anim_state = 0;
	frame += 1;
}
