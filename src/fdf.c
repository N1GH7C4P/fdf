/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:32:23 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 03:25:24 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

static t_map	*parse_file(int fd, int ret, int i)
{
	char	**lines;
	char	*buff;
	t_map	*map;

	lines = (char **)malloc(sizeof(char *) * MAX_H + 1);
	i = 0;
	ret = 1;
	while (i < MAX_H)
	{
		buff = ft_strnew(MAX_W);
		ret = ft_get_next_line(fd, &buff);
		lines[i] = ft_strdup(buff);
		if (ret < 1)
			break ;
		i++;
	}
	free(buff);
	lines[i++] = NULL;
	map = new_map(lines, (i - 1));
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
	return (map);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_params	*params;
	t_map		*map;
	t_line		**lines;

	if (argc != 2)
	{
		ft_putendl("ARGUMENT ERROR");
		return (-1);
	}
	fd = open(argv[argc - 1], O_RDONLY);
	map = parse_file(fd, 0, 0);
	print_map(map);
	params = new_params(COLOR);
	lines = create_lines(map, 0, 0, 0);
	print_all_lines(lines);
	if (ISOMETRIC_MODE)
		draw_all_lines_isometrically(lines, params, 0);
	else
		draw_all_lines_from_top(lines, params, 0);
	mlx_loop(params->mlx);
	return (0);
}
