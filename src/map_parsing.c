/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:39:42 by ntan              #+#    #+#             */
/*   Updated: 2022/03/17 13:53:03 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnl/get_next_line.h"

t_map	get_player_pos(t_map map)
{
	int	x;
	int	y;

	y = 0;
	map.max_c = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			if (map.map[y][x] == 'P')
			{
				map.p_pos.x = x;
				map.p_pos.y = y;
			}
			else if (map.map[y][x] == 'C')
				map.max_c += 1;
			x++;
		}
		y++;
	}
	return (map);
}

void	replace_bn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\r')
		{
			str[i] = '\0';
			return ;
		}
		i++;
	}
}

void	ft_error(void)
{
	ft_putstr_fd("Error\nEmpty Map or Map too big\n", 2);
	exit(1);
}

t_map	get_map(int fd)
{
	t_map	map;
	int		i;

	i = 0;
	map.map = malloc(sizeof(char) * MAX_MAP);
	if (map.map == NULL)
		return (map);
	while (1)
	{
		map.map[i] = get_next_line(fd);
		if (map.map[i] == NULL)
		{
			if (i == 0 || i >= MAX_MAP)
			{
				free(map.map);
				ft_error();
			}
			break ;
		}
		replace_bn(map.map[i]);
		i++;
	}
	map.size.x = ft_strlen(map.map[0]);
	map.size.y = i;
	return (map);
}

int	parse_map(t_map *map, char *path)
{
	int	fd;
	int	i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nIncorrect map file\n", 2);
		return (0);
	}
	*map = get_map(fd);
	if (map->map == NULL)
		return (0);
	close(fd);
	if (check_map(map) == 0)
	{
		i = 0;
		while (i < map->size.y)
			free(map->map[i++]);
		free(map->map);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	*map = get_player_pos(*map);
	*map = get_mechant_pos(*map);
	return (1);
}
