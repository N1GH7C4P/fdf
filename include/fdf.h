/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:02:10 by kpolojar          #+#    #+#             */
/*   Updated: 2022/04/05 03:39:22 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ISOMETRIC_MODE 1
# define WINDOW_W 1024
# define WINDOW_H 768
# define MAX_W 150
# define MAX_H 150
# define X_SCALE 30
# define Y_SCALE 30
# define Z_SCALE 3
# define ANGLE -1.57
# define X_OFFSET 200
# define Y_OFFSET 300
# define COLOR 0x44AA55
# define BUFF_SIZE 480000

// Mlx
# include "../include/mlx_linux.h"
// Math
# include <math.h>
// Open
# include <fcntl.h>

// Draw params

typedef struct s_params
{
	void	*mlx;
	void	*win;
	int		color;
}	t_params;

t_params	*new_params(int color);

// Map

typedef struct s_map
{
	char	**content;
	int		width;
	int		height;
}	t_map;

t_map		*new_map(char **content, int nb_of_lines);
void		print_map(t_map *map);

// Point

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

t_point		*new_point(float x, float y, float z);

// Line

typedef struct s_line
{
	t_point	*start;
	t_point	*end;
}	t_line;

t_line		*new_line(t_point *start, t_point *end);
void		line_del(t_line *line);
void		print_all_lines(t_line **lines);

// Window
void		*init_window(void *mlx);

// Graphics
void		draw_all_lines_from_top(t_line **lines, t_params *p, int i);
void		draw_all_lines_isometrically(t_line **lines, t_params *p, int i);
void		draw_line(double d_x, double d_y, t_point *start, t_params *p);
t_line		**create_lines(t_map *map, int l, int i, int j);

// Projection
int			toiso_x(t_point *p, float angle);
int			toiso_y(t_point *p, float angle);
int			totop_x(t_point *p, float angle);
int			totop_y(t_point *p, float angle);

#endif