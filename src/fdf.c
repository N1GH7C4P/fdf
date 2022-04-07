/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:32:23 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/07 02:36:18 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

static int	key_hook(int keycode)
{
	ft_putnbr(keycode);
	if (keycode == 53 || keycode == 65307)
	{
		ft_putendl("Exiting FDF");
		exit (0);
	}
	return (0);
}

static t_map	*parse_file(int fd, int ret, int i)
{
	char	**lines;
	char	*buff;
	t_map	*map;

	buff = ft_strnew(MAX_W);
	ret = ft_get_next_line(fd, &buff);
	if (ret < 1 || !buff[0])
		exit(-1);
	lines = (char **)malloc(sizeof(char *) * MAX_H + 1);
	while (i < MAX_H && ret > 0 && buff[0])
	{
		lines[i++] = ft_strdup(buff);
		ret = ft_get_next_line(fd, &buff);
	}
	free(buff);
	lines[i] = NULL;
	map = new_map(lines, (i - 1));
	while (lines[i--])
		free(lines[i]);
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
		ft_putendl("usage: ./fdf ./path/to/mapfile.fdf");
		exit(-1);
	}
	fd = open(argv[argc - 1], O_RDONLY);
	map = parse_file(fd, 0, 0);
	params = new_params(map);
	set_background_color(params, BG_COLOR);
	lines = create_lines(map, params, 0, 0);
	draw_all_lines(lines, params, 0);
	mlx_key_hook(params->win, key_hook, &params);
	mlx_loop(params->mlx);
	exit (0);
}
