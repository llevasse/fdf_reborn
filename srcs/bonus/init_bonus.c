/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:18:58 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/02 13:06:55 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_highest_n_lowest_z(t_data *data)
{
	reset_point_ptr(data);
	data->lowest_z = 0;
	data->highest_z = 0;
	while (data->point->point_id != (data->nb_point - 1))
	{
		if (data->point->z > data->highest_z)
			data->highest_z = data->point->z;
		if (data->point->z < data->lowest_z)
			data->lowest_z = data->point->z;
		data->point++;
	}
}

int	init_data(t_data *data, int fd)
{
	init_null(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"fdf");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	data->angle_x = 45;
	data->angle_y = -35;
	data->angle_z = 30;
	data->nb_column = 0;
	data->nb_row = 0;
	data->z_amplifier = 1;
	init_points(data, fd);
	if (!data->point)
		return (free_data(data, fd), 1);
	set_highest_n_lowest_z(data);
	set_colour(data);
	data->zoom = 1000 / data->nb_column;
	data->beg_x = WINDOW_WIDTH / 2;
	data->beg_y = WINDOW_HEIGHT / 2;
	data->dif_x = 0;
	data->dif_y = 0;
	return (0);
}

void	init_null(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->point = NULL;
	data->line = NULL;
	data->img.mlx_img = NULL;
}

void	free_data(t_data *data, int fd)
{
	if (data->win_ptr)
		close_window(data);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	close(fd);
}
