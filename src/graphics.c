/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:53:32 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 03:22:18 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

void	draw_all_lines_isometrically(t_line **lines, t_params *p, int i)
{
	double	d_x;
	double	d_y;

	while (lines[i])
	{
		d_x = toiso_x(lines[i]->end, ANGLE) - toiso_x(lines[i]->start, ANGLE);
		d_y = toiso_y(lines[i]->end, ANGLE) - toiso_y(lines[i]->start, ANGLE);
		lines[i]->start->x = toiso_x(lines[i]->start, ANGLE);
		lines[i]->start->y = toiso_y(lines[i]->start, ANGLE);
		draw_line(d_x, d_y, lines[i]->start, p);
		i++;
	}
}

void	draw_all_lines_from_top(t_line **lines, t_params *p, int i)
{
	double	d_x;
	double	d_y;

	while (lines[i])
	{
		d_x = totop_x(lines[i]->end, ANGLE) - totop_x(lines[i]->start, ANGLE);
		d_y = totop_y(lines[i]->end, ANGLE) - totop_y(lines[i]->start, ANGLE);
		lines[i]->start->x = totop_x(lines[i]->start, ANGLE);
		lines[i]->start->y = totop_y(lines[i]->start, ANGLE);
		draw_line(d_x, d_y, lines[i]->start, p);
		i++;
	}
}

void	draw_line(double d_x, double d_y, t_point *start, t_params *p)
{
	int		pixels;

	start->x += X_OFFSET;
	start->y += Y_OFFSET;
	pixels = sqrt((d_x * d_x) + (d_y * d_y));
	d_x = d_x / pixels;
	d_y = d_y / pixels;
	while (pixels)
	{
		mlx_pixel_put(p->mlx, p->win, start->x, start->y, p->color);
		start->x += d_x;
		start->y += d_y;
		--pixels;
	}
}
