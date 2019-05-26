/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
<<<<<<< HEAD:main.c
/*   Updated: 2019/05/22 21:32:57 by klekisha         ###   ########.fr       */
=======
/*   Updated: 2019/05/25 16:30:21 by Dmitry           ###   ########.fr       */
>>>>>>> 444454ec17e26a99b7d6b51394e23c51213395d4:sources/main.c
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	// fillit(argv[1]);
	ft_atoi("123456");
	return (0);
}

<<<<<<< HEAD:main.c
// void	fillit(char *argv)
// {
// 	int		num_tetraminos;
// 	int		size_square;
// 	int		*field[20];

// 	num_tetraminos = check_count_pcs(argv);
// 	size_square = 2;
// 	while (size_square * size_square < num_tetraminos * 4)
// 		size_square++;
	
// }
=======
int		fillit(char *argv)
{
	int		num_tetraminos;
	int		size_square;
	int		fd;
	char *stock;

	fd = open(argv, O_RDONLY);
	if (!(stock = (char *)malloc(sizeof(char) * 650)))
		return (0);
	num_tetraminos = check_count_pcs_newstr(fd, stock);
	size_square = 0;
	while (size_square * size_square < num_tetraminos * 4)
		size_square++;
	if (!check_str(stock))
		error();
	else
		printf("VALID FILE");
	return 0;
}
>>>>>>> 444454ec17e26a99b7d6b51394e23c51213395d4:sources/main.c
