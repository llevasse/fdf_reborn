/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:03:35 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/01 23:12:41 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/// @brief Reset map variables to default.
/// @param *data Pointer to data structur containing map's info.
void	reset_setting(t_data *data)
{
	data->angle_x = 45;
	data->angle_y = -35;
	data->angle_z = 30;
	data->zoom = 1000 / data->nb_column;
	data->beg_x = WINDOW_WIDTH / 2;
	data->beg_y = WINDOW_HEIGHT / 2;
	data->dif_x = 0;
	data->dif_y = 0;
}

/// @brief Print map's info.
/// @param data Data structur containing map's info.
void	print_info(t_data data)
{
	ft_printf("rotation : {x : %i}, {y : %i}, {z : %i}\n", (int)data.angle_x,
		(int)data.angle_y, (int)data.angle_z);
	while (data.point->point_id != data.nb_point)
	{
		ft_printf("{%i.%i.%i} ", (int)data.point->x, (int)data.point->y,
			(int)data.point->z);
		data.point++;
		if (data.point->x == 0)
			ft_printf("\n");
	}
	ft_printf("\ncenter position : {%i.%i} (point : %i.%i)\n",
		(int)data.point->x_bis,
		(int)data.point->y_bis, (int)data.point->x, (int)data.point->y);
	ft_printf("center screen : {%i.%i}\n", WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	ft_printf("beg_x : %i | beg_y %i\n", (int)data.beg_x, (int)data.beg_y);
}

/// @brief I see a red door,
/// And I want it painted black,
/// No colors anymore,
/// I want them to turn black,
/// I see the girls walk by,
/// Dressed in their summer clothes,
/// I have to turn my head,
/// Until my darkness goes,
/// I see a line of cars,
/// And they're all painted black,
/// With flowers and my love,
/// Both never to come back,
/// I've seen people turn their heads,
/// And quickly look away,
/// Like a newborn baby,
/// It just happens everyday,
/// I look inside myself,
/// And see my heart is black,
/// I see my red door,
/// I must have it painted black,
/// Maybe then, I'll fade away,
/// And not have to face the facts,
/// It's not easy facing up,
/// When your whole world is black,
/// No more will my green sea,
/// Go turn a deeper blue,
/// I could not foresee this thing,
/// Happening to you,
/// If I look hard enough,
/// Into the setting sun,
/// My love will laugh with me,
/// Before the morning comes,
/// I see a red door,
/// And I want it painted black,
/// No colors anymore,
/// I want them to turn black,
/// I see the girls walk by,
/// Dressed in their summer clothes,
/// I have to turn my head,
/// Until my darkness goes,
/// I wanna see it painted,
/// Painted black,
/// Black as night,
/// Black as coal,
/// I wanna see the sun,
/// Blotted out from the sky,
/// I wanna see it painted, painted, painted,
/// Painted black, yeah.
/// @param *data Pointer to structur cointaining map's data.
void	paint_it_black(t_data *data)
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
