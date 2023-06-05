/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_mechant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:18:25 by ntan              #+#    #+#             */
/*   Updated: 2022/03/07 13:32:01 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	get_mechant_pos(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			if (map.map[y][x] == 'M')
			{
				map.m_pos.x = x;
				map.m_pos.y = y;
			}
			x++;
		}
		y++;
	}
	return (map);
}

int	c(t_map *map, int x, int y)
{
	if (map->map[y][x] != '1' &&
		map->map[y][x] != 'E' &&
		map->map[y][x] != 'C' &&
		map->map[y][x] != 'F' &&
		map->map[y][x] != 'P')
		return (1);
	else
		return (0);
}

void	le_mechant_2(t_map *map)
{
	if (map->p_pos.y < map->m_pos.y
		&& c(map, map->m_pos.x, map->m_pos.y - 1))
	{
		map->map[map->m_pos.y][map->m_pos.x] = '0';
		map->map[map->m_pos.y - 1][map->m_pos.x] = 'M';
		map->m_pos.y--;
	}
	else if (map->p_pos.y > map->m_pos.y
		&& c(map, map->m_pos.x, map->m_pos.y + 1))
	{
		map->map[map->m_pos.y][map->m_pos.x] = '0';
		map->map[map->m_pos.y + 1][map->m_pos.x] = 'M';
		map->m_pos.y++;
	}
}

void	le_mechant(t_map *map)
{
	if (map->p_pos.x < map->m_pos.x
		&& c(map, map->m_pos.x - 1, map->m_pos.y))
	{
		map->map[map->m_pos.y][map->m_pos.x] = '0';
		map->map[map->m_pos.y][map->m_pos.x - 1] = 'M';
		map->m_pos.x--;
	}
	else if (map->p_pos.x > map->m_pos.x
		&& c(map, map->m_pos.x + 1, map->m_pos.y))
	{
		map->map[map->m_pos.y][map->m_pos.x] = '0';
		map->map[map->m_pos.y][map->m_pos.x + 1] = 'M';
		map->m_pos.x++;
	}
	else
		le_mechant_2(map);
}

void	check_lose(t_map *map)
{
	if ((map->p_pos.x == map->m_pos.x || map->f_pos.x == map->m_pos.x)
		&& (map->p_pos.y == map->m_pos.y - 1
			|| map->p_pos.y == map->m_pos.y + 1
			|| map->m_pos.y == map->f_pos.y - 1
			|| map->m_pos.y == map->f_pos.y + 1))
		map->end_status = 1;
	else if ((map->p_pos.y == map->m_pos.y || map->f_pos.y == map->m_pos.y)
		&& (map->p_pos.x == map->m_pos.x - 1
			|| map->p_pos.x == map->m_pos.x + 1
			|| map->m_pos.x == map->f_pos.x + 1
			|| map->m_pos.x == map->f_pos.x - 1))
		map->end_status = 1;
}
