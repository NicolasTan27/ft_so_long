/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pok_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:56:18 by ntan              #+#    #+#             */
/*   Updated: 2022/03/07 13:32:10 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pok_anim_2(t_data *prog, int frame)
{
	if (frame <= 1800)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_3.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 2400)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_4.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 3000)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_5.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 3600)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.s_f.down.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
}

void	pok_anim(t_data *prog)
{
	static int	frame = 0;

	if (frame <= 600)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_1.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 1200)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_2.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 1800)
		mlx_put_image_to_window(prog->mlx, prog->win.win,
			prog->sprites.pok_anim.img_3.image, prog->map.anim_pos.x * 64,
			prog->map.anim_pos.y * 64);
	else if (frame <= 2400)
		pok_anim_2(prog, frame);
	else if (frame <= 3000)
		pok_anim_2(prog, frame);
	else if (frame <= 3600)
		pok_anim_2(prog, frame);
	else if (frame > 3600)
		prog->map.pok_anim_state = 0;
	frame += 1;
}
