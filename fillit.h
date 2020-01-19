/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:54:25 by kpesonen          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/16 17:04:31 by ykalashn         ###   ########.fr       */
=======
/*   Updated: 2020/01/19 14:44:54 by kpesonen         ###   ########.fr       */
>>>>>>> kim
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

<<<<<<< HEAD
int	validate(char *buf, int size);
t_piece	*create_list(char *buf, int size);
=======
int					validate(char *buf, int size);
t_piece				*create_list(char *buf, int size);
int					start_size(t_piece *list);
void				free_map(char **map, int size);
char				**create_map(int size);
int					solve_map(char **map, t_piece *piece, int size);
>>>>>>> kim

#endif
