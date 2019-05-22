/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:50:05 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/23 20:11:00 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i1;
	unsigned char	*ps;

	i1 = 0;
	ps = (unsigned char*)s;
	while (i1 < n)
	{
		if (*(ps + i1) == (unsigned char)c)
			return ((void*)(ps + i1));
		i1++;
	}
	return (NULL);
}
