/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/28 21:28:27 by klekisha         ###   ########.fr       */
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
	//char 	*stock;
	//t_tetri	tetrimino;

	map_size = 2;	
	map_size_previous = 4;
	fd = open(argv, O_RDONLY); //error check is located in "check_count_pcs_newstr"
	if (!(stock = (char *) malloc(sizeof(char) * 650)))
		error();
	num_tetraminos = check_count_pcs_newstr(fd, stock);
	if (!check_str(stock))
		error();
	close(fd);
	tetri = stock_tetri(stock, num_tetraminos);
	while (map_size * map_size < num_tetraminos * 4)
		map_size++;
	while (ft_decode_tetri(*tetri, map_size_previous, map_size) == 0)
	{
		map_size_previous = map_size++;
		map_size++;
	}
	// //-------------------------------------------
	// printFromHead(tetri);
	if (!(map = ft_strnew((size_t)(map_size * map_size))))
		return ;
	while ((ft_recursion(&tetri, map_size, map)) == 0)
	{
		map_size++
		free(map);
		if (!(map = ft_strnew((size_t)(map_size * map_size))))
			return ;
	}
	return ;
}
/*=======
	else
		ft_putstr("VALID FILE");
	// example of one tetrimino:
	// {0,1,2,3} = ####
	// first of all, we need to check 2x2 and 3x3 maps 
	
	ft_check_map_for_1_tetr(tetrimino, num_tetraminos);
	ft_check_map_for_2_tetr(tetrimino, num_tetraminos);
	return (0);

}
*/

int		ft_recursion(t_tetri *tetri, int map_size, char *map)
{
	int		a;

	a = ft_recursion(tetri->next, map_size, map);
	return ()
}