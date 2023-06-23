/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:36:54 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/23 17:04:01 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	angle_input(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->angle_y = no_higher(data->angle_y + 1, 360, 0);
	if (keysym == XK_Right)
		data->angle_y = no_higher(data->angle_y - 1, 360, 0);
	if (keysym == XK_Up)
		data->angle_x = no_higher(data->angle_x + 1, 360, 0);
	if (keysym == XK_Down)
		data->angle_x = no_higher(data->angle_x - 1, 360, 0);
	if (keysym == XK_e)
		data->angle_z = no_higher(data->angle_z + 1, 360, 0);
	if (keysym == XK_q)
		data->angle_z = no_higher(data->angle_z - 1, 360, 0);
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		return (close_window(data), 0);
	if (keysym == XK_KP_Add)
		data->zoom *= 1.10;
	if (keysym == XK_KP_Subtract)
		data->zoom *= 0.90;
	if (keysym == XK_a)
		data->beg_x -= 10;
	if (keysym == XK_d)
		data->beg_x += 10;
	if (keysym == XK_s)
		data->beg_y += 10;
	if (keysym == XK_w)
		data->beg_y -= 10;
	if (keysym == XK_r)
		reset_setting(data);
	if (keysym == XK_x)
		data->z_amplifier -= 0.10;
	if (keysym == XK_c)
		data->z_amplifier += 0.10;
	return (angle_input(keysym, data));
}
