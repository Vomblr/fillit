/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/06/04 20:51:30 by klekisha         ###   ########.fr       */
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
// int		main(void)
// {
// 	char *argv = "tests/test3_valid.txt";
// 	fillit(argv);
// 	return (0);
// }
void printFromHead(const t_tetri* list) { //TEST FUNCTION!!!
	if (list->next) {
		int i = 0;
		printf("TETRIMIN[%c]:\t", list->c);
		while (i != 4)
		{
			printf("%d  ", list->x[i]);
			i++;
		}
		putchar('\n');
		printFromHead(list->next);
	}
}

void		fillit(char *argv)
{
	int			num_tetraminos;
	int			mp_sz;
	int			map_size_previous;
	int			fd;
	char		*stock;
	t_tetri		*ttr;
	char		*mp;
	int			strt_pnt;
	int			a;

	//char 	*stock;
	//t_tetri	tetrimino;

	mp_sz = 2;	
	map_size_previous = 4;
	a = 0;
	fd = open(argv, O_RDONLY); //error check is located in "check_count_pcs_newstr"
	// printf("%i\n", errno);
	if (!(stock = (char *) malloc(sizeof(char) * 650)))
		error();
	num_tetraminos = check_count_pcs_newstr(fd, stock);
	if (!check_str(stock))
		error();
	close(fd);
	ttr = stock_tetri(stock, num_tetraminos);
	while (mp_sz * mp_sz < num_tetraminos * 4)
		mp_sz++;
	while (ft_decode_tetri(ttr, map_size_previous, mp_sz) == 0)
	{
		map_size_previous = mp_sz;
		mp_sz++;
	}
	if (!(mp = ft_create_map(mp_sz)))
		return ;
	while (ft_recursion(ttr, mp_sz, mp) != 1)
	{
		free(mp);
		map_size_previous = mp_sz;
		mp_sz++;
		ft_decode_tetri(ttr, map_size_previous, mp_sz);
		if (!(mp = ft_create_map(mp_sz)))
			return ;		
	}
	ft_print_map(mp, mp_sz);
	return ;
}
	// else
	// 	ft_putstr("VALID FILE");

int		ft_recursion(t_tetri *ttr, int mp_sz, char *mp)
{
	int			a;
	int			indx;
	int			strt_pnt;
	char		*mp_tmp;

	a = -1;
	if (!(ttr->c))
		return (1);		
	if ((strt_pnt = ft_try_tetri(ttr, mp_sz, mp, 0)) == -1)
		return (-1);
	if (!(mp_tmp = ft_strnew(mp_sz * mp_sz)))
		return (-1);
	ft_strcpy(mp_tmp, mp);
	indx = -1;
	while (++indx < 4)
		mp[strt_pnt + ttr->x[indx]] = ttr->c;
	while ((a = ft_recursion(ttr->next, mp_sz, mp)) != 1 && strt_pnt != -1)
	{
		ft_strcpy(mp, mp_tmp);
		if ((strt_pnt = ft_try_tetri(ttr, mp_sz, mp, ++strt_pnt)) == -1)
			return (-1);
		indx = -1;
		while (++indx < 4)
			mp[strt_pnt + ttr->x[indx]] = ttr->c;
	}
	return ((a != 1 && strt_pnt == -1) ? -1 : 1);
}

int		ft_try_tetri(t_tetri *ttr, int mp_sz, char *mp, int strt_pnt)
{
	int			indx;
	int			flg_sccss;

	while (strt_pnt < mp_sz * mp_sz - 3)
	{
		flg_sccss = 4;
		indx = -1;
		while (++indx < 4)
		{
			if (strt_pnt + ttr->x[indx] > mp_sz * mp_sz)
				return (-1);
			if ((mp[strt_pnt + ttr->x[indx]] != '.') || (indx > 0 && (ttr->x[indx] - ttr->x[indx - 1] == 1) && ((strt_pnt + ttr->x[indx]) % mp_sz == 0)))
				flg_sccss--;
		}
		if (flg_sccss == 4)
			return (strt_pnt);		
		strt_pnt++;
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

	if (mp_sz * mp_sz == (size_t)(-1))
		return (NULL);
	mp = (char*)malloc(mp_sz * mp_sz + 1);
	if (!mp)
		return (NULL);
	mp = (char*)ft_memset(mp, (int)('.'), (mp_sz * mp_sz));
	mp[mp_sz * mp_sz] = '\0';
	return (mp);	
}
