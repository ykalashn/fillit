/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:27:32 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/16 14:49:41 by ykalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_piece	*create_piece(char *buf, char letter)
{
	t_piece	*new;

	if (!(new = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
//	new->coor = figure this out today;
	new->letter = letter;
	new->next = NULL;
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
