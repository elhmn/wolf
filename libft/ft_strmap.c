/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 03:31:07 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 16:52:37 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_strnew(ft_strlen(s));
	if (!new_str)
		return (NULL);
	while (s && *(s + i) && f)
	{
		*(new_str + i) = f(*(s + i));
		i++;
	}
	return (new_str);
}
