/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:58:01 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/08 09:51:07 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

/* 720p */
//# define WINDOW_WIDTH 1280
//# define WINDOW_HEIGHT 720

/* 1080p */
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define PI 3.1415926535
# define RADIAN PI / 180
# define HIGHEST_R 255
# define HIGHEST_G 0
# define HIGHEST_B 255
# define LOWEST_R 0
# define LOWEST_G 255
# define LOWEST_B 0
# define BEG_R 255
# define BEG_G 255
# define BEG_B 0
# define ZERO_R 255
# define ZERO_G 255
# define ZERO_B 255
typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_colour
{
	int			r;
	int			g;
	int			b;
	int			hex;
}				t_colour;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	float		x_bis;
	float		y_bis;
	float		z_bis;
	int			point_id;
	t_colour	colour;
}				t_point;

typedef struct s_data
{
	t_point		*point;
	t_img		img;
	void		*mlx_ptr;
	void		*win_ptr;
	int			nb_column;
	int			nb_row;
	int			nb_point;
	char		**line;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	float		zoom;
	float		beg_x;
	float		beg_y;
	float		lowest_z;
	float		highest_z;
}				t_data;

typedef struct s_line
{
	t_point		p_a;
	t_point		p_b;
	float		len;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			error;
	int			e2;
	int			i;
}				t_line;

typedef struct polygon
{
	t_line left_line;
	t_line right_line;
	t_line up_line;
	t_line down_line;
}				t_polygon;

/* fdf.c */
void			print_line(t_data data);
void			print_info(t_data data);
void			reset_img(t_data *data);

/* point.c */
void			init_points(t_data *data, int fd);
char			**get_line(int fd, int *nb_row, int *nb_column);
void			get_bis(t_data *data);
void			reset_point_ptr(t_data *data);
void			set_colour(t_data *data);
/* matrix */
float			**init_matrix_x(t_data data);
float			**init_matrix_y(t_data data);
float			**init_matrix_z(t_data data);
void			get_matrix_point(t_data *data, t_point point, float *x,
					float *y);
void			free_matrix(float **matrix_x, float **matrix_y,
					float **matrix_z);
float			*multiply_matrix(float **matrix, float *matrix_point,
					t_data *data);

/* project.c */
void			project(t_data *data);
void			draw_line(t_data data, t_point p_a, t_point p_b, t_img *img);
void			img_pix_put(t_img *img, int x, int y, int color);
float			check_angle(float angle);
void			set_line_data(t_line *line, t_point p_a, t_point p_b);


/* colour.c */
int				get_rgb(int r, int g, int b);
int				hex2int(char byte);
t_colour		init_colour(int colour, int r, int g, int b);
t_colour		init_colour_from_str(const char *str);
unsigned int	get_colour(t_line line);

#endif