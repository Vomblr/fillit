/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:14:45 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/26 18:41:27 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strnstr_che(const char *needle, size_t len)
{
	if (ft_strcmp(needle, "") == 0)
		return (0);
	if (len == 0)
		return (-1);
	return (1);
}

char			*ft_strnstr(const char *haystack, const char *needle,
size_t len)
{
	size_t	i1;
	size_t	i2;
	size_t	temp;

	i1 = 0;
	if ((*haystack == 0 && *needle == 0) || (ft_strnstr_che(needle, len) == 0))
		return ((char*)haystack);
	if (ft_strnstr_che(needle, len) == -1)
		return (NULL);
	while (haystack[i1] != '\0' && i1 < len)
	{
		i2 = 0;
		temp = i1;
		while (haystack[i1] && needle[i2] && haystack[i1] == needle[i2] && \
				(i1 < len))
		{
			i1++;
			i2++;
		}
		if (needle[i2] == '\0')
			return ((char*)(haystack + temp));
		i1 = temp;
		i1++;
	}
	return (NULL);
}
