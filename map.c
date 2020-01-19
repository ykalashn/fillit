/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:11:45 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/19 14:36:30 by ykalashn         ###   ########.fr       */
=======
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:11:45 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/17 17:23:40 by kpesonen         ###   ########.fr       */
>>>>>>> kim
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(char **map, int size)
{
<<<<<<< HEAD
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&map[i]);
		i++; 
	}
	ft_memdel((void **)&map);
=======


>>>>>>> kim
}

char	**create_map(int size)
{
<<<<<<< HEAD
	int i;
	char **map;

	i = 0;
	map = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset(map[i], '.', size);
		i++;	
	}
	map[i] = '\0';
	return (map);
=======


>>>>>>> kim
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
