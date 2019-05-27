/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:22:46 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/27 19:14:06 by klekisha         ###   ########.fr       */
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
