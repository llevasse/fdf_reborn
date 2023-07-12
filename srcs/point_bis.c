/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:17:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/12 17:06:35 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/// @brief Assign point's coordinate for 2d image.
/// @param data Data structur containing map's info.
void	get_bis(t_data *data)
{
	while (data->point->point_id != 0)
		data->point--;
	while (data->point->point_id != data->nb_row * data->nb_column)
	{
		set_bis_point(data);
		printf("Assigning point x:%.0f y:%.0f z:%.0f | x:%.0f y:%.0f z:%.0f\n", data->point->x, data->point->y, data->point->z, data->point->x_bis, data->point->y_bis, data->point->z_bis);
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

/// @brief Assign coordinate to one point for 2d image.
/// @param data Data structur containing map's info.
void	set_bis_point(t_data *data)
{
	data->point->x_bis = data->dif_x + (data->point->x * data->zoom)
		+ (data->beg_x - (data->zoom * (data->nb_column - 1) / 2));
	data->point->y_bis = data->dif_y + (data->point->y * data->zoom)
		+ (data->beg_y - (data->zoom * (data->nb_row - 1) / 2));
	data->point->z_bis = (data->point->z * data->z_amplifier) * data->zoom;
	get_matrix_point(data, *data->point, &data->point->x_bis,
		&data->point->y_bis);
	data->point->x_bis += data->dif_x;
	data->point->y_bis += data->dif_y;
	data->point->x_bis = no_higher_double(data->point->x_bis, 2147483647.0, -2147483648.0);
	data->point->y_bis = no_higher_double(data->point->y_bis, 2147483647.0, -2147483648.0);
	data->point->z_bis = no_higher_double(data->point->z_bis, 2147483647.0, -2147483648.0);
}

double	no_higher_double(double nb, double highest, double lowest)
{
	if (nb <= lowest)
		return (lowest);
	if (nb >= highest)
		return (highest);
	return (nb);
}
