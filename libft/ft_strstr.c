/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:51:07 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/26 18:58:05 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i1;
	size_t	i2;
	size_t	temp;

	i1 = 0;
	if (*haystack == 0 && *needle == 0)
		return ((char*)haystack);
	while (haystack[i1] != '\0')
	{
		i2 = 0;
		temp = i1;
		while (haystack[i1] && needle[i2] && haystack[i1] == needle[i2])
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
