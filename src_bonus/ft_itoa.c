/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:29:04 by ntan              #+#    #+#             */
/*   Updated: 2022/03/09 16:13:03 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*rev_char(char *str)
{
	char	*rev;
	int		i;
	int		size;

	i = 0;
	size = 0;
	size = ft_strlen(str) - 1;
	rev = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (rev == NULL)
		return (NULL);
	while (str[i])
	{
		rev[i] = str[size - i];
		i++;
	}
	rev[i] = '\0';
	return (rev);
}

char	*ft_itoa(int n)
{
	char			res[200];
	unsigned int	quotient;
	int				reste;
	int				i;

	i = 0;
	if (n < 0)
		quotient = -n;
	else
		quotient = n;
	while (1)
	{
		reste = quotient % 10;
		quotient = quotient / 10;
		res[i++] = (reste + '0');
		if (quotient == 0)
		{
			if (n < 0)
				res[i++] = '-';
			res[i] = '\0';
			break ;
		}
	}
	return (rev_char(res));
}

void	ft_putnbr_fd(int n, int fd)
{
	char			res[200];
	unsigned int	quotient;
	unsigned int	reste;
	int				i;

	i = 0;
	if (n < 0)
		quotient = -n;
	else
		quotient = n;
	while (quotient != 0)
	{
		reste = quotient % 10;
		quotient = quotient / 10;
		res[i++] = reste + '0';
	}
	if (n < 0)
		res[i++] = '-';
	if (n == 0)
		res[i++] = '0';
	while (i-- > 0)
		write(fd, &res[i], 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
