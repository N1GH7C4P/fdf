/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:01:15 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 03:01:32 by linuxlite        ###   ########.fr       */
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
		if (ft_isdigit(map->content[y][i]))
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

static t_line	*c_ln(t_map *map, t_point *start, t_point *end)
{
	t_line	*line;
	int		z;
	int		ez;

	z = get_z_at_map_coordinates(map, start->x, start->y);
	ez = get_z_at_map_coordinates(map, end->x, end->y);
	start->z = Z_SCALE * z;
	end->z = Z_SCALE * ez;
	start->x = X_SCALE * start->x;
	start->y = Y_SCALE * start->y;
	end->x = X_SCALE * end->x;
	end->y = Y_SCALE * end->y;
	line = new_line(start, end);
	return (line);
}

t_line	**create_lines(t_map *map, int l, int i, int j)
{
	t_line	**m;

	m = (t_line **)malloc(sizeof(t_line *) * (count_links(map) + 1));
	m[count_links(map)] = NULL;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (j < map->width - 1)
				m[l++] = c_ln(map, new_point(j, i, 0), new_point(j + 1, i, 0));
			if (i < map->height - 1)
				m[l++] = c_ln(map, new_point(j, i, 0), new_point(j, i + 1, 0));
			j++;
		}
		i++;
	}
	return (m);
}

void	print_all_lines(t_line **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		ft_putstr("line: ");
		ft_putnbr(i);
		ft_putstr(" start: ");
		ft_putstr("(");
		ft_putnbr(lines[i]->start->x);
		ft_putstr(", ");
		ft_putnbr(lines[i]->start->y);
		ft_putstr(", ");
		ft_putnbr(lines[i]->start->z);
		ft_putstr(")");
		ft_putstr(" end: ");
		ft_putstr("(");
		ft_putnbr(lines[i]->end->x);
		ft_putstr(", ");
		ft_putnbr(lines[i]->end->y);
		ft_putstr(", ");
		ft_putnbr(lines[i]->end->z);
		ft_putendl(")");
		i++;
	}
}
