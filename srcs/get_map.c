/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 23:20:51 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/05 16:18:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}

char		**get_map(void)
{
	char		**map = malloc(sizeof(char*) * 12);
	int			i;

	i = -1;
	
	map[11] = 0;
	while (++i < 11)
		map[i] = ft_strnew(11);
	ft_strcpy(map[0], "1111111111");
	ft_strcpy(map[1], "1000010001");
	ft_strcpy(map[2], "1010000011");
	ft_strcpy(map[3], "1000000101");
	ft_strcpy(map[4], "1010000011");
	ft_strcpy(map[5], "1000000001");
	ft_strcpy(map[6], "1010010011");
	ft_strcpy(map[7], "1000000001");
	ft_strcpy(map[8], "1001101001");
	ft_strcpy(map[9], "1000001001");
	ft_strcpy(map[10], "1111111111");

	return (map);
}
