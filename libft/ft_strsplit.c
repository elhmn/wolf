/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 05:57:16 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 17:20:27 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		ft_get_words_nbr(int nbr, char *tmp, char c)
{
	while (tmp && *tmp)
	{
		if (*(tmp - 1) == c && *tmp != c)
			nbr++;
		tmp++;
	}
	return (nbr);
}

static int		ft_get_word_size(char *s, unsigned int *i, char c)
{
	int	wd_size;

	wd_size = 0;
	while (*(s + *i) == c)
		(*i)++;
	while (*(s + (*i + wd_size)) != c && *(s + (*i + wd_size)) != '\0')
		wd_size++;
	return (wd_size);
}

static int		ft_fillmap(char **tab, char *s, char c, int nbr)
{
	char				*s_tmp;
	int					wd_size;
	unsigned int		i;
	int					j;

	j = 0;
	i = 0;
	s_tmp = s;
	while (*(s + i) == c)
		i++;
	while (j < nbr)
	{
		wd_size = ft_get_word_size(s_tmp, &i, c);
		*(tab + j) = ft_strsub(s_tmp, i, (size_t)wd_size);
		if (!(*tab + j))
			return (0);
		j++;
		i += wd_size;
	}
	tab[nbr] = NULL;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	int			nbr;
	char		**tab;
	char		*tmp;

	tmp = (char*)s;
	if (s)
	{
		while (*tmp == c)
			tmp++;
		if (tmp == s)
			nbr = ft_get_words_nbr(1, tmp + 1, c);
		else
			nbr = ft_get_words_nbr(0, tmp, c);
		if (nbr)
		{
			tab = (char**)malloc(sizeof(char*) * (nbr + 1));
			if (!tab)
				return (NULL);
			if (!ft_fillmap(tab, (char*)s, c, nbr))
				return (NULL);
			return (tab);
		}
	}
	return (NULL);
}
