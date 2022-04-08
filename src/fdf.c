/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:32:23 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/08 03:30:16 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

void	error(int code)
{
	if (code == 1)
		ft_putendl("usage: executable mapfile.fdf");
	else if (code == 2)
		ft_putendl("invalid file");
	exit(-1);
}

static int	key_hook(int keycode, t_params *p)
{
	if (keycode == 65307 || keycode == 53)
		exit_fdf(p);
	else if (keycode == 65363)
		move_projection(MOVE_FACTOR, 0, p);
	else if (keycode == 65361)
		move_projection(-MOVE_FACTOR, 0, p);
	else if (keycode == 65362)
		move_projection(0, -MOVE_FACTOR, p);
	else if (keycode == 65364)
		move_projection(0, MOVE_FACTOR, p);
	else if (keycode == 97)
		change_projection(PROJECTION_DELTA_FACTOR, p);
	else if (keycode == 100)
		change_projection(-PROJECTION_DELTA_FACTOR, p);
	else if (keycode == 119)
		zoom_in(ZOOM_FACTOR, p);
	else if (keycode == 115)
		zoom_out(ZOOM_FACTOR, p);
	else if (keycode == 120)
		raise_projection(ZOOM_FACTOR, p);
	else if (keycode == 122)
		flatten_projection(ZOOM_FACTOR, p);
	return (0);
}

static t_map	*parse_file(int fd, int ret, int i)
{
	char	**lines;
	char	*buff;
	t_map	*map;

	ret = ft_get_next_line(fd, &buff);
	if (ret < 1 || !buff[0])
		error(2);
	lines = (char **)malloc(sizeof(char *) * (MAX_H + 1));
	while (i < MAX_H && ret > 0 && buff[0])
	{
		if (cnt_dgts(buff) < 1)
			error(2);
		lines[i++] = buff;
		ret = ft_get_next_line(fd, &buff);
	}
	lines[i] = NULL;
	map = new_map(lines, i);
	ft_free_array(lines);
	return (map);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_params	*params;

	if (argc != 2)
		error(1);
	fd = open(argv[argc - 1], O_RDONLY);
	params = new_params();
	params->map = parse_file(fd, 0, 0);
	set_background_color(params, BG_COLOR);
	params->lines = create_lines(params, 0, 0);
	draw_all_lines(params, 0);
	mlx_key_hook(params->win, key_hook, params);
	mlx_loop(params->mlx);
	free_params(params);
	exit (0);
}
