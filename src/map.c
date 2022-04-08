/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:35:14 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/08 03:26:54 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

int	cnt_dgts(char *line)
{
	int	digits;
	int	i;

	digits = 0;
	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (ft_isdigit(line[i]) && line[i + 1] != 'x')
		{
			digits++;
			while (ft_isdigit(line[i]))
				i++;
			continue ;
		}
		i++;
	}
	return (digits);
}

t_map	*new_map(char **content, int nb_of_lines)
{
	t_map	*new_map;
	int		i;

	new_map = (t_map *)malloc(sizeof(t_map));
	new_map->content = (char **)malloc(sizeof(char *) * (nb_of_lines + 1));
	i = 0;
	while (i < nb_of_lines)
	{
		new_map->content[i] = ft_strdup(content[i]);
		i++;
	}
	new_map->width = cnt_dgts(content[0]);
	new_map->height = i;
	return (new_map);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height && map->content[i])
	{
		j = 0;
		while (map->content[i][j])
		{
			ft_putchar(map->content[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->height && map->content[i])
	{
		free(map->content[i]);
		i++;
	}
	free(map);
}
