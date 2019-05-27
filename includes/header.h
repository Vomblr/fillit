/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:23:19 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/27 00:47:05 by Dmitry           ###   ########.fr       */
/*   Updated: 2019/05/26 20:20:23 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_tetri
{
	char			c;
	int				x[4];
	//int				y[4];
	struct s_tetri	*next;
}					t_tetri;

void	usage(void);
void	error(void);
int		check_count_pcs_newstr(int fd, char *line);
void	fillit(char *argv);
int		check_pcs_links(char *stock, int j);
int		valid_pcs(char *stock, int j);
int		check_str(char *stock);
void	set_tetri(t_tetri **tmp, char *str);
t_tetri	*stock_tetri(char *str, int num_tetraminos);
int		ft_check_map_for_1_tetr(t_tetri tetrimino, int num_tetraminos);
int		ft_check_map_for_2_tetr(t_tetri tetrimino, int num_tetraminos);

#endif
