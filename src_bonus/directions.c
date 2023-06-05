/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:54:04 by ntan              #+#    #+#             */
/*   Updated: 2022/03/07 15:16:13 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	follow(t_map *map)
{
	static int	i = 0;

	if (i == 0)
	{
		map->f_pos.x = 0;
		map->f_pos.y = 0;
	}
	if (map->map[map->f_pos.y][map->f_pos.x] != 'P' && i++ > 0)
		map->map[map->f_pos.y][map->f_pos.x] = '0';
	map->f_pos.x = map->p_pos.x;
	map->f_pos.y = map->p_pos.y;
	map->map[map->f_pos.y][map->f_pos.x] = 'F';
	return (1);
}

int	move_up(t_map *map)
{
	if (map->map[map->p_pos.y - 1][map->p_pos.x] != '1'
		&& map->map[map->p_pos.y - 1][map->p_pos.x] != 'E')
	{
		if (map->map[map->p_pos.y - 1][map->p_pos.x] == 'C')
			map->c++;
		if (map->map[map->p_pos.y - 1][map->p_pos.x] == 'C' && map->c == 1)
		{
			map->pok_anim_state = 1;
			map->anim_pos.x = map->p_pos.x;
			map->anim_pos.y = map->p_pos.y - 1;
		}
		map->map[map->p_pos.y - 1][map->p_pos.x] = 'P';
		map->map[map->p_pos.y][map->p_pos.x] = '0';
		if (map->c >= 1)
			follow(map);
		map->p_pos.y--;
		return (1);
	}
	else if (map->map[map->p_pos.y - 1][map->p_pos.x] == 'E'
		&& map->c == map->max_c)
		map->end_status = 1;
	return (0);
}

int	move_down(t_map *map)
{
	if (map->map[map->p_pos.y + 1][map->p_pos.x] != '1'
		&& map->map[map->p_pos.y + 1][map->p_pos.x] != 'E')
	{
		if (map->map[map->p_pos.y + 1][map->p_pos.x] == 'C')
			map->c++;
		if (map->map[map->p_pos.y + 1][map->p_pos.x] == 'C' && map->c == 1)
		{
			map->pok_anim_state = 1;
			map->anim_pos.x = map->p_pos.x;
			map->anim_pos.y = map->p_pos.y + 1;
		}
		map->map[map->p_pos.y + 1][map->p_pos.x] = 'P';
		map->map[map->p_pos.y][map->p_pos.x] = '0';
		if (map->c >= 1)
			follow(map);
		map->p_pos.y++;
		return (1);
	}
	else if (map->map[map->p_pos.y + 1][map->p_pos.x] == 'E' &&
	map->c == map->max_c)
		map->end_status = 1;
	return (0);
}

int	move_left(t_map *map)
{
	if (map->map[map->p_pos.y][map->p_pos.x - 1] != '1'
		&& map->map[map->p_pos.y][map->p_pos.x - 1] != 'E')
	{
		if (map->map[map->p_pos.y][map->p_pos.x - 1] == 'C')
			map->c++;
		if (map->map[map->p_pos.y][map->p_pos.x - 1] == 'C' && map->c == 1)
		{
			map->pok_anim_state = 1;
			map->anim_pos.x = map->p_pos.x - 1;
			map->anim_pos.y = map->p_pos.y;
		}
		map->map[map->p_pos.y][map->p_pos.x - 1] = 'P';
		map->map[map->p_pos.y][map->p_pos.x] = '0';
		if (map->c >= 1)
			follow(map);
		map->p_pos.x--;
		return (1);
	}
	else if (map->map[map->p_pos.y][map->p_pos.x - 1] == 'E' &&
	map->c == map->max_c)
		map->end_status = 1;
	return (0);
}

int	move_right(t_map *map)
{
	if (map->map[map->p_pos.y][map->p_pos.x + 1] != '1' &&
		map->map[map->p_pos.y][map->p_pos.x + 1] != 'E')
	{
		if (map->map[map->p_pos.y][map->p_pos.x + 1] == 'C')
			map->c++;
		if (map->map[map->p_pos.y][map->p_pos.x + 1] == 'C' && map->c == 1)
		{
			map->pok_anim_state = 1;
			map->anim_pos.x = map->p_pos.x + 1;
			map->anim_pos.y = map->p_pos.y;
		}
		map->map[map->p_pos.y][map->p_pos.x + 1] = 'P';
		map->map[map->p_pos.y][map->p_pos.x] = '0';
		if (map->c >= 1)
			follow(map);
		map->p_pos.x++;
		return (1);
	}
	else if (map->map[map->p_pos.y][map->p_pos.x + 1] == 'E' &&
	map->c == map->max_c)
		map->end_status = 1;
	return (0);
}
