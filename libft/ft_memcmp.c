/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:36:59 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 16:04:13 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_1;
	const unsigned char	*ptr_2;

	ptr_1 = (const unsigned char*)s1;
	ptr_2 = (const unsigned char*)s2;
	while (n)
	{
		if (*ptr_1 != *ptr_2)
			return ((int)(*ptr_1 - *ptr_2));
		n--;
		ptr_1++;
		ptr_2++;
	}
	return (0);
}
