/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:09:14 by klekisha          #+#    #+#             */
/*   Updated: 2019/04/25 21:04:06 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if (elem)
		elem->next = ft_lstmap(lst->next, f);
	if (elem->next == NULL && lst->next != NULL)
	{
		free(elem);
		elem = NULL;
	}
	return (elem);
}
