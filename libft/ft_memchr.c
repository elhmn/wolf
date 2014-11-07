/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:10:43 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 16:03:05 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		car;
	const unsigned char	*ptr;

	car = (unsigned char)c;
	ptr = (const unsigned char*)s;
	while (n)
	{
		if (*ptr == car)
			return ((void*)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
