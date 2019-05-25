/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:23:19 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/23 20:13:35 by mcomet           ###   ########.fr       */
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
	int				y[4];
	struct s_tetri	*next;
}					t_tetri;

void	usage(void);
void	error(void);
int		check_count_pcs_newstr(int fd, char *line);
int		fillit(char *argv);
int		check_pcs_links(char *stock, int j);
int		valid_pcs(char *stock, int j);
int		check_str(char *stock);

#endif
