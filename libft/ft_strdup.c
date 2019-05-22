/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:35:28 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/23 20:23:29 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*temp;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	dest = (char*)(malloc(sizeof(*s1) * (i + 1)));
	if (!dest)
		return (NULL);
	temp = dest;
	while (*s1)
		*dest++ = *s1++;
	*dest = '\0';
	return (temp);
}
