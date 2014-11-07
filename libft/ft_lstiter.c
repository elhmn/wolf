/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 05:43:54 by bmbarga           #+#    #+#             */
/*   Updated: 2013/11/29 07:00:33 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	if (lst)
	{
		if (lst->next == NULL)
			f(lst);
		else
		{
			f(lst);
			ft_lstiter(lst->next, f);
		}
	}
}
