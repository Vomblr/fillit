/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:56:41 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/24 21:23:37 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*p1;

	if (!(p1 = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		p1->content = NULL;
		p1->content_size = 0;
	}
	else
	{
		if (!(p1->content = malloc(content_size)))
			return (NULL);
		p1->content = ft_memcpy(p1->content, content, content_size);
		p1->content_size = content_size;
	}
	p1->next = NULL;
	return (p1);
}
