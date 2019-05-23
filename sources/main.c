/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/23 17:09:43 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	fillit(argv[1]);
	return (0);
}

void	fillit(char *argv)
{
	int		num_tetraminos;
	int		size_square;
	int 	fd;
	char	*stock;

	fd = open(argv[1], O_RDONLY);
	num_tetraminos = check_count_pcs(fd);
	stock = save_str(fd);
	size_square = 0;
	while (size_square * size_square < num_tetraminos * 4)
		size_square++;
}
