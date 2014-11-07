/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 03:41:32 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 16:53:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	new_str = ft_strnew(ft_strlen(s));
	if (!new_str)
		return (NULL);
	while (s && *(s + i) && f)
	{
		*(new_str + i) = f(i, *(s + i));
		i++;
	}
	return (new_str);
}
