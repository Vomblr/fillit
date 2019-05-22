/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:29:51 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/25 19:36:17 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i1;
	unsigned char	*pd;
	unsigned char	*ps;

	i1 = 0;
	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	if (dst == src)
	{
		return (dst);
	}
	while (i1 < n)
	{
		*(pd + i1) = *(ps + i1);
		i1++;
	}
	return (dst);
}
