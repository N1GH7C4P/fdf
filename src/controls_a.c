/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:27:27 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/08 03:15:56 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

void	zoom_in(float scale_factor, t_params *p)
{
	p->x_scale = p->x_scale / scale_factor;
	p->y_scale = p->y_scale / scale_factor;
	p->z_scale = p->z_scale / scale_factor;
	free_all_lines(p->lines);
	p->lines = create_lines(p, 0, 0);
	set_background_color(p, BG_COLOR);
	draw_all_lines(p, 0);
}

void	zoom_out(float scale_factor, t_params *p)
{
	if (p->z_scale < 100 && p->x_scale < 100 && p->y_scale < 100)
	{
		p->x_scale = (p->x_scale * scale_factor) + 0.01;
		p->y_scale = (p->y_scale * scale_factor) + 0.01;
		p->z_scale = (p->z_scale * scale_factor) + 0.01;
	}
	free_all_lines(p->lines);
	p->lines = create_lines(p, 0, 0);
	set_background_color(p, BG_COLOR);
	draw_all_lines(p, 0);
}

void	move_projection(int dx, int dy, t_params *p)
{
	if (p->x_offset + dx < (p->map->width + WINDOW_W) * p->x_scale)
		if (p->x_offset + dx > (p->map->width - WINDOW_W) * p->x_scale)
			p->x_offset += dx;
	if (p->y_offset + dy < (p->map->height + WINDOW_H) * p->y_scale)
		if (p->y_offset + dy > (p->map->height - WINDOW_H) * p->y_scale)
			p->y_offset += dy;
	set_background_color(p, BG_COLOR);
	draw_all_lines(p, 0);
}
