/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:54:25 by kpesonen          #+#    #+#             */
/*   Updated: 2019/12/30 16:07:41 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"

typedef	struct		s_piece
{
	int				x;
	struct s_piece	*next; 

}					t_piece;

#endif
