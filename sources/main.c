/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/23 20:15:09 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	fillit(argv[1]);
	return (0);
}

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
	//printf("%s", stock);
}
