/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:59:58 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 02:01:23 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

int	totop_x(t_point *p, float angle)
{
	int	projected_x;

	projected_x = p->x + cos(angle) * p->z;
	return (projected_x);
}

int	totop_y(t_point *p, float angle)
{
	int	projected_y;

	projected_y = p->y + sin(angle) * p->z;
	return (projected_y);
}

int	toiso_x(t_point *p, float angle)
{
	int	projected_x;

	projected_x = p->x + cos(angle) * p->z - cos(angle) * p->y;
	return (projected_x);
}

int	toiso_y(t_point *p, float angle)
{
	int	projected_y;

	projected_y = -1 * (p->y) * sin(angle) - p->z * sin(angle);
	return (projected_y);
}
