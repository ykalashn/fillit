/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:24:26 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/19 18:30:17 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_piece(t_piece *piece, char **map, int x_index, int y_index)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = piece->coor[i] + x_index;
	y = piece->coor[i + 1] + y_index;
	while (i < 8)
	{
		map[y][x] = piece->letter;
		i += 2;
		x = piece->coor[i] + x_index;
		y = piece->coor[i + 1] + y_index;
	}
}

int		check_overlap(char **map, int *coor, int x_index, int y_index)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = coor[i] + x_index;
	y = coor[i + 1] + y_index;
	while (i < 8)
	{
		if (map[y][x] != '.')
			return (1);
		i += 2;
		x = coor[i] + x_index;
		y = coor[i + 1] + y_index;
	}
	return (0);
}

int		hi_coor(int *arr, char xy)
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
	while (!inside_map(y, piece->coor, size, 'y'))
	{
		while (!inside_map(x, piece->coor, size, 'x'))
		{
			if (!check_overlap(map, piece->coor, x, y))
			{
				place_piece(piece, map, x, y);
				if (solve_map(map, piece->next, size))
					return (1);
				remove_piece(piece, map, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
