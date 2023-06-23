/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:36:54 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/23 13:07:14 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	angle_input(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->angle_y = check_angle(data->angle_y + 1);
	if (keysym == XK_Right)
		data->angle_y = check_angle(data->angle_y - 1);
	if (keysym == XK_Up)
		data->angle_x = check_angle(data->angle_x + 1);
	if (keysym == XK_Down)
		data->angle_x = check_angle(data->angle_x - 1);
	if (keysym == XK_e)
		data->angle_z = check_angle(data->angle_z + 1);
	if (keysym == XK_q)
		data->angle_z = check_angle(data->angle_z - 1);
	if (keysym == XK_z)
	{
		if (data->is_wireframe == 1)
			data->is_wireframe = 0;
		else
			data->is_wireframe = 1;
	}
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

int	handle_mouse_input(int button, int x, int y, t_data *data)
{
	t_colour	colour;

	colour = init_colour(get_pixel_color(&data->img, x, y), 0, 0, 0);
	ft_printf("click on x : %i y : %i with button %i\n", x, y, button);
	ft_printf("r : %i, g : %i, b : %i\n", colour.r, colour.g, colour.b);
	data->button.click_x = x;
	data->button.click_y = y;
	(void)data;
	return (0);
}

int	button1_motion(int x, int y, t_data *data)
{
	ft_printf("x %i\n", x);
	ft_printf("y %i\n", y);
	if (data->button.click_x != 0 || data->button.click_y != 0)
	{
		if (x > data->button.click_x)
			data->dif_x += 1;
		else
			data->dif_x -= 1;
		if (y > data->button.click_y)
			data->dif_y += 1;
		else
			data->dif_y -= 1;
	}
	data->button.click_x = x;
	data->button.click_y = y;
	ft_printf("dif x : %i | dif y : %i\n", data->dif_x, data->dif_y);
	reset_img(data);
	project(data);
	return (0);
}
int	button3_motion(int x, int y, t_data *data)
{
	ft_printf("x %i\n", x);
	ft_printf("y %i\n", y);
	if ((data->button.click_x != 0 || data->button.click_y != 0) && (x % 10 == 0
			|| y % 10 == 0))
	{
		if (x > data->button.click_x)
			data->angle_y = check_angle(data->angle_y + 5);
		else
			data->angle_y = check_angle(data->angle_y - 5);
		if (y > data->button.click_y)
			data->angle_x = check_angle(data->angle_x + 5);
		else
			data->angle_x = check_angle(data->angle_x - 5);
	}
	data->button.click_x = x;
	data->button.click_y = y;
	ft_printf("dif x : %i | dif y : %i\n", data->dif_x, data->dif_y);
	reset_img(data);
	project(data);
	return (0);
}