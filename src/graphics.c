/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:53:32 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/08 03:23:24 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

void	set_background_color(t_params *p, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_H)
	{
		j = 0;
		while (j < WINDOW_W)
		{
			mlx_pixel_put(p->mlx, p->win, j, i, colour);
			j++;
		}
		i++;
	}
}

void	draw_all_lines(t_params *p, int i)
{
	double	d_x;
	double	d_y;
	t_point	*temp_point;

	temp_point = new_p(0, 0, 0);
	while (p->lines[i])
	{
		d_x = iso_x(p->lines[i]->end, p->n) - iso_x(p->lines[i]->start, p->n);
		d_y = iso_y(p->lines[i]->end, p->n) - iso_y(p->lines[i]->start, p->n);
		temp_point->x = iso_x(p->lines[i]->start, p->n);
		temp_point->y = iso_y(p->lines[i]->start, p->n);
		draw_line(d_x, d_y, temp_point, p);
		i++;
	}
	free(temp_point);
}

void	draw_line(double d_x, double d_y, t_point *start, t_params *p)
{
	int		pixels;

	start->x += p->x_offset;
	start->y += p->y_offset;
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
