/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:27:24 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/08 03:18:02 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

void	flatten_projection(float scale_factor, t_params *p)
{
	if (p->z_scale < 100)
		p->z_scale = (p->z_scale * scale_factor) + 0.01;
	free_all_lines(p->lines);
	p->lines = create_lines(p, 0, 0);
	set_background_color(p, BG_COLOR);
	draw_all_lines(p, 0);
}

void	raise_projection(float scale_factor, t_params *p)
{
	p->z_scale = p->z_scale / scale_factor;
	free_all_lines(p->lines);
	p->lines = create_lines(p, 0, 0);
	set_background_color(p, BG_COLOR);
	draw_all_lines(p, 0);
}

void	change_projection(float d, t_params *p)
{
	if (p->n + d < 1000 && p->n + d > -1000)
		p->n += d;
	set_background_color(p, BG_COLOR);
	draw_all_lines(p, 0);
}

void	exit_fdf(t_params *p)
{
	mlx_destroy_window(p->mlx, p->win);
	free_params(p);
	ft_putendl("Exiting FDF");
	exit(0);
}
