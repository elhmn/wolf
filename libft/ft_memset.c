/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:05:39 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 16:03:22 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_b;

	tmp_b = (unsigned char*)b;
	while (len && tmp_b)
	{
		*tmp_b = c;
		tmp_b++;
		len--;
	}
	return (b);
}
