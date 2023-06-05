/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:02:24 by ntan              #+#    #+#             */
/*   Updated: 2022/03/09 16:14:23 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	create_sprite(t_data *prog, void *mlx, char *path)
{
	t_image	sprite;

	sprite.image = mlx_xpm_file_to_image(mlx, path, &sprite.size.x,
			&sprite.size.y);
	if (!sprite.image)
	{
		ft_putstr_fd("Could not find an xpm\n", 1);
		ending(prog);
	}
	sprite.addr = mlx_get_data_addr(sprite.image, &sprite.bits_per_pixel,
			&sprite.line_length, &sprite.endian);
	return (sprite);
}

void	init_sprites_3(t_data *prog)
{
	prog->sprites.s_p.up.image = NULL;
	prog->sprites.s_p.down.image = NULL;
	prog->sprites.s_p.right.image = NULL;
	prog->sprites.s_p.left.image = NULL;
	prog->sprites.s_f.up.image = NULL;
	prog->sprites.s_f.down.image = NULL;
	prog->sprites.s_f.right.image = NULL;
	prog->sprites.s_f.left.image = NULL;
	prog->sprites.s_m.up.image = NULL;
	prog->sprites.s_m.down.image = NULL;
	prog->sprites.s_m.right.image = NULL;
	prog->sprites.s_m.left.image = NULL;
	prog->sprites.s_0.image = NULL;
	prog->sprites.s_1.image = NULL;
	prog->sprites.s_e.image = NULL;
	prog->sprites.s_c.image = NULL;
	prog->sprites.pok_anim.img_1.image = NULL;
	prog->sprites.pok_anim.img_2.image = NULL;
	prog->sprites.pok_anim.img_3.image = NULL;
	prog->sprites.pok_anim.img_4.image = NULL;
	prog->sprites.pok_anim.img_5.image = NULL;
	prog->win.win = NULL;
}

void	init_sprites_2(t_data *prog)
{
	prog->sprites.pok_anim.img_1 = create_sprite(prog, prog->mlx,
			"xpm/pokeball_1.xpm");
	prog->sprites.pok_anim.img_2 = create_sprite(prog, prog->mlx,
			"xpm/pokeball_2.xpm");
	prog->sprites.pok_anim.img_3 = create_sprite(prog, prog->mlx,
			"xpm/pokeball_3.xpm");
	prog->sprites.pok_anim.img_4 = create_sprite(prog, prog->mlx,
			"xpm/pokeball_4.xpm");
	prog->sprites.pok_anim.img_5 = create_sprite(prog, prog->mlx,
			"xpm/pokeball_5.xpm");
	prog->map.pok_anim_state = 0;
	prog->map.end_status = 0;
}

void	init_sprites(t_data *prog)
{
	prog->sprites.s_p.up = create_sprite(prog, prog->mlx, "xpm/P_up.xpm");
	prog->sprites.s_p.down = create_sprite(prog, prog->mlx, "xpm/P_down.xpm");
	prog->sprites.s_p.right = create_sprite(prog, prog->mlx, "xpm/P_right.xpm");
	prog->sprites.s_p.left = create_sprite(prog, prog->mlx, "xpm/P_left.xpm");
	prog->sprites.s_p.side = 0;
	prog->sprites.s_f.up = create_sprite(prog, prog->mlx, "xpm/F_up.xpm");
	prog->sprites.s_f.down = create_sprite(prog, prog->mlx, "xpm/F_down.xpm");
	prog->sprites.s_f.right = create_sprite(prog, prog->mlx, "xpm/F_right.xpm");
	prog->sprites.s_f.left = create_sprite(prog, prog->mlx, "xpm/F_left.xpm");
	prog->sprites.s_f.side = 0;
	prog->sprites.s_m.up = create_sprite(prog, prog->mlx, "xpm/M_up.xpm");
	prog->sprites.s_m.down = create_sprite(prog, prog->mlx, "xpm/M_down.xpm");
	prog->sprites.s_m.right = create_sprite(prog, prog->mlx, "xpm/M_right.xpm");
	prog->sprites.s_m.left = create_sprite(prog, prog->mlx, "xpm/M_left.xpm");
	prog->sprites.s_m.side = 0;
	prog->sprites.s_0 = create_sprite(prog, prog->mlx, "xpm/s_0.xpm");
	prog->sprites.s_1 = create_sprite(prog, prog->mlx, "xpm/s_1.xpm");
	prog->sprites.s_e = create_sprite(prog, prog->mlx, "xpm/s_E.xpm");
	prog->sprites.s_c = create_sprite(prog, prog->mlx, "xpm/pokeball_1.xpm");
	init_sprites_2(prog);
}
