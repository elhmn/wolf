/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:06:40 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 16:12:52 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*tmp_1;
	char	*tmp_2;
	char	*tmp;

	tmp_1 = (char*)s1;
	while (tmp_1 && tmp_2 && *tmp_1 && tmp_1 != s1 + n)
	{
		tmp = tmp_1;
		tmp_2 = (char*)s2;
		while (*tmp_1 == *tmp_2 && *tmp_2 && tmp_1 != s1 + n)
		{
			tmp_2++;
			tmp_1++;
		}
		if ((!(*tmp_1) && *tmp_2) || ((tmp_1 == s1 + n) && *tmp_2))
			return (NULL);
		if (!(*tmp_2))
			return (tmp);
		tmp_1++;
	}
	return (NULL);
}
