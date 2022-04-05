/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 01:04:28 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 02:02:53 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

t_params	*new_params(int color)
{
	t_params	*p;

	p = (t_params *)malloc(sizeof(t_params));
	p->mlx = mlx_init();
	p->win = init_window(p->mlx);
	p->color = color;
	return (p);
}
