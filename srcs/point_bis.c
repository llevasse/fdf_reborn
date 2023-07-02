/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:17:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/02 09:10:57 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_bis(t_data *data)
{
	float	temp_z;

	while (data->point->point_id != 0)
		data->point--;
	while (data->point->point_id != data->nb_row * data->nb_column)
	{
		temp_z = data->point->z;
		data->point->z_bis = 0;
		set_bis_point(data);
		data->point->z = temp_z;
		data->point->z_bis = (data->point->z * data->z_amplifier) * data->zoom;
		set_bis_matrix(data);
		data->point++;
	}
	data->point->x_bis = (data->point->x * data->zoom)
		+ (data->beg_x - (data->zoom * (data->nb_column - 1)) / 2);
	data->point->y_bis = (data->point->y * data->zoom)
		+ (data->beg_y - (data->zoom * (data->nb_row - 1)) / 2);
	data->point->z_bis = data->point->z * data->zoom;
	get_matrix_point(data, *data->point, &data->point->x_bis,
		&data->point->y_bis);
	while (data->point->point_id != 0)
		data->point--;
}

void	set_bis_point(t_data *data)
{
	data->point->x_bis = data->dif_x + (data->point->x * data->zoom)
		+ (data->beg_x - (data->zoom * (data->nb_column - 1) / 2));
	data->point->y_bis = data->dif_y + (data->point->y * data->zoom)
		+ (data->beg_y - (data->zoom * (data->nb_row - 1) / 2));
}

void	set_bis_matrix(t_data *data)
{
	get_matrix_point(data, *data->point, &data->point->x_bis,
		&data->point->y_bis);
	data->point->x_bis += data->dif_x;
	data->point->y_bis += data->dif_y;
}
