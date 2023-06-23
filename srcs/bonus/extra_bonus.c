/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:03:35 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/23 14:09:44 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	reset_setting(t_data *data)
{
	data->angle_x = check_angle(45);
	data->angle_y = check_angle(-35);
	data->angle_z = check_angle(30);
	data->zoom = 1000 / data->nb_column;
	data->beg_x = WINDOW_WIDTH / 2;
	data->beg_y = WINDOW_HEIGHT / 2;
	data->dif_x = 0;
	data->dif_y = 0;
}

void	print_line(t_data data)
{
	int	i;

	i = 0;
	while (*data.line)
	{
		ft_printf("|%s", *data.line++);
		if (i++ == data.nb_column)
		{
			i = 0;
			ft_printf("|\n");
		}
	}
}

void	print_info(t_data data)
{
	ft_printf("rotation : {x : %i}, {y : %i}, {z : %i}\n", (int)data.angle_x,
		(int)data.angle_y, (int)data.angle_z);
	while (data.point->point_id != data.nb_point)
	{
		ft_printf("{%i.%i.%i.%i} ", (int)data.point->x, (int)data.point->y,
			(int)data.point->z, data.point->colour);
		data.point++;
		if (data.point->x == 0)
			ft_printf("\n");
	}
	ft_printf("\ncenter position : {%i.%i} (%i.%i)\n", (int)data.point->x_bis,
		(int)data.point->y_bis, (int)data.point->x, (int)data.point->y);
	ft_printf("center screen : {%i.%i}\n", WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	ft_printf("beg_x : %i | beg_y %i\n", (int)data.beg_x, (int)data.beg_y);
}

void	reset_img(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!data->win_ptr)
		return ;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			img_pix_put(&data->img, x++, y, 0x000000);
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
}
