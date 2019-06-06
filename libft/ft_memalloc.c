/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:50:55 by mcomet            #+#    #+#             */
/*   Updated: 2019/04/18 15:32:45 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memarea;

	if (size == (size_t)(-1))
		return (0);
	if (!(memarea = malloc(size)))
		return (NULL);
	ft_bzero(memarea, size);
	return (memarea);
}
