/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:49:54 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/24 21:47:20 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	close_window(t_data *data)
{
	free(data->point);
	if (data->line)
		free_tab(data->line);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->win_ptr = NULL;
	return (0);
}

int	render(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	reset_img(data);
	project(data);
	return (0);
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

int	init_data(t_data *data, int fd)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"fdf");
	if (!data->win_ptr)
		return (free(data->win_ptr), 1);
	data->angle_x = 45;
	data->angle_y = -35;
	data->angle_z = 30;
	data->nb_column = 0;
	data->nb_row = 0;
	data->z_amplifier = 1;
	init_points(data, fd);
	set_highest_n_lowest_z(data);
	set_colour(data);
	data->bg = init_colour(0, 0, 0, 0);
	data->zoom = 1000 / data->nb_column;
	data->beg_x = WINDOW_WIDTH / 2;
	data->beg_y = WINDOW_HEIGHT / 2;
	data->dif_x = 0;
	data->dif_y = 0;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		fd;

	if (argc == 1 || (!ft_strnstr(argv[1], ".fdf",
				ft_strlen(argv[1]))))
		return (ft_printf("Missing .fdf file\n"));
	data.point = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Invalid .fdf file.\nExited with error code : %d\n", errno);
		return (*__errno_location());
	}
	if (init_data(&data, fd))
		return (1);
	close(fd);
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
