/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:11:45 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/19 18:23:04 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_piece(t_piece *piece, char **map, int x_index, int y_index)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = piece->coor[i] + x_index;
	y = piece->coor[i + 1] + y_index;
	while (i < 8)
	{
		map[y][x] = '.';
		i += 2;
		x = piece->coor[i] + x_index;
		y = piece->coor[i + 1] + y_index;
	}
}

void	free_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&map[i]);
		i++;
	}
	ft_memdel((void **)&map);
}

char	**create_map(int size)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset(map[i], '.', size);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		count_pieces(t_piece *list)
{
	t_piece	*tmp;
	int		count;

	count = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int		start_size(t_piece *list)
{
	int		size;
	int		blocks;

	size = 2;
	blocks = count_pieces(list) * 4;
	while (blocks > (size * size))
		size++;
	return (size);
}
