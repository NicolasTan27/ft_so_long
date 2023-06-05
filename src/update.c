/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:37:28 by ntan              #+#    #+#             */
/*   Updated: 2022/03/07 13:41:18 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(void *param)
{
	t_data	*prog;

	prog = (t_data *)param;
	if (prog->map.pok_anim_state == 0)
	{
		display(prog);
		if (prog->map.end_status == 1)
		{
			display(prog);
			sleep(1);
			ending(param);
		}
	}
	return (0);
}
