/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 03:19:36 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 02:51:47 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

t_point	*new_point(float x, float y, float z)
{
	t_point	*new_point;

	new_point = (t_point *)malloc(sizeof(t_point));
	new_point->x = x;
	new_point->y = y;
	new_point->z = z;
	return (new_point);
}