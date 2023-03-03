/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:49:54 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/03 15:42:29 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->win_ptr = NULL;
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	return (0);
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
	data.angle_x = 45;
	data.angle_y = -35;
	data.angle_z = 30;
	data.nb_column = 0;
	data.nb_row = 0;
	init_points(&data, fd);
	data.img.addr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	(void)fd;
}
// angle iso x = 45 y = -35 z = 30
