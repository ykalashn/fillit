/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:54:25 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/17 17:30:53 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef	struct		s_piece
{
	struct s_piece	*next;
	char			letter;
	int				coor[8];

}					t_piece;

int					validate(char *buf, int size);
t_piece				*create_list(char *buf, int size);
int					start_size(t_piece *list);
void				free_map(char **map, int size);
char				**create_map(int size);

#endif
