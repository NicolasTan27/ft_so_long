/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:01:35 by ntan              #+#    #+#             */
/*   Updated: 2022/07/23 14:57:14 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_up(t_data *prog)
{
	prog->sprites.s_f.side = prog->sprites.s_p.side;
	prog->sprites.s_p.side = 1;
	if (move_up(&prog->map))
	{
		prog->map.moves += 1;
	}
}

void	input_down(t_data *prog)
{
	prog->sprites.s_f.side = prog->sprites.s_p.side;
	prog->sprites.s_p.side = 0;
	if (move_down(&prog->map))
	{
		prog->map.moves += 1;
	}
}

void	input_left(t_data *prog)
{
	prog->sprites.s_f.side = prog->sprites.s_p.side;
	prog->sprites.s_p.side = 3;
	if (move_left(&prog->map))
	{
		prog->map.moves += 1;
	}
}

void	input_right(t_data *prog)
{
	prog->sprites.s_f.side = prog->sprites.s_p.side;
	prog->sprites.s_p.side = 2;
	if (move_right(&prog->map))
	{
		prog->map.moves += 1;
	}
}

int	keyboard_input(int key, void *param)
{
	t_data	*prog;

	prog = (t_data *)param;
	if (key == 65307)
		ending(prog);
	else if (key == 119 || key == 13)
		input_up(prog);
	else if (key == 115 || key == 1)
		input_down(prog);
	else if (key == 97 || key == 0)
		input_left(prog);
	else if (key == 100 || key == 2)
		input_right(prog);
	if (prog->map.map[prog->map.p_pos.y][prog->map.p_pos.x] == 'E')
		prog->map.end_status = 1;
	ft_putstr_fd("Moves : ", 1);
	ft_putnbr_fd(prog->map.moves, 1);
	ft_putstr_fd("\n", 1);
	printf("%d\n", key);
	return (0);
}
