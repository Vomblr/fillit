/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:48:59 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/22 19:56:05 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	fillit(argv[1]);
	return (0);
}

void	fillit(char *argv)
{
	int	pcs;
	int	size;

	size = 0;
	while (size * size < pcs * 4)
		size++;


}

int		check_count_pcs(char *argv)
{
	int		i;
	int		ret;
	int		fd;
	char	buff[2];

	i = 1;
	if ((fd = open(argv, O_RDONLY)) < 0)
		usage();
	while ((ret = read(fd, buff, 1)))
	{
		buff[ret] = '\0';
		if (buff[0] != '.' && buff[0] != '#' && buff[0] != '\n' && buff[0] != '\0')
			error();
		if (buff[0] == '\n')
			i++;
	}
	if ((i % 5) == 0 && (i = (i / 5)) <= 26)
		return (i);
	return (0);

}


