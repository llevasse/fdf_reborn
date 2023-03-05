/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:58:01 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/05 10:44:48 by llevasse         ###   ########.fr       */
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
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_point
{
	float x; //nb in column
	float y; //nb in row
	float	z;
	float	x_bis;
	float	y_bis;
	float	z_bis;
	int		point_id;
}			t_point;

typedef struct s_data
{
	t_point	*point;
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		nb_column;
	int		nb_row;
	int		nb_point;
	char	**line;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	zoom;
	float	beg_x;
	float	beg_y;
}			t_data;

/* fdf.c */
void		print_line(t_data data);
void		print_info(t_data data);
void		reset_img(t_data *data);
/* point.c */
void		init_points(t_data *data, int fd);
char		**get_line(int fd, int *nb_row, int *nb_column);
void		get_bis(t_data *data);
void		reset_ptr_point(t_data *data);

/* matrix */
float		**init_matrix_x(t_data data);
float		**init_matrix_y(t_data data);
float		**init_matrix_z(t_data data);
void		get_matrix_point(t_data *data, t_point point, float *x, float *y);
void		free_matrix(float **matrix_x, float **matrix_y, float **matrix_z);
float		*multiply_matrix(float **matrix, float *matrix_point);

/* project.c */
void		project(t_data *data);
void		draw_line(t_data data, t_point p_a, t_point p_b, t_img *img);
void		img_pix_put(t_img *img, int x, int y, int color);

#endif