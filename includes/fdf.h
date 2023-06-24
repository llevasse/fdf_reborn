/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:58:01 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/24 21:48:00 by llevasse         ###   ########.fr       */
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
# include <errno.h>

/* 720p */
//# define WINDOW_WIDTH 1280
//# define WINDOW_HEIGHT 720

/* 1080p */
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define PI 3.1415926535
# define RADIAN 0.017453292519444445

typedef struct s_img
{
	void				*mlx_img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
}						t_img;

typedef struct s_point
{
	float				x;
	float				y;
	float				z;
	float				x_bis;
	float				y_bis;
	float				z_bis;
	float				x_bis_no_z;
	float				y_bis_no_z;
	int					point_id;
}						t_point;

typedef struct s_data
{
	t_point				*point;
	t_img				img;
	void				*mlx_ptr;
	void				*win_ptr;
	int					nb_column;
	int					nb_row;
	int					nb_point;
	char				**line;
	float				angle_x;
	float				angle_y;
	float				angle_z;
	float				zoom;
	float				beg_x;
	float				beg_y;
	float				lowest_z;
	float				highest_z;
	float				z_amplifier;
	int					dif_x;
	int					dif_y;
}						t_data;

typedef struct s_line
{
	t_point				p_a;
	t_point				p_b;
	float				len;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					error;
	int					e2;
	int					i;
	float				x;
	float				y;
}						t_line;

/* fdf.c */
void					print_line(t_data data);
void					print_info(t_data data);
void					reset_img(t_data *data);
void					reset_setting(t_data *data);
int						close_window(t_data *data);

/* input.c */
int						handle_input(int keysym, t_data *data);
int						handle_mouse_input(int button, int x, int y,
							t_data *data);
int						button1_motion(int x, int y, t_data *data);
int						button3_motion(int x, int y, t_data *data);

/* point.c */
void					init_points(t_data *data, int fd);
char					**get_line(int fd, int *nb_row, int *nb_column);
void					reset_point_ptr(t_data *data);
void					set_points(t_data *data);

/* point_bis.c */
void					get_bis(t_data *data);
void					set_bis_point(t_data *data);
void					set_bis_matrix(t_data *data);

/* matrix */
float					**init_matrix_x(t_data data);
float					**init_matrix_y(t_data data);
float					**init_matrix_z(t_data data);
void					get_matrix_point(t_data *data, t_point point, float *x,
							float *y);
void					free_all_matrix(float *matrix_point, float **matrix_x,
							float **matrix_y, float **matrix_z);
void					free_matrix(float **matrix);
float					*multiply_matrix(float **matrix, float *matrix_point,
							t_data *data);

/* project.c */
void					project(t_data *data);
void					draw_line(t_line line, t_img *img);
void					img_pix_put(t_img *img, int x, int y, int colour);
float					check_angle(float angle);
t_line					set_line_data(t_point p_a, t_point p_b);
void					move_forward(t_line *line);

void					print_lines(char **lines, int col, int rows);

#endif