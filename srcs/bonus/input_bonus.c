/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:36:54 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/02 13:06:55 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	angle_input(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->angle_y = no_higher(data->angle_y + Y_ROT, 360, 0);
	if (keysym == XK_Right)
		data->angle_y = no_higher(data->angle_y - Y_ROT, 360, 0);
	if (keysym == XK_Up)
		data->angle_x = no_higher(data->angle_x + X_ROT, 360, 0);
	if (keysym == XK_Down)
		data->angle_x = no_higher(data->angle_x - X_ROT, 360, 0);
	if (keysym == XK_e)
		data->angle_z = no_higher(data->angle_z + Z_ROT, 360, 0);
	if (keysym == XK_q)
		data->angle_z = no_higher(data->angle_z - Z_ROT, 360, 0);
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		return (close_window(data), 0);
	if (keysym == XK_p)
		return (print_info(*data), 0);
	if (keysym == XK_KP_Add)
		data->zoom *= 1.10;
	if (keysym == XK_KP_Subtract)
		data->zoom *= 0.90;
	if (keysym == XK_a)
		data->beg_x -= X_VELOCITY * data->zoom;
	if (keysym == XK_d)
		data->beg_x += X_VELOCITY * data->zoom;
	if (keysym == XK_s)
		data->beg_y += Y_VELOCITY * data->zoom;
	if (keysym == XK_w)
		data->beg_y -= Y_VELOCITY * data->zoom;
	if (keysym == XK_r)
		reset_setting(data);
	if (keysym == XK_x)
		data->z_amplifier -= 0.10;
	if (keysym == XK_c)
		data->z_amplifier += 0.10;
	return (angle_input(keysym, data));
}

/// @brief Close and free everything.
/// @param *data Pointer to a data structur containing the map's info.
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	free(data->point);
	if (data->line)
		free_tab(data->line);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
