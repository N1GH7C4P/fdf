/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:43:42 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 02:00:30 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

void	*init_window(void	*mlx)
{
	return (mlx_new_window(mlx, WINDOW_W, WINDOW_H, "Fdf"));
}
