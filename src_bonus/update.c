/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:37:28 by ntan              #+#    #+#             */
/*   Updated: 2022/03/09 13:24:11 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_data *prog)
{
	char	*str;

	str = ft_itoa(prog->map.moves);
	mlx_string_put(prog->mlx, prog->win.win, 0,
		prog->map.size.y * 64, 15921152, "MOVES :");
	mlx_string_put(prog->mlx, prog->win.win, 64,
		prog->map.size.y * 64, 15921152, str);
	free(str);
}

int	update(void *param)
{
	t_data	*prog;

	prog = (t_data *)param;
	if (prog->map.pok_anim_state == 0)
	{
		display(prog);
		print_moves(prog);
		if (prog->map.end_status == 1)
		{
			display(prog);
			ending(param);
		}
	}
	if (prog->map.pok_anim_state == 1)
		pok_anim(prog);
	return (0);
}
