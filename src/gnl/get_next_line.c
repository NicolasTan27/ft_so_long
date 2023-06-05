/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:45:37 by ntan              #+#    #+#             */
/*   Updated: 2022/03/09 16:55:26 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*index_next_word(char *str)
{
	static int	count;
	int			actual;
	int			i;

	i = 0;
	actual = 0;
	while (str[i] && count != actual)
	{
		if (str[i] == '\n')
			actual++;
		i++;
	}
	count++;
	return (&str[i]);
}

char	*clean_output(char *str)
{
	char		*res;
	static int	count;

	if (count++ <= is_endofline(str))
	{
		res = index_next_word(str);
		res = remove_bn(res);
		if (res == NULL)
		{
			if (str)
				free(str);
			return (NULL);
		}
		return (res);
	}
	else
	{
		if (str)
			free(str);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char		*str = "";
	static char		buf[BUFFER_SIZE + 1] = "";
	int				ret;

	if (fd < 0 || fd > 999 || BUFFER_SIZE <= 0)
		return (0);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (str == NULL)
			return (NULL);
		if (is_endofline(buf) > 0)
			break ;
	}
	return (clean_output(str));
}
