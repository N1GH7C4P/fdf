/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:53:32 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/06 18:00:00 by kpolojar         ###   ########.fr       */
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

void	draw_all_lines(t_line **lines, t_params *p, int i)
{
	double	d_x;
	double	d_y;
	t_point	*temp_point;

	temp_point = new_pnt(0, 0, 0);
	while (lines[i])
	{
		d_x = toiso_x(lines[i]->end, p->n) - toiso_x(lines[i]->start, p->n);
		d_y = toiso_y(lines[i]->end, p->n) - toiso_y(lines[i]->start, p->n);
		temp_point->x = toiso_x(lines[i]->start, p->n);
		temp_point->y = toiso_y(lines[i]->start, p->n);
		draw_line(d_x, d_y, temp_point, p);
		i++;
	}
	free(temp_point);
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
