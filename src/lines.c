/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:01:15 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 19:45:17 by kpolojar         ###   ########.fr       */
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

t_line	**create_lines(t_map *map, t_params *p, int i, int j)
{
	t_line	**m;
	int		l;

	l = 0;
	m = (t_line **)malloc(sizeof(t_line *) * (count_links(map) + 1));
	m[count_links(map)] = NULL;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (j < map->width - 1)
				m[l++] = c_ln(map, new_pnt(j, i, 0), new_pnt(j + 1, i, 0), p);
			if (i < map->height - 1)
				m[l++] = c_ln(map, new_pnt(j, i, 0), new_pnt(j, i + 1, 0), p);
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
