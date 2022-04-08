/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:01:15 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/08 03:26:17 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

static int	count_links(t_map *m)
{
	int	l;

	l = ((m->width - 1) * m->height) + ((m->height - 1) * m->width);
	return (l);
}

static int	get_z_at_map_coordinates(t_map *map, int x, int y)
{
	int	nums;
	int	i;
	int	result;

	nums = -1;
	i = 0;
	while (map->content[y][i])
	{
		if (ft_isdigit(map->content[y][i]) && map->content[y][i + 1] != 'x')
		{
			nums++;
			if (nums == x)
			{
				result = atoi(map->content[y] + i);
				break ;
			}
			while (ft_isdigit(map->content[y][i]))
				i++;
		}
		i++;
	}
	if (!(i > 0 && map->content[y][i - 1] == '-'))
		result = -1 * result;
	return (result);
}

t_line	*c_ln(t_map *map, t_point *start, t_point *end, t_params *p)
{
	t_line	*line;
	int		z;
	int		ez;

	z = get_z_at_map_coordinates(map, start->x, start->y);
	ez = get_z_at_map_coordinates(map, end->x, end->y);
	start->z = p->z_scale * z;
	end->z = p->z_scale * ez;
	start->x = p->x_scale * start->x;
	start->y = p->y_scale * start->y;
	end->x = p->x_scale * end->x;
	end->y = p->y_scale * end->y;
	line = new_line(start, end);
	return (line);
}

t_line	**create_lines(t_params *p, int i, int j)
{
	t_line	**m;
	int		l;
	int		digits;

	l = 0;
	m = (t_line **)malloc(sizeof(t_line *) * (count_links(p->map) + 1));
	m[count_links(p->map)] = NULL;
	i = 0;
	while (i < p->map->height)
	{
		j = 0;
		digits = cnt_dgts(p->map->content[i]);
		while (j < digits)
		{
			if (j < digits - 1)
				m[l++] = c_ln(p->map, new_p(j, i, 0), new_p(j + 1, i, 0), p);
			if (i < p->map->height - 1 && j < cnt_dgts(p->map->content[i + 1]))
				m[l++] = c_ln(p->map, new_p(j, i, 0), new_p(j, i + 1, 0), p);
			j++;
		}
		i++;
	}
	return (m);
}

void	free_all_lines(t_line **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		line_del(lines[i]);
		i++;
	}
	free(lines);
}
