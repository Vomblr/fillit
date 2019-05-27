/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/27 00:53:11 by Dmitry           ###   ########.fr       */
/*   Updated: 2019/05/26 20:20:28 by klekisha         ###   ########.fr       */
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

int		fillit(char *argv)
{
	int num_tetraminos;
	int size_square;
	int fd;
	char *stock;
	t_tetri *tetri;
	//char 	*stock;
	//t_tetri	tetrimino;

	fd = open(argv, O_RDONLY); //error check is located in "check_count_pcs_newstr"
	if (!(stock = (char *) malloc(sizeof(char) * 650)))
		return (0);
	num_tetraminos = check_count_pcs_newstr(fd, stock);
	size_square = 2;
	while (size_square * size_square < num_tetraminos * 4)
		size_square++;
	if (!check_str(stock))
		error();
	close(fd);
	tetri = stock_tetri(stock, num_tetraminos);

	//-------------------------------------------
	printFromHead(tetri);


	return 0;
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
