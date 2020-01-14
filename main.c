/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:17:44 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/14 17:44:47 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	reader(char *file)
{
	char	buf[546];
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	ret = read(fd, buf, 546);
	close(fd);
	if (ret < 20 || ret > 545)
		return (1);
	buf[ret] = '\0';
	if (validate(buf, ret) == 1)
		return (1);
	ft_putendl("ok");
	return (0);
}

int		main(int ac, char **av)
{
//	t_tetri	*list; //start of our linked list, that we will pass to other functions

//	list = NULL;
	if (ac != 2) //checking if we have a file to read or not
	{
		ft_putendl("usage: ./fillit source_file"); //printing instructions
		return (1);
	}
	if (reader(av[1]) == 1) //calling our reader and error check function
	{
		ft_putendl("error"); //printing error message and exiting
		return (1);
	}
//	solver function(list); //calling our solver function
//	free function(list); //calling a function that frees everything at the end
	return (0);
}
