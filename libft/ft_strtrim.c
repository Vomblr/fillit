/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 11:06:33 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/23 20:41:17 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_record_word(int len, char const *s, int t1)
{
	char	*fresh;

	if (!(fresh = (char*)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	fresh[len + 1] = '\0';
	while (len >= 0)
	{
		fresh[len] = s[t1 + len];
		len--;
	}
	return (fresh);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	int		i1;
	int		t1;

	i1 = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1++;
	t1 = i1;
	while (s[i1])
	{
		i1++;
		len++;
	}
	while (i1 > t1 && (s[i1] == '\0' || s[i1] == ' ' || s[i1] == '\n'
	|| s[i1] == '\t'))
	{
		i1--;
		len--;
	}
	return (ft_record_word(len, s, t1));
}
