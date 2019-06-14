/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 21:41:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/06/14 21:44:29 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct		s_magic
{
	int			a;
	int			i;
	int			strt;
	char		*mp_tmp;
}					t_magic;
typedef struct		s_tetri
{
	char			c;
	int				x[4];
	struct s_tetri	*next;
}					t_tetri;
void				usage(void);
void				error(void);
int					check_count_pcs_newstr(int fd, char *line);
void				fillit(t_tetri *ttr, int nm_ttr);
int					check_pcs_links(char *stock, int j);
int					valid_pcs(char *stock, int j);
int					check_str(char *stock);
void				set_tetri(t_tetri **tmp, char *str);
t_tetri				*stock_tetri(char *str, int num_tetraminos);
int					ft_decode_tetri(t_tetri *tetrimino, int map_size_prev,
					int map_size_current);
int					ft_rcrsn(t_tetri *tetri, int map_size, char *map, int nm_ttr);
int					ft_tr_ttr(t_tetri *ttr, int mp_sz, char *mp, int strt_pnt, int nm_ttr);
void				ft_print_map(char *mp, int mp_sz);
char				*ft_create_map(int mp_sz);
void				opencheckstock(char *argv, char *stock, int *nm_ttr);
void				freelist(t_tetri *head);
int					check_exclusion(char *s, int i);
int					ft_check_map_3(t_tetri *ttr, char *mp, int strt, 
					int nm_ttr, int i);
#endif
