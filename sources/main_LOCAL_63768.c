/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/22 21:32:57 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	// fillit(argv[1]);
	ft_atoi("123456");
	return (0);
}

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
