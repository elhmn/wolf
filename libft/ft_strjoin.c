/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 04:42:54 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 18:49:25 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp_s1;

	if (s1 && s2)
	{
		tmp_s1 = ft_strnew(ft_strlen(s2) + ft_strlen(s1));
		if (!tmp_s1)
			return (NULL);
		ft_strcpy(tmp_s1, s1);
		ft_strcat(tmp_s1, s2);
	}
	return (tmp_s1);
}
