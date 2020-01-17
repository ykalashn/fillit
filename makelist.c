/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:27:32 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/16 17:23:06 by ykalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		shift(int *arr)
{
	int		min_x;
	int		min_y;
	int		i;
	
	i = 0;
	min_x = arr[i];
	while (i < 8)
	{
		if (arr[i] < min_x)
			min_x = arr[i];
		i += 2;
	}
	i = 1;
	min_y = arr[i];
	while (i < 8)
	{
		if (arr[i] < min_y)
			min_y = arr[i];
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		arr[i] = arr[i] - min_x;
		i++;
		arr[i] = arr[i] - min_y;
		i++;
	}
}

/*int		*get_coords(char *buf)
{
	int		coor[8];
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 1;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			coor[x] = i % 5;
			coor[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	return (shift(coor));
}*/

t_piece	*create_piece(char *buf, char letter)
{
	t_piece	*new;
	int		i;
	int		x;
	int		y;

	if (!(new = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	i = 0;
	x = 0;
	y = 1;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			new->coor[x] = i % 5;
			new->coor[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	new->letter = letter;
	new->next = NULL;
	shift(new->coor);
	return (new);
}

t_piece	*create_list(char *buf, int size)
{
	int		i;
	char	letter;
	t_piece	*head;
	t_piece	*current;

	i = 0;
	letter = 'A';
	while (i < size)
	{
		if (letter == 'A')
		{
			head = create_piece(buf + i, letter);
			current = head;
		}
		else
		{
			current->next = create_piece(buf + i, letter);
			current = current->next;
		}
		letter++;
		i += 21;
	}
	current->next = NULL;
	return (head);
}
