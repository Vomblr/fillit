/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:47:52 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/25 21:11:55 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	n1;

	if (n < 0)
	{
		ft_putchar('-');
		n1 = (unsigned int)(-n);
	}
	else
		n1 = (unsigned int)n;
	if (n1 >= 10)
		ft_putnbr((int)(n1 / 10));
	ft_putchar(n1 % 10 + '0');
}
