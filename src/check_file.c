/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:39:56 by ntan              #+#    #+#             */
/*   Updated: 2022/03/09 16:20:41 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extent(char *av)
{
	int	i;

	i = ft_strlen(av) - 1;
	if (av[i] != 'r' || av[i - 1] != 'e'
		|| av[i - 2] != 'b' || av[i - 3] != '.')
	{
		ft_putstr_fd("Error\nNot a .ber file\n", 2);
		return (0);
	}
	return (1);
}
