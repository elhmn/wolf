/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:36:21 by bmbarga           #+#    #+#             */
/*   Updated: 2013/12/08 17:57:59 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MY_EOF -1
# define BUFF_SIZE 10 
int		get_next_line(int const fd, char **line);
enum	e_str
{
		TMP,
		STR,
		BUFF
};
#endif
