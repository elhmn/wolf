/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:55:40 by bmbarga           #+#    #+#             */
/*   Updated: 2013/11/28 04:29:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*tmp_1;
	char	*tmp_2;
	char	*tmp;

	tmp_1 = (char*)s1;
	tmp_2 = (char*)s2;
	while (*tmp_1)
	{
		tmp = tmp_1;
		tmp_2 = (char*)s2;
		while (*tmp_1 == *tmp_2 && *tmp_2 && *tmp_1)
		{
			tmp_2++;
			tmp_1++;
		}
		if (!(*tmp_1) && *tmp_2)
			return (NULL);
		if (!(*tmp_2))
			return (tmp);
		tmp_1++;
	}
	return (NULL);
}
