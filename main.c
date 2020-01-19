/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:17:44 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/19 16:40:48 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	solver(t_piece *list)
{
	char	**map;
	int		size;

	size = start_size(list);
	map = create_map(size);
	while (!solve_map(map, list, size))
	{
		ft_putendl("fail");
		ft_putnbr(size);
		free_map(map, size);
		size++;
		map = create_map(size);
	}
	print_map(map, size);
	free_map(map, size);
}

t_piece	*reader(char *file)
{
	char	buf[546];
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	ret = read(fd, buf, 546);
	close(fd);
	if (ret < 20 || ret > 545)
		return (NULL);
	buf[ret] = '\0';
	if (validate(buf, ret) == 1)
		return (NULL);
	return (create_list(buf, ret));
}

int		main(int ac, char **av)
{
	t_piece	*list;

	list = NULL;
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (1);
	}
	if ((list = reader(av[1])) == NULL)
	{
		ft_putendl("error");
		return (1);
	}
	solver(list);
	free_list(list);
	return (0);
}
