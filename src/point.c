/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 03:19:36 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/06 16:25:46 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

t_point	*new_pnt(float x, float y, float z)
{
	t_point	*new_point;

	new_point = (t_point *)malloc(sizeof(t_point));
	new_point->x = x;
	new_point->y = y;
	new_point->z = z;
	return (new_point);
}

void	print_point(t_point *p)
{
	ft_putstr("(");
	ft_putnbr(p->x);
	ft_putstr(", ");
	ft_putnbr(p->y);
	ft_putstr(", ");
	ft_putnbr(p->z);
	ft_putendl(")");
}
