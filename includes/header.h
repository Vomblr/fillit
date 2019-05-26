/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:23:19 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/26 21:23:42 by Dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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
int		fillit(char *argv);
int		check_pcs_links(char *stock, int j);
int		valid_pcs(char *stock, int j);
int		check_str(char *stock);
void	set_tetri(t_tetri **tmp, char *str);
t_tetri	*stock_tetri(char *str, int num_tetraminos);

#endif
