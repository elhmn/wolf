/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 02:05:25 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 16:00:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(*ptr) * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return ((void*)ptr);
}
