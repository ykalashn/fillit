/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:17:44 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/16 12:45:55 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*reader(char *file)
{
	//	this function reads the file and stores it in 'buf'
	char	buf[546]; //size set for 'buf' can fit max 26 tetrimino pieces
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	ret = read(fd, buf, 546); //opening, reading and closing the file, saving it to 'buf'
	close(fd);
	if (ret < 20 || ret > 545) //first check for file size, if it is too small or big
		return (1);
	buf[ret] = '\0';
	if (validate(buf, ret) == 1) //calling validate function which checks 'buf'
		return (1); //exits and prints error if 'validate' function failed
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
//	solver(list); //calling our solver function
//	free(list); //calling a function that frees everything at the end
	return (0);
}
