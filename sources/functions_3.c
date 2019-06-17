/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:31:50 by mcomet            #+#    #+#             */
/*   Updated: 2019/06/17 15:32:22 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	deccycle(t_tetri *tetrimino, int indx, int mp_sz_prvs, int mp_sz_crrnt)
{
	int	tmp;

	tmp = tetrimino->x[indx];
	tetrimino->x[indx] = tmp / mp_sz_prvs * mp_sz_crrnt +
					tmp % mp_sz_prvs;
}
