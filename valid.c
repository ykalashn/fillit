/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:36:28 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/14 17:32:37 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_characters(char *buf)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] != '\0' && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (1);
		if (buf[i] == '\n' && ((i + 1) % 5 != 0))
			return (1);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (buf[i] == '\0' || buf[i] != '\n')
		return (1);
	return (count);
}

int	check_connections(char *buf)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#' && ((i - 1 >= 0) && buf[i - 1] == '#'))
			count++;
		if (buf[i] == '#' && ((i + 1 <= 18) && buf[i + 1] == '#'))
			count++;
		if (buf[i] == '#' && ((i - 5 >= 0) && buf[i - 5] == '#'))
			count++;
		if (buf[i] == '#' && ((i + 5 <= 18) && buf[i + 5] == '#'))
			count++;
		i++;
	}
	return (count);
}

int	validate(char *buf, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		if (check_characters(buf + i) != 4)
			return (1);
		if (check_connections(buf + i) != 6 && check_connections(buf + i) != 8)
			return (1);
		i += 21;
	}
	return (0);
}
