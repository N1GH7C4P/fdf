/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:04:31 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 03:03:28 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

t_line	*new_line(t_point *start, t_point *end)
{
	t_line	*new_line;

	new_line = (t_line *)malloc(sizeof(t_line));
	new_line->start = start;
	new_line->end = end;
	return (new_line);
}

void	line_del(t_line *line)
{
	line->start = NULL;
	line->end = NULL;
	free(line->start);
	free(line->end);
	line = NULL;
	free(line);
}
