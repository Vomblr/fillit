/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:16:18 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/25 22:19:28 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;

	if (size == (size_t)(-1))
		return (NULL);
	temp = (char*)malloc(size + 1);
	if (!temp)
		return (NULL);
	temp = (char*)ft_memset(temp, 0, size + 1);
	return (temp);
}
