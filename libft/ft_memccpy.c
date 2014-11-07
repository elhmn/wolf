/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:43:41 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 18:57:14 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;
	char	car;

	car = (char)c;
	tmp_s = (char*)src;
	tmp_d = (char*)dest;
	while (n != 0 && *tmp_s != car)
	{
		*tmp_d = *tmp_s;
		tmp_d++;
		tmp_s++;
		n--;
	}
	if (*tmp_s == car)
	{
		*tmp_d = *tmp_s;
		return ((void*)++tmp_d);
	}
	return (NULL);
}
