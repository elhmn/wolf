/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 04:05:24 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 18:43:55 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	if (alst && *alst)
	{
		if ((*alst)->next == NULL)
			ft_lstdelone(alst, del);
		else
		{
			ft_lstdel(&(*alst)->next, del);
			ft_lstdelone(alst, del);
		}
	}
}
