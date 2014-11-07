/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:12:37 by bmbarga           #+#    #+#             */
/*   Updated: 2013/11/28 04:03:05 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	while (*tmp != c && *tmp)
		tmp++;
	if (*tmp != c)
		return (NULL);
	return (tmp);
}
