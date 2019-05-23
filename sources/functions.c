/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:33:39 by klekisha          #+#    #+#             */
/*   Updated: 2019/05/23 16:57:39 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_count_pcs(int fd)
{
	int		i;
	int		ret;
	char	buff[2];

	i = 1;
	if ((fd < 0))
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

char	*save_str(int fd)
{
	int		ret;
	int		i;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	ret = read(fd, &c, 1);
	if (ret == 1)
	{
		str = (char *)malloc(sizeof(char) * 650);
		while (ret != '\0')
		{
			str[i] = c;
			i++;
			ret = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	return (str);
}
