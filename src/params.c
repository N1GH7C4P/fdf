/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 01:04:28 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/08 03:26:42 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

t_params	*new_params(void)
{
	t_params	*p;

	p = (t_params *)malloc(sizeof(t_params));
	p->mlx = mlx_init();
	p->win = init_window(p->mlx);
	p->color = COLOR;
	p->n = ANGLE;
	p->x_scale = X_SCALE;
	p->y_scale = Y_SCALE;
	p->z_scale = Z_SCALE;
	p->x_offset = X_OFFSET;
	p->y_offset = Y_OFFSET;
	return (p);
}

void	free_params(t_params *p)
{
	free_all_lines(p->lines);
	free_map(p->map);
	free(p->mlx);
	free(p);
}
