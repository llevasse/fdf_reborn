/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:49:54 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/09 10:33:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	free(data->point);
	free_tab(data->line);
	data->win_ptr = NULL;
	return (0);
}

void	reset_angle_pos(t_data *data)
{
	data->angle_x = check_angle(45);
	data->angle_y = check_angle(-35);
	data->angle_z = check_angle(30);
	data->zoom = 1000 / data->nb_column;
	data->beg_x = WINDOW_WIDTH / 2;
	data->beg_y = WINDOW_HEIGHT / 2;
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		return (close_window(data), 0);
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
	if (keysym == XK_p)
		print_info(*data);
	if (keysym == XK_l)
		print_line(*data);
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
		reset_angle_pos(data);
	reset_img(data);
	project(data);
	return (0);
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
			0);
}

int	render(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	project(data);
	return (0);
}

void	print_line(t_data data)
{
	data.line -= data.nb_point;
	while (*data.line)
		ft_printf(" %s", *data.line++);
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

int	main(int argc, char *argv[])
{
	t_data	data;
	int		fd;

	if (argc == 1)
		return (1);
	fd = open(argv[1], O_RDONLY);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"fdf");
	if (!data.win_ptr)
		return (free(data.win_ptr), 1);
	data.angle_x = check_angle(45);
	data.angle_y = check_angle(-35);
	data.angle_z = check_angle(30);
/* 	data.angle_x = check_angle(0);
	data.angle_y = check_angle(0);
	data.angle_z = check_angle(0);
 */	data.nb_column = 0;
	data.nb_row = 0;
	init_points(&data, fd);
	set_highest_n_lowest_z(&data);
	set_colour(&data);
	data.zoom = 1000 / data.nb_column;
	data.beg_x = WINDOW_WIDTH / 2;
	data.beg_y = WINDOW_HEIGHT / 2;
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
// angle iso x = 45 y = -35 z = 30
