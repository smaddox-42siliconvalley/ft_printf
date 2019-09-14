/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:02:26 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/03 22:15:01 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*newlist;

	if (!lst)
	{
		return (NULL);
	}
	start = f(lst);
	newlist = start;
	while (lst->next)
	{
		lst = lst->next;
		newlist->next = f(lst);
		newlist = newlist->next;
	}
	return (start);
}
