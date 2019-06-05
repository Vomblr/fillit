/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:33:39 by klekisha          #+#    #+#             */
/*   Updated: 2019/06/05 14:59:54 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		check_count_pcs_newstr(int fd, char *str)
{
	int		i;
	int		ret;
	char	buff[2];
	int		j;

	i = 1;
	if ((fd < 0))
		usage();
	j = 0;
	while ((ret = read(fd, buff, 1)))
	{
		buff[ret] = '\0';
		if (buff[0] != '.' && buff[0] != '#' && buff[0] != '\n' && buff[0] != '\0')
			error();
		str[j] = buff[0];
		j++;
		if (buff[0] == '\n')
			i++;
	}
	str[j] = '\0';
	if ((i % 5) == 0 && (i = (i / 5)) <= 26)
		return (i);
	else
		error();
	return (0);
}

int check_pcs_links(char *stock, int j)
{
	int	link;
	int i;

	i = 0;
	link = 0;
	while (i + j < 20 + j)
	{
		if (stock[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && stock[i + j + 1] == '#')
				link++;
			if ((i + j - 1) >= (0 + j) && stock[i + j - 1] == '#')
				link++;
			if ((i + j + 5) < (20 + j) && stock[i + j + 5] == '#')
				link++;
			if ((i + j - 5) >= (0 + j) && stock[i + j - 5] == '#')
				link++;
		}
		i++;
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}

int		valid_pcs(char *stock, int j)
{
	int dash;
	int dot;
	int newline;
	int i;

	i = 0;
	dash = 0;
	dot = 0;
	newline = 0;
	while ((i + j) < (20 + j) && stock[i + j] != '\0')
	{
		if (stock[i + j] == '#')
			dash++;
		if (stock[i + j] == '.')
			dot++;
		if (stock[i + j] == '\n')
			newline++;
		i++;
	}
	if (dash == 4 && dot == 12 && newline == 4)
		return (1);
	return (0);
}

int		check_str(char *stock)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (stock[i + j] != '\0')
	{
		if (!(check_pcs_links(stock, j) && valid_pcs(stock, j)))
			return (0);
		i += 19;
		if ((stock[i + j]) == '\n' && stock[i + j + 1] == '\0')
			break ;
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\n'
			&& (stock[i + j + 2] == '.' || stock[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}

void		set_tetri(t_tetri **tmp, char *str)
{
	int	i;
	int	j;
	int z;

	i = 0;
	j = 0;
	z = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			if ((str[i + 1] == '#' && str[i + 4] == '#' && str[i + 5] == '#') ||
					(str[i + 4] == '#' && str[i + 5] == '#' && str[i + 6] == '#') ||
					(str[i + 5] == '#' && str[i + 9] == '#' && str[i + 10] == '#') ||
					(str[i + 4] == '#' && str[i + 5] == '#' && str[i + 10] == '#') ||
					(str[i + 4] == '#' && str[i + 5] == '#' && str[i + 9] == '#'))
				z = 1;
			else if (str[i + 3] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
				z = 2;
			(*tmp)->x[j] = z;
			j++;
			z++;
		}
		if (z && str[i] != '#' && str[i] != '\n')
			z++;
		i++;
	}
}

t_tetri		*stock_tetri(char *str, int num_tetraminos)
{
	int		plus21;
	char 	c;
	t_tetri	*tmp;
	t_tetri	*stock;

	plus21 = 0;
	c = 'A';
	if (!(stock = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	tmp = stock;
	while (num_tetraminos > 0)
	{
		tmp->c = c;
		set_tetri(&tmp, ft_strsub(str, 0 + plus21, 20));
		if (!(tmp->next = (t_tetri*)malloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
		num_tetraminos--;
		c++;
		plus21 += 21;
	}
	tmp->next = NULL;
	return (stock);
}

// /* 2 functions below check a case then map size 2 or 3 enough for tetraminos set */

// int		ft_check_map_for_1_tetr(t_tetri tetrimino)
// {
// 	if (tetrimino.x[3] == 4 || tetrimino.x[3] == 12)
// 		return (4);
// 	if (tetrimino.x[0] == 0 && tetrimino.x[1] == 1 && tetrimino.x[2] == 4 && tetrimino.x[3] == 5)
// 		return (2);
// 	return (3);
// }

// int		ft_check_map_for_2_tetr(t_tetri tetrimino)
// {
// 	t_tetri		first_tetrimino;
// 	t_tetri		second_tetrimino;

// 	first_tetrimino = tetrimino;
// 	second_tetrimino = *(tetrimino.next);
// 	if ((ft_check_map_for_1_tetr(first_tetrimino)) == 4 || (ft_check_map_for_1_tetr(second_tetrimino)) == 4)
// 		return (4);
	
// }

int		ft_decode_tetri(t_tetri *tetrimino, int mp_sz_prvs, int mp_sz_crrnt)
{
	int		indx;
	int		tmp;

	if (mp_sz_prvs == mp_sz_crrnt)
		return (1);
	if (mp_sz_crrnt > mp_sz_prvs)
		if (tetrimino->x[3] % mp_sz_prvs / mp_sz_crrnt > 0 || 
			tetrimino->x[2] % mp_sz_prvs / mp_sz_crrnt > 0)
			return (0);
	while (tetrimino->c)
	{
		indx = -1;
		while (++indx < 4)
		{
			tmp = tetrimino->x[indx];
			tetrimino->x[indx] = tmp / mp_sz_prvs * mp_sz_crrnt + tmp % mp_sz_prvs;
		}
		tetrimino = tetrimino->next;
	}
	return (1);
}
