/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 01:04:28 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 18:33:03 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

t_params	*new_params(t_map *map)
{
	t_params	*p;

	p = (t_params *)malloc(sizeof(t_params));
	p->mlx = mlx_init();
	p->win = init_window(p->mlx);
	p->map_width = map->width;
	p->map_height = map->height;
	p->color = COLOR;
	p->n = ANGLE;
	p->x_scale = X_SCALE;
	p->y_scale = Y_SCALE;
	p->z_scale = Z_SCALE;
	p->x_offset = X_OFFSET;
	p->y_offset = Y_OFFSET;
	return (p);
}
