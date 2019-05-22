/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 08:55:51 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/23 20:17:03 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i1;
	unsigned char	*ps;

	i1 = 0;
	ps = (unsigned char*)b;
	while (i1 < len)
	{
		*(ps + i1++) = (unsigned char)c;
	}
	return (b);
}
