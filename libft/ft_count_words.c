/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:07:28 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/26 17:54:20 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s, char c)
{
	int		i1;
	size_t	len_word;

	if (!s)
		return (-1);
	i1 = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (i1);
		i1++;
		len_word = 1;
		while (*s && *s != c)
		{
			s++;
			len_word++;
		}
	}
	return (i1);
}
