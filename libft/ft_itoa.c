/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 05:50:15 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 17:36:54 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "stdlib.h"
#include "libft.h"

static int	ft_get_nbr_size(int n)
{
	int		size;

	size = 0;
	if (n < 0)
		size++;
	while ((n /= 10))
		size++;
	return (size + 1);
}

static char	*ft_fill_car_nbr(char **car_nbr, int n, int i)
{
	if (!(n / 10))
	{
		*(*car_nbr + i) = n + '0';
		return (*car_nbr);
	}
	ft_fill_car_nbr(car_nbr, n / 10, i - 1);
	ft_fill_car_nbr(car_nbr, n % 10, i);
	return (*car_nbr);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*car_nbr;

	if (n > MAX_NBR || n < MIN_NBR)
	{
		if (!(car_nbr = malloc(sizeof(char))))
			return (NULL);
		*car_nbr = '0';
		return (car_nbr);
	}
	size = ft_get_nbr_size(n);
	car_nbr = ft_strnew((size_t)size);
	if (n < 0)
	{
		car_nbr[0] = '-';
		n *= -1;
	}
	ft_fill_car_nbr(&car_nbr, n, size - 1);
	return (car_nbr);
}
