/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 08:32:54 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/26 17:57:49 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_array_free(char **array, unsigned int size)
{
	unsigned int i1;

	i1 = 0;
	if (!array)
		return ;
	while (i1 < size)
	{
		free(array[i1]);
		i1++;
	}
	*array = NULL;
	array = NULL;
	return ;
}

static char		*ft_rec_new_word(char **t5, int i1,
char const *s, char c)
{
	char	*t3;
	size_t	len_word;

	len_word = 1;
	while (s[len_word] && s[len_word] != c)
		len_word++;
	if (!(t3 = (char*)malloc(len_word + 1)))
	{
		ft_array_free(t5, (unsigned int)(i1 + 1));
		return (NULL);
	}
	ft_memccpy((void*)t3, (const void*)s, (int)c, len_word + 1);
	t3[len_word] = '\0';
	return (t3);
}

char			**ft_strsplit(char const *s, char c)
{
	int			c1;
	int			i1;
	char		**t5;
	size_t		len_word;

	i1 = 0;
	c1 = ft_count_words(s, c);
	if (c1 == -1 || !(t5 = (char**)malloc(sizeof(s) * (c1 + 1))))
		return (NULL);
	while (i1 < c1)
	{
		len_word = 1;
		while (*s == c)
			s++;
		while (s[len_word] && s[len_word] != c)
			len_word++;
		t5[i1] = ft_rec_new_word(t5, i1, s, c);
		if (!t5[i1])
			return (NULL);
		i1++;
		s += len_word;
	}
	t5[i1] = NULL;
	return (t5);
}
