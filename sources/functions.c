/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:33:39 by klekisha          #+#    #+#             */
/*   Updated: 2019/05/25 17:29:07 by Dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		check_count_pcs_newstr(int fd, char *str)
{
	int		i;
	int		ret;
	char	buff[2];
	int		j;

	i = 1;
	if ((fd < 0))
		usage();
	j = 0;
	while ((ret = read(fd, buff, 1)))
	{
		buff[ret] = '\0';
		if (buff[0] != '.' && buff[0] != '#' && buff[0] != '\n' && buff[0] != '\0')
			error();
		str[j] = buff[0];
		j++;
		if (buff[0] == '\n')
			i++;
	}
	str[j] = '\0';
	if ((i % 5) == 0 && (i = (i / 5)) <= 26)
		return (i);
	return (0);
}

int check_pcs_links(char *stock, int j)
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

int valid_pcs(char *stock, int j)
{
	int dash;
	int dot;
	int newline;
	int i;

	i = 0;
	dash = 0;
	dot = 0;
	newline = 0;
	while ((i + j) < (20 + j) && stock[i + j] != '\0')
	{
		if (stock[i + j] == '#')
			dash++;
		if (stock[i + j] == '.')
			dot++;
		if (stock[i + j] == '\n')
			newline++;
		i++;
	}
	if (dash == 4 && dot == 12 && newline == 4)
		return (1);
	return (0);
}

int 	check_str(char *stock)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (stock[i + j] != '\0')
	{
		if (!(check_pcs_links(stock, j) && valid_pcs(stock, j)))
			return (0);
		i += 19;
		if ((stock[i + j]) == '\n' && stock[i + j + 1] == '\0')
			break ;
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\n'
			&& (stock[i + j + 2] == '.' || stock[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}
