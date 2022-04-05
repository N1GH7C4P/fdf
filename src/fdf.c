/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:32:23 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/05 19:44:05 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fdf.h"

static int	key_hook(int keycode)
{
	if (keycode == 53)
	{
		ft_putendl("Exiting FDF");
		exit(1);
	}
	return (0);
}

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
	return (0);
}
