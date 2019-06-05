/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:22:46 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/29 21:09:46 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	usage(void)
{
	write(1, "usage: ./fillit <FILE_MAP>\n", 27);
	exit(0);
}

void	error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	opencheckstock(char *argv, char *stock, int *nm_ttr)
{
	int fd;

	fd = open(argv, O_RDONLY);
	*nm_ttr = check_count_pcs_newstr(fd, stock);
	if (!check_str(stock))
		error();
	close(fd);
}

int		check_count_pcs_newstr(int fd, char *str)
{
	int		i;
	int		ret;
	char	buf[2];
	int		j;

	i = 1;
	if ((fd < 0))
		usage();
	j = 0;
	while ((ret = read(fd, buf, 1)))
	{
		buf[ret] = '\0';
		if (buf[0] != '.' && buf[0] != '#' && buf[0] != '\n' && buf[0] != '\0')
			error();
		str[j] = buf[0];
		j++;
		if (buf[0] == '\n')
			i++;
	}
	str[j] = '\0';
	if ((i % 5) == 0 && (i = (i / 5)) <= 26)
		return (i);
	else
		error();
	return (0);
}

int		check_pcs_links(char *stock, int j)
{
	int	link;
	int i;

	i = 0;
	link = 0;
	while (i + j < 20 + j)
	{
		if (stock[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && stock[i + j + 1] == '#')
				link++;
			if ((i + j - 1) >= (0 + j) && stock[i + j - 1] == '#')
				link++;
			if ((i + j + 5) < (20 + j) && stock[i + j + 5] == '#')
				link++;
			if ((i + j - 5) >= (0 + j) && stock[i + j - 5] == '#')
				link++;
		}
		i++;
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}
