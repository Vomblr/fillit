/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/06/12 20:39:49 by klekisha         ###   ########.fr       */
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
	fillit(ttr, nm_ttr);
	free(stock);
	freelist(ttr);
	return (0);
}

// int		main(int argc, char **argv)
// {
// 	t_tetri		*ttr;
// 	char		*stock;
// 	int			nm_ttr;

// 	// char		*arg = "test1";
// 	// char		*arg = "test2";
// 	// char		*arg = "test3";
// 	// char		*arg = "test4";
// 	char		*arg = "test5";

// 	if (!(stock = (char *)malloc(sizeof(char) * 650)))
// 		error();
// 	opencheckstock(arg, stock, &nm_ttr);
// 	ttr = stock_tetri(stock, nm_ttr);
// 	fillit(ttr, nm_ttr);
// 	free(stock);
// 	freelist(ttr);
// 	return (0);
// }

void	fillit(t_tetri *ttr, int nm_ttr)
{
	int			mp_sz;
	int			mp_sz_prvs;
	char		*mp;

	mp_sz = 2;
	mp_sz_prvs = 4;
	while (mp_sz * mp_sz < nm_ttr * 4)
		mp_sz++;
	while (ft_decode_tetri(ttr, mp_sz_prvs, mp_sz) == 0)
		if (mp_sz_prvs < mp_sz++)
			mp_sz_prvs = mp_sz;
	if (!(mp = ft_create_map(mp_sz)))
		error();
	while (ft_rcrsn(ttr, mp_sz, mp, nm_ttr) != 1)
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

int		ft_rcrsn(t_tetri *ttr, int mp_sz, char *mp, int nm_ttr)
{
	t_magic		m;

	m.i = -1;
	if (!(ttr->c))
		return (1);
	if ((m.strt = ft_tr_ttr(ttr, mp_sz, mp, 0, nm_ttr)) == -1)
		return (-1);
	if ((!(m.mp_tmp = ft_strnew(mp_sz * mp_sz))) || !ft_strcpy(m.mp_tmp, mp))
		return (-1);
	while (++m.i < 4)
		mp[m.strt + ttr->x[m.i]] = ttr->c;
	while ((m.a = ft_rcrsn(ttr->next, mp_sz, mp, nm_ttr)) != 1 && m.strt != -1)
	{
		ft_strcpy(mp, m.mp_tmp);
		if ((m.strt = ft_tr_ttr(ttr, mp_sz, mp, ++m.strt, nm_ttr)) == -1)
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

int		ft_tr_ttr(t_tetri *ttr, int mp_sz, char *mp, int strt, int nm_ttr)
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
			if (mp_sz == 3 && ((i < 3 && t == 2 && ttr->x[i + 1] == 3 &&
			(mp[strt + t] != '.' || (strt != 0 && strt != 3))) ||
			(nm_ttr == 1 && i + 1 != mp_sz && i > 0 && (t - ttr->x[i - 1] == 1) && ((strt + t) % mp_sz == 0) && (t != i) && (t != i + 2))
			|| (nm_ttr == 2 && i > 0 && (t - ttr->x[i - 1] == 1) && ((strt + t) % mp_sz == 0) && (t != i) && (t != i + 2))))
			flg_sccss--;
			if ((mp[strt + t] != '.') || (mp_sz == 2 && i + 1 != mp_sz && i > 0 &&
				(t - ttr->x[i - 1] == 1) &&
				((strt + t) % mp_sz == 0) && (t != i) && (t != i + 2))
			   || (mp_sz > 3 && i > 0 &&
				(t - ttr->x[i - 1] == 1) && ((strt + t) % mp_sz == 0)))
				flg_sccss--;
		}
		if (flg_sccss == 4)
			return (strt);
		strt++;
	}
	return (-1);
}

//&& i + 1 != mp_sz