/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:48:01 by bmbarga           #+#    #+#             */
/*   Updated: 2013/11/28 04:25:53 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	while (*tmp)
		tmp++;
	while (*tmp != c && *tmp != *s)
		tmp--;
	if (*tmp != c)
		return (NULL);
	return (tmp);
}
