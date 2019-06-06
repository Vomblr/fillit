/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:05:35 by klekisha          #+#    #+#             */
/*   Updated: 2019/06/05 18:06:16 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_print_map(char *mp, int mp_sz)
{
	int			nm_strs;
	int			nm_smbls;

	nm_strs = mp_sz;
	while (nm_strs--)
	{
		nm_smbls = mp_sz;
		while (nm_smbls--)
			ft_putchar(*mp++);
		ft_putchar('\n');
	}
}

char	*ft_create_map(int mp_sz)
{
	char	*mp;

	if ((size_t)(mp_sz * mp_sz) == (size_t)(-1))
		return (NULL);
	mp = (char*)malloc(mp_sz * mp_sz + 1);
	if (!mp)
		return (NULL);
	mp = (char*)ft_memset(mp, (int)('.'), (mp_sz * mp_sz));
	mp[mp_sz * mp_sz] = '\0';
	return (mp);
}

void	freelist(t_tetri *head)
{
	t_tetri	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int		check_exclusion(char *s, int i)
{
	if ((i <= 11) &&
		((s[i + 1] == '#' && s[i + 4] == '#' && s[i + 5] == '#') ||
		(s[i + 4] == '#' && s[i + 5] == '#' && s[i + 6] == '#') ||
		(s[i + 5] == '#' && s[i + 9] == '#' && s[i + 10] == '#') ||
		(s[i + 4] == '#' && s[i + 5] == '#' && s[i + 10] == '#') ||
		(s[i + 4] == '#' && s[i + 5] == '#' && s[i + 9] == '#')))
		return (1);
	else if ((i <= 16) &&
			(s[i + 3] == '#' && s[i + 4] == '#' && s[i + 5] == '#'))
		return (2);
	else
		return (0);
}
