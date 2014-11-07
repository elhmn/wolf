/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 06:26:04 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 18:44:18 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void	ft_lstmap_aux(t_list *l1, t_list **l2, t_list *(*f) (t_list *elem))
{
	t_list	*tmp;

	if (l1->next == NULL)
	{
		tmp = f(l1);
		tmp = ft_lstnew(tmp->content, tmp->content_size);
		(*l2)->next = tmp;
	}
	else
	{
		tmp = f(l1);
		tmp = ft_lstnew(tmp->content, tmp->content_size);
		(*l2)->next = tmp;
		ft_lstmap_aux(l1->next, &tmp, f);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*lst_2;

	if (lst)
	{
		lst_2 = f(lst);
		lst_2 = ft_lstnew(lst_2->content, lst_2->content_size);
		if (!lst_2)
			return (NULL);
		ft_lstmap_aux(lst, &lst_2, f);
	}
	return (lst_2);
}
