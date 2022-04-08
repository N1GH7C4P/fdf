/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:02:10 by kpolojar          #+#    #+#             */
/*   Updated: 2022/04/08 03:29:26 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_W 1024
# define WINDOW_H 768
# define MAX_W 150
# define MAX_H 150
# define X_SCALE 5
# define Y_SCALE 5
# define Z_SCALE 7
# define ANGLE -1.57
# define X_OFFSET 250
# define Y_OFFSET 200
# define ZOOM_FACTOR 1.5
# define COLOR 0
# define MOVE_FACTOR 50
# define PROJECTION_DELTA_FACTOR 0.1
# define BG_COLOR 0xABCDEF
# define BUFF_SIZE 480000

// mlx
# include "./mlx_linux.h"
// math
# include <math.h>
// open
# include <fcntl.h>

// Point

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

t_point		*new_p(float x, float y, float z);
void		print_point(t_point *p);

// Line

typedef struct s_line
{
	t_point	*start;
	t_point	*end;
}	t_line;

t_line		*new_line(t_point *start, t_point *end);
void		line_del(t_line *line);
void		print_all_lines(t_line **lines);
int			cnt_dgts(char *line);

// Map

typedef struct s_map
{
	char	**content;
	int		width;
	int		height;
}	t_map;

t_map		*new_map(char **content, int nb_of_lines);
void		print_map(t_map *map);
void		free_map(t_map *map);

// Draw params

typedef struct s_params
{
	t_map	*map;
	t_line	**lines;
	void	*mlx;
	void	*win;
	int		x_scale;
	int		y_scale;
	int		z_scale;
	int		color;
	int		x_offset;
	int		y_offset;
	float	n;
}	t_params;

t_params	*new_params(void);
void		free_params(t_params *p);

// Window
void		*init_window(void *mlx);

// Graphics
void		draw_all_lines(t_params *p, int i);
void		draw_line(double d_x, double d_y, t_point *start, t_params *p);
void		set_background_color(t_params *p, int colour);
t_line		**create_lines(t_params *p, int i, int j);
void		free_all_lines(t_line **lines);

// Projection
int			iso_x(t_point *p, float angle);
int			iso_y(t_point *p, float angle);

// Controls
void		zoom_in(float scale_factor, t_params *p);
void		zoom_out(float scale_factor, t_params *p);
void		move_projection(int dx, int dy, t_params *p);
void		flatten_projection(float scale_factor, t_params *p);
void		raise_projection(float scale_factor, t_params *p);
void		change_projection(float d, t_params *p);
void		exit_fdf(t_params *p);

#endif