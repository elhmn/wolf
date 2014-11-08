/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:15:13 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/08 14:19:05 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "wolf3d.h"
#include "check_errors.h"

void	check_errors(t_uint code, char *file_name, char *var_name)
{
	t_uint	i;

	i = -1;
	ERR ERR_VAR(var_name) ERR_SP ERR_FILE(file_name) ERR_SP
	while (++i < (MALLOC + 1))
		if (i == code)
			ERR_MALLOC
	exit(0);
}
