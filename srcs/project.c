/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:37:51 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/13 17:32:54 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/// @brief Refresh the map's values and the display.
/// @param *data Pointr to the Data Struct containing map's data.
void	project(t_data *data)
{
	int		i;

	get_bis(data);
	i = 0;
	reset_point_ptr(data);
	while (data->point->point_id != (data->nb_point - 1))
	{
		if ((data->point + 1)->x != 0)
			draw_line(set_line_data(*data->point, *(data->point + 1)),
				&data->img);
		if (i < data->nb_point - data->nb_column)
			draw_line(set_line_data(*data->point, *(data->point
						+ data->nb_column)), &data->img);
		data->point++;
		i++;
	}
	reset_point_ptr(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
}

/// @brief Put a pixel at X:Y location on an image.
/// @param *img Point to img struct to put pixel on,
/// @param x Int to the horizontal value to print on,
/// @param y Int to the vertical value to print on,
/// @param colour Int value of the colour to print.
void	img_pix_put(t_img *img, int x, int y, int colour)
{
	char	*pixel;
	int		i;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel = (colour >> i) & 0xFF;
		else
			*pixel = (colour >> (img->bpp - 8 - i)) & 0xff;
		pixel++;
		i -= 8;
	}
}
