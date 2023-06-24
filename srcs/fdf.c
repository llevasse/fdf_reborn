/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:49:54 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/24 22:19:12 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	render(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	reset_img(data);
	project(data);
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
