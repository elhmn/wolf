/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:48:17 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/08 14:17:31 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHECK_ERRORS_H
# define CHECK_ERRORS_H

# define ERR			ft_putstr("Error : ");
# define ERR_VAR(var)	ft_putstr(var);
# define ERR_SP			ft_putstr(" :: ");
# define ERR_FILE(file)	ft_putstr(file);
# define ERR_MALLOC 	ft_putendl("malloc");

enum	e_code
{
	MALLOC
};


void	check_errors(t_uint code, char *file_name, char *var_name);

#endif
