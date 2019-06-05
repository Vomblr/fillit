/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/06/05 16:29:45 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	fillit(argv[1]);
	return (0);
}

void		fillit(char *argv)
{
	int			nm_ttr;
	int			mp_sz;
	int			mp_sz_prvs;
	int			fd;
	char		*stock;
	t_tetri		*ttr;
	char		*mp;
	int			a;

	mp_sz = 2;
	mp_sz_prvs = 4;
	a = 0;
	if (!(stock = (char *)malloc(sizeof(char) * 650)))
		error();
	opencheckstock(argv, stock, &nm_ttr);
	ttr = stock_tetri(stock, nm_ttr);
	while (mp_sz * mp_sz < nm_ttr * 4)
		mp_sz++;
	while (ft_decode_tetri(ttr, mp_sz_prvs, mp_sz) == 0)
	{
		mp_sz_prvs = mp_sz;
		mp_sz++;
	}
	if (!(mp = ft_create_map(mp_sz)))
		return ;
	while (ft_rcrsn(ttr, mp_sz, mp) != 1)
	{
		free(mp);
		mp_sz_prvs = mp_sz;
		mp_sz++;
		ft_decode_tetri(ttr, mp_sz_prvs, mp_sz);
		if (!(mp = ft_create_map(mp_sz)))
			return ;
	}
	ft_print_map(mp, mp_sz);
	return ;
}

int		ft_rcrsn(t_tetri *ttr, int mp_sz, char *mp)
{
	int			a;
	int			i;
	int			strt;
	char		*mp_tmp;
	a = -1;
	if (!(ttr->c))
		return (1);
	if ((strt = ft_tr_ttr(ttr, mp_sz, mp, 0)) == -1)
		return (-1);
	if (!(mp_tmp = ft_strnew(mp_sz * mp_sz)))
		return (-1);
	ft_strcpy(mp_tmp, mp);
	i = -1;
	while (++i < 4)
		mp[strt + ttr->x[i]] = ttr->c;
	while ((a = ft_rcrsn(ttr->next, mp_sz, mp)) != 1 && strt != -1)
	{
		ft_strcpy(mp, mp_tmp);
		if ((strt = ft_tr_ttr(ttr, mp_sz, mp, ++strt)) == -1)
			return (-1);
		i = -1;
		while (++i < 4)
			mp[strt + ttr->x[i]] = ttr->c;
	}
	return ((a != 1 && strt == -1) ? -1 : 1);
}

int		ft_tr_ttr(t_tetri *ttr, int mp_sz, char *mp, int strt)
{
	int			i;
	int			flg_sccss;
	while (strt < mp_sz * mp_sz - 3)
	{
		flg_sccss = 4;
		i = -1;
		while (++i < 4)
		{
			if (strt + ttr->x[i] > mp_sz * mp_sz)
				return (-1);
			if ((mp_sz == 3 && ((ttr->x[i] == i) || (ttr->x[i] == i + 2))) && (mp[strt + ttr->x[i]] != '.' || (strt != 0 && strt != 3)))
					flg_sccss--;
			if (ttr->x[i] > mp_sz * mp_sz || (mp[strt + ttr->x[i]] != '.') || (mp_sz <= 3 && i > 0 && (ttr->x[i] - ttr->x[i - 1] == 1) && ((strt + ttr->x[i]) % mp_sz == 0) && (ttr->x[i] != i) && (ttr->x[i] != i + 2)))
				flg_sccss--;
			if (ttr->x[i] > mp_sz * mp_sz || (mp[strt + ttr->x[i]] != '.') || (mp_sz > 3 && i > 0 && (ttr->x[i] - ttr->x[i - 1] == 1) && ((strt + ttr->x[i]) % mp_sz == 0)))
				flg_sccss--;
		}
		if (flg_sccss == 4)
			return (strt);
		strt++;
	}
	return (-1);
}

void	ft_print_map(char *mp, int mp_sz)
{
	int			nm_strs;
	int			nm_smbls;
	nm_strs = mp_sz;
	while (nm_strs--)
	{
		nm_smbls = mp_sz;
		while (nm_smbls--)
			ft_putchar(*mp++);
		ft_putchar('\n');
	}
}

char	*ft_create_map(int mp_sz)
{
	char	*mp;
	if ((size_t)(mp_sz * mp_sz) == (size_t)(-1))
		return (NULL);
	mp = (char*)malloc(mp_sz * mp_sz + 1);
	if (!mp)
		return (NULL);
	mp = (char*)ft_memset(mp, (int)('.'), (mp_sz * mp_sz));
	mp[mp_sz * mp_sz] = '\0';
	return (mp);
}
