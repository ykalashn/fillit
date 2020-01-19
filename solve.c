/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:24:26 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/19 15:12:29 by ykalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_piece(int *arr, char **map, char letter)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 8)
	{
		x = arr[i];
		y = arr[i + 1];
		map[y][x] = letter;
		i += 2;
	}
}

int		check_overlap(char **map, int *coor)
{
	int		i;
	int		count;

	i = 0;

	count = 4;
	while (count > 0)
	{
		if (map[coor[i + 1]][coor[i]] != '.')
			return (1);
		i += 2;
		count--;
	}
	return (0);
}

int		hi_coor(int	*arr, char xy)
{
	int		hi;
	int		i;	

	if (xy == 'x')
		i = 0;
	else
		i = 1;
	hi = arr[i];
	while (i < 8)
	{
		if (arr[i] > hi)
			hi = arr[i];
		i += 2;
	}
	return (hi);
}

int		inside_map(int index, int *arr, int size, char xy)
{
	int		hi;

	if (xy == 'x')
	{
		hi = hi_coor(arr, 'x');
		if (index + hi < size)
			return (0);
	}
	else
	{
		hi = hi_coor(arr, 'y');
		if (index + hi < size)
			return (0);
	}	
	return (1);
}

int		solve_map(char **map, t_piece *piece, int size)
{
	int		x;
	int		y;

	if (!piece)
		return (1);
	x = 0;
	y = 0;
	while (y < size && !inside_map(y, piece->coor, size, 'y'))
	{
		while (x < size && !inside_map(x, piece->coor, size, 'x'))
		{
			if (!check_overlap(map, piece->coor))
			{
				place_piece(piece->coor, map, piece->letter);
				if (!solve_map(map, piece->next, size))
					return (1);
				else
					place_piece(piece->coor, map, '.');
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
