/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:17:44 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/19 15:12:11 by ykalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	free_list(t_piece *list)
{
	t_piece	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	print_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putendl(map[i]);
		i++;
	}
}

/*void	printer(t_piece *list)
{
	t_piece *tmp;
	int i;

	tmp = list;
	while (tmp != NULL)
	{
		i = 0;
		while (i < 8)
		{
			ft_putnbr(tmp->coor[i]);
			i++;
		}
		tmp = tmp->next;
		ft_putchar('\n');	
	}
}*/

void	solver(t_piece *list)
{
	char	**map;
	int		size;

	size = start_size(list);
	map = create_map(size);
	while (!solve_map(map, list, size))
	{
		free_map(map, size);
		size++;
		map = create_map(size);
	}
	print_map(map, size);
	free_map(map, size);
}

t_piece	*reader(char *file)
{
	//	this function reads the file and stores it in 'buf'
	char	buf[546]; //size set for 'buf' can fit max 26 tetrimino pieces
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	ret = read(fd, buf, 546); //opening, reading and closing the file, saving it to 'buf'
	close(fd);
	if (ret < 20 || ret > 545) //first check for file size, if it is too small or big
		return (NULL);
	buf[ret] = '\0';
	if (validate(buf, ret) == 1) //calling validate function which checks 'buf'
		return (NULL); //exits and prints error if 'validate' function failed
	return (create_list(buf, ret));
	//calling 'create_list' which creates our linked list and returns it to 'main'
}

int		main(int ac, char **av)
{
	t_piece	*list; //declaring our linked list just like any variable

	list = NULL; //setting value of our linked list to null for now
	if (ac != 2) //checking if we have a file to read or not
	{
		ft_putendl("usage: ./fillit source_file"); //printing instructions
		return (1);
	}
	if ((list = reader(av[1])) == NULL) //calling our reader and error check function
	// and sets return value from 'reader' function as our linked list values
	{
		ft_putendl("error"); //printing error message and exiting if there was an error
		return (1);
	}
	solver(list); //calling our solver function
//	printer(list);
	free_list(list);
//	while (1);
	return (0);
}
