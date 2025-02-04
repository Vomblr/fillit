/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:33:39 by klekisha          #+#    #+#             */
/*   Updated: 2019/06/17 15:29:08 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			valid_pcs(char *stock, int j)
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

int			check_str(char *stock)
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

void		set_tetri(t_tetri **tmp, char *s)
{
	int	i;
	int	j;
	int z;

	i = -1;
	j = -1;
	z = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '#')
		{
			if (check_exclusion(s, i) && !z)
				z = check_exclusion(s, i);
			(*tmp)->x[++j] = z;
			z++;
		}
		if (z && s[i] != '#' && s[i] != '\n')
			z++;
	}
}

t_tetri		*stock_tetri(char *str, int num_tetraminos)
{
	int			plus21;
	char		c;
	char		*s;
	t_tetri		*tmp;
	t_tetri		*stock;

	plus21 = 0;
	c = 'A';
	if (!(stock = (t_tetri*)ft_memalloc(sizeof(t_tetri))))
		return (NULL);
	tmp = stock;
	while (num_tetraminos > 0)
	{
		tmp->c = c;
		set_tetri(&tmp, s = ft_strsub(str, 0 + plus21, 20));
		free(s);
		if (!(tmp->next = (t_tetri*)ft_memalloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
		num_tetraminos--;
		c++;
		plus21 += 21;
	}
	tmp->next = NULL;
	return (stock);
}

int			ft_decode_tetri(t_tetri *tetrimino, int mp_sz_prvs, int mp_sz_crrnt)
{
	int		indx;
	t_tetri *fx_ttr;

	fx_ttr = tetrimino;
	if (mp_sz_prvs == mp_sz_crrnt)
		return (1);
	if (mp_sz_crrnt < mp_sz_prvs)
	{
		while (tetrimino->c)
		{
			if (!(some_check(tetrimino, mp_sz_prvs, mp_sz_crrnt)))
				return (0);
			tetrimino = tetrimino->next;
		}
	}
	tetrimino = fx_ttr;
	while (tetrimino->c)
	{
		indx = -1;
		while (++indx < 4)
			deccycle(tetrimino, indx, mp_sz_prvs, mp_sz_crrnt);
		tetrimino = tetrimino->next;
	}
	return (1);
}
