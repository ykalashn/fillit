/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:27:32 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/16 12:15:46 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_tetri	*create_piece(char *buf, char letter)
{
	t_tetri	*new;

	if (!(new = (t_tetri*)malloc(sizeof(t_piece))))
		return (NULL);

	new->next = NULL;
	return (new);
}

t_tetri	*create_list(char *buf, int size)
{
	int		i;
	char	letter;

	i = 0;
	letter = 'A';
	while (i < size)
	{

	}
}
