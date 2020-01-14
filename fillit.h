/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:54:25 by kpesonen          #+#    #+#             */
/*   Updated: 2020/01/14 17:08:58 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef	struct		s_tetri
{
	char			letter;
	char			**piece;
	struct s_tetri	*next; 

}					t_tetri;

int	validate(char *buf, int size);

#endif
