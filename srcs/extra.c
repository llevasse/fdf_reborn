/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:03:35 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/01 11:17:41 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
}
