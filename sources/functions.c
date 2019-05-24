/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:33:39 by klekisha          #+#    #+#             */
/*   Updated: 2019/05/23 20:14:37 by mcomet           ###   ########.fr       */
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
