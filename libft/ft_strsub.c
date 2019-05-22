/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:20:41 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/23 20:31:08 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i1;
	char	*fresh;

	i1 = 0;
	if (!s)
		return (NULL);
	fresh = (char*)malloc(sizeof(char) * (len + 1));
	if (!fresh)
		return (NULL);
	while (i1 < len)
	{
		fresh[i1] = s[start + i1];
		i1++;
	}
	fresh[i1] = '\0';
	return (fresh);
}
