/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:12:32 by ntan              #+#    #+#             */
/*   Updated: 2022/03/07 14:45:44 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnl/get_next_line.h"

int	is_only_1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_inside(t_map *map, int E, int P)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->size.y)
	{
		x = -1;
		while (++x < map->size.x)
		{
			if (map->map[y][x] == 'E')
				E++;
			else if (map->map[y][x] == 'C')
				map->c++;
			else if (map->map[y][x] == 'P')
				P++;
			else if (map->map[y][x] == 'M')
				map->m++;
			else if (map->map[y][x] != '1' && map->map[y][x] != '0')
				return (0);
		}
		y++;
	}
	if (E == 0 || map->c == 0 || P == 0 || P > 1 || map->m > 1)
		return (0);
	return (1);
}

int	check_outside(t_map map)
{
	int	y;

	y = 0;
	while (y < map.size.y)
	{
		if ((y == 0 || y == map.size.y - 1) && is_only_1(map.map[y]) == 0)
			return (0);
		if (ft_strlen(map.map[y]) != map.size.x)
			return (0);
		if (map.map[y][0] != '1'
			|| map.map[y][ft_strlen(map.map[y]) - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_map(t_map *map)
{
	int	e;
	int	p;

	e = 0;
	p = 0;
	map->m = 0;
	map->c = 0;
	if (check_outside(*map) == 0)
	{
		ft_putstr_fd("Incorrect map exterior\n", 2);
		return (0);
	}
	if (check_inside(map, e, p) == 0)
	{
		ft_putstr_fd("Incorrect map exterior\n", 2);
		return (0);
	}
	map->c = 0;
	map->moves = 0;
	return (1);
}
