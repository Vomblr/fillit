/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/06/17 16:26:53 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		main(int argc, char **argv)
{
	t_tetri		*ttr;
	char		*stock;
	int			nm_ttr;

	if (argc != 2)
	{
		write(1, "usage: ./fillit <FILE_MAP>\n", 27);
		exit(0);
	}
	if (!(stock = (char *)malloc(sizeof(char) * 650)))
		error();
	opencheckstock(argv[1], stock, &nm_ttr);
	ttr = stock_tetri(stock, nm_ttr);
	ttr->nm_ttr = nm_ttr;
	fillit(ttr);
	free(stock);
	freelist(ttr);
	return (0);
}

void	fillit(t_tetri *ttr)
{
	int			mp_sz;
	int			mp_sz_prvs;
	char		*mp;

	mp_sz = 2;
	mp_sz_prvs = 4;
	while (mp_sz * mp_sz < ttr->nm_ttr * 4)
		mp_sz++;
	while (ft_decode_tetri(ttr, mp_sz_prvs, mp_sz) == 0)
		if (mp_sz_prvs < mp_sz++)
			mp_sz_prvs = mp_sz;
	if (!(mp = ft_create_map(mp_sz)))
		error();
	while (ft_rcrsn(ttr, mp_sz, mp) != 1)
	{
		free(mp);
		mp_sz_prvs = mp_sz;
		mp_sz++;
		ft_decode_tetri(ttr, mp_sz_prvs, mp_sz);
		if (!(mp = ft_create_map(mp_sz)))
			error();
	}
	ft_print_map(mp, mp_sz);
	free(mp);
}

int		ft_rcrsn(t_tetri *ttr, int mp_sz, char *mp)
{
	t_magic		m;

	m.i = -1;
	if (!(ttr->c))
		return (1);
	if ((m.strt = ft_tr_ttr(ttr, mp_sz, mp, 0)) == -1)
		return (-1);
	if ((!(m.mp_tmp = ft_strnew(mp_sz * mp_sz))) || !ft_strcpy(m.mp_tmp, mp))
		return (-1);
	while (++m.i < 4)
		mp[m.strt + ttr->x[m.i]] = ttr->c;
	while ((m.a = ft_rcrsn(ttr->next, mp_sz, mp)) != 1 && m.strt != -1)
	{
		ft_strcpy(mp, m.mp_tmp);
		if ((m.strt = ft_tr_ttr(ttr, mp_sz, mp, ++m.strt)) == -1)
		{
			free(m.mp_tmp);
			return (-1);
		}
		m.i = -1;
		while (++m.i < 4)
			mp[m.strt + ttr->x[m.i]] = ttr->c;
	}
	free(m.mp_tmp);
	return ((m.a != 1 && m.strt == -1) ? -1 : 1);
}

int		ft_tr_ttr(t_tetri *ttr, int mp_sz, char *mp, int strt)
{
	int			i;
	int			t;
	int			flg_sccss;

	while (strt + ttr->x[3] <= mp_sz * mp_sz)
	{
		flg_sccss = 4;
		i = -1;
		while (++i < 4 && (t = ttr->x[i]) != -1)
		{
			if (mp_sz == 3)
				if (ft_check_map_3(ttr, mp, strt, i) == -1)
					flg_sccss--;
			if ((mp[strt + t] != '.') || (mp_sz == 2 && i + 1 != mp_sz && i > 0
			&& (t - ttr->x[i - 1] == 1)
			&& ((strt + t) % mp_sz == 0) && (t != i) && (t != i + 2))
			|| (mp_sz > 3 && i > 0
			&& (t - ttr->x[i - 1] == 1) && ((strt + t) % mp_sz == 0)))
				flg_sccss--;
		}
		if (flg_sccss == 4)
			return (strt);
		strt++;
	}
	return (-1);
}

int		ft_check_map_3(t_tetri *ttr, char *mp, int strt, int i)
{
	int	t;

	if (mp[strt + ttr->x[i]] != '.')
		return (-1);
	if (strt != 0 && strt != 3 && ((
		(i < 3 && ttr->x[i] == 2 && ttr->x[i + 1] == 3)
	|| (i < 2 && ((t = ttr->x[i] / 3) != -1)
	&& ttr->x[i + 1] / 3 == t && ttr->x[i + 2] / 3 == t)
	|| (ttr->x[0] == 0 && ttr->x[1] == 1 && ttr->x[2] == 4 && ttr->x[3] == 5))))
		return (-1);
	if (ttr->nm_ttr != -1)
		if (i + 1 != 3 && i > 0 && (ttr->x[i] - ttr->x[i - 1] == 1) &&
		((strt + ttr->x[i]) % 3 == 0)
		&& (ttr->x[i] != i) && (ttr->x[i] != i + 2))
			return (-1);
	if (strt >= 2 && ttr->x[3] / 3 == 2)
		return (-1);
	return (1);
}
