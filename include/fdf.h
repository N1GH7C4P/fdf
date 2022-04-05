/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:02:10 by kpolojar          #+#    #+#             */
/*   Updated: 2022/04/05 19:45:05 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_W 1024
# define WINDOW_H 768
# define MAX_W 150
# define MAX_H 150
# define X_SCALE 20
# define Y_SCALE 20
# define Z_SCALE 5
# define ANGLE -1.57
# define X_OFFSET 100
# define Y_OFFSET 100
# define COLOR 0
# define BG_COLOR 0xABCDEF
# define BUFF_SIZE 480000

// mlx
# include "../include/mlx.h"
// math
# include <math.h>
// open
# include <fcntl.h>

// Map

typedef struct s_map
{
	char	**content;
	int		width;
	int		height;
}	t_map;

t_map		*new_map(char **content, int nb_of_lines);
void		print_map(t_map *map);

// Draw params

typedef struct s_params
{
	void	*mlx;
	void	*win;
	int		x_scale;
	int		y_scale;
	int		z_scale;
	int		color;
	int		x_offset;
	int		y_offset;
	int		map_height;
	int		map_width;
	float	n;
}	t_params;

t_params	*new_params(t_map *map);

// Point

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

t_point		*new_pnt(float x, float y, float z);

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
void		draw_all_lines(t_line **lines, t_params *p, int i);
void		draw_line(double d_x, double d_y, t_point *start, t_params *p);
void		set_background_color(t_params *p, int colour);
t_line		**create_lines(t_map *map, t_params *p, int i, int j);

// Projection
int			toiso_x(t_point *p, float angle);
int			toiso_y(t_point *p, float angle);

#endif