/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:14:34 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/23 20:30:42 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *temp;

	temp = s;
	while (*s)
		s++;
	if (*s == (char)c)
		return ((char*)s);
	while (s != temp && *s != (char)c)
	{
		s--;
	}
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
