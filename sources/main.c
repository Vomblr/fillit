/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/06/01 11:22:51 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <errno.h>

// int		main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		usage();
// 	fillit(argv[1]);
// 	return (0);
// }
int		main(void)
{
	char *argv = "tests/test5_valid.txt";
	fillit(argv);
	return (0);
}
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
	int num_tetraminos;
	int map_size;
	int	map_size_previous;
	int fd;
	char *stock;
	t_tetri *tetri;
	char	*map;
	int		start_point;
	int		a;

	//char 	*stock;
	//t_tetri	tetrimino;

	map_size = 2;	
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
	tetri = stock_tetri(stock, num_tetraminos);
	while (map_size * map_size < num_tetraminos * 4)
		map_size++;
	while (ft_decode_tetri(tetri, map_size_previous, map_size) == 0)
	{
		map_size_previous = map_size++;
		map_size++;
	}
	// //-------------------------------------------
	// printFromHead(tetri);
	if (!(map = ft_strnew((size_t)(map_size * map_size))))
		return ;
	ft_memset(map,(int)('.'),(map_size * map_size));	
	ft_recursion(tetri, map_size, map, 0);
	// start_point = -1;
	// while (a == 0)
	// {
	// 	a = ft_recursion(tetri, map_size, map, ++start_point);
	// 	if (a == 0)
	// 		a = ft_recursion(tetri->next, map_size, map, start_point);
	// 	map_size++;
	// 	ft_decode_tetri(tetri, map_size_previous, map_size);
	// 	free(map);
	// 	if (!(map = ft_strnew((size_t)(map_size * map_size))))
	// 		return ;
	// 	ft_memset(map, (int)('.'), (map_size * map_size));
	// }
	printf("%s", map);
	return ;
}
	// else
	// 	ft_putstr("VALID FILE");

int		ft_recursion(t_tetri *tetri, int map_size, char *map, int start_point)
{
	int		a;
	int		indx;

	indx = -1;
	while (++indx < 4)
	{
		if (start_point + tetri->x[indx] > map_size * map_size)
			return (0);
		if (map[start_point + tetri->x[indx]] != '.')
			return (0);
		map[start_point + tetri->x[indx]] = tetri->c;
	}
	a = ft_recursion(tetri->next, map_size, map, ++start_point) || ft_recursion(tetri->next, map_size, map, start_point);
	return (a);
}