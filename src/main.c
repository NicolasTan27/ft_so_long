/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:32:31 by ntan              #+#    #+#             */
/*   Updated: 2023/05/14 19:40:33 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	prog;

	if (argc == 2 && check_extent(argv[1]) && parse_map(&prog.map, argv[1]))
	{
		init_sprites_3(&prog);
		prog.mlx = mlx_init();
		if (!prog.mlx)
			ending(&prog);
		mlx_get_screen_size(prog.mlx, &prog.map.max_x, &prog.map.max_y);
		if (prog.map.max_x - 64 <= prog.map.size.x * 64
			|| prog.map.max_y - 64 <= prog.map.size.y * 64)
		{
			ft_putstr_fd("Error\nMap too big\n", 2);
			ending(&prog);
		}
		prog.win = new_window(prog.mlx, prog.map.size.x * 64,
				prog.map.size.y * 64, "So_long");
		init_sprites(&prog);
		mlx_key_hook(prog.win.win, keyboard_input, &prog);
		mlx_hook(prog.win.win, 17, 0, ending, &prog);
		mlx_loop_hook(prog.mlx, update, &prog);
		mlx_loop(prog.mlx);
	}
	else
		printf("kc");
	return (0);
}
