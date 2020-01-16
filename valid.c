/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:36:28 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/14 19:14:41 by kpesonen         ###   ########.fr       */
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
		//checking the text for only allowed characters
		if (buf[i] == '\n' && ((i + 1) % 5 != 0))
			return (1);
		//checking that each row is 4 characters long
		if (buf[i] == '#')
			count++;
		//counting the number of #'s
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
		//checking for connections to left
		if (buf[i] == '#' && ((i + 1 <= 18) && buf[i + 1] == '#'))
			count++;
		//checking for connections to right
		if (buf[i] == '#' && ((i - 5 >= 0) && buf[i - 5] == '#'))
			count++;
		//checking for connections to up
		if (buf[i] == '#' && ((i + 5 <= 18) && buf[i + 5] == '#'))
			count++;
		//checking for connections to down
		i++;
	}
	return (count);
}

int	validate(char *buf, int size)
{
	int	i;

	i = 0;
	while (i <= size) //reading what is saved into 'buf'
	{
		if (check_characters(buf + i) != 4) //checking that there is 4 #'s
			return (1);
		if (check_connections(buf + i) != 6 && check_connections(buf + i) != 8)
			return (1);
		//checking that each tetrimino has 6 or 8 connecions and is a correct piece
		i += 21;
		//increasing index by 21, which is the size of each piece in text with newlines
	}
	return (0);
}
