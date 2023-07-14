/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:58:01 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/14 11:16:05 by llevasse         ###   ########.fr       */
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
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

/* 1080p */
//# define WINDOW_WIDTH 1920
//# define WINDOW_HEIGHT 1080

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
	double				x;
	double				y;
	double				z;
	double				x_bis;
	double				y_bis;
	double				z_bis;
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
	double				angle_x;
	double				angle_y;
	double				angle_z;
	double				zoom;
	double				beg_x;
	double				beg_y;
	double				lowest_z;
	double				highest_z;
	double				z_amplifier;
	int					dif_x;
	int					dif_y;
}						t_data;

typedef struct s_line
{
	t_point				p_a;
	t_point				p_b;
	double				len;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					error;
	int					e2;
	int					i;
	double				x;
	double				y;
}						t_line;

/* fdf.c */
void					print_line(t_data data);
void					print_info(t_data data);
void					paint_it_black(t_data *data);
void					reset_setting(t_data *data);
int						close_window(t_data *data);

/* init.c */
int						init_data(t_data *data, int fd);
void					free_data(t_data *data, int fd);
void					init_null(t_data *data);

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
void					no_higher_double(double *nb,
							double highest, double lowest);

/* matrix */
double					**init_matrix_x(t_data data);
double					**init_matrix_y(t_data data);
double					**init_matrix_z(t_data data);
void					get_matrix_point(t_data *data, t_point point, double *x,
							double *y);
void					free_all_matrix(double *matrix_point, double **matrix_x,
							double **matrix_y, double **matrix_z);
void					free_matrix(double **matrix);
double					*multiply_matrix(double **matrix, double *matrix_point,
							t_data *data);

/* project.c */
void					project(t_data *data);
void					img_pix_put(t_img *img, int x, int y, int colour);

/* line.c */
void					draw_line(t_line line, t_img *img);
t_line					set_line_data(t_point p_a, t_point p_b);
void					move_forward(t_line *line);
int						is_out_of_bound(t_point point);

#endif
