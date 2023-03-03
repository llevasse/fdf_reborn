/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:58:01 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/03 15:42:32 by llevasse         ###   ########.fr       */
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
	float	x;			//nb in column
	float	y;			//nb in row
	float	z;
	float	x_bis;
	float	y_bis;
	float	z_bis;
}			t_point;

typedef struct s_data
{
	t_point	*point;
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		nb_column;
	int		nb_row;
	char	**line;
	float	angle_x;
	float	angle_y;
	float	angle_z;
}			t_data;

/* fdf.c */


/* point.c */
void	init_points(t_data *data, int fd);
char	**get_line(int fd, int *nb_row, int *nb_column);

#endif