/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:53:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/05 10:37:21 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_points(t_data *data, int fd)
{
	int	x;
	int	y;

	data->line = get_line(fd, &data->nb_row, &data->nb_column);
	data->point = malloc(((data->nb_row * (data->nb_column + 1)) + 1)
			* sizeof(t_point));
	if (!data->point)
		return ;
	y = 0;
	while (y < data->nb_row)
	{
		x = 0;
		while (x <= data->nb_column)
		{
			data->point->x = x;
			data->point->y = y;
			data->point->z = ft_atoi((const char *)data->line[(y * data->nb_column) + x]);
			data->point->point_id = (y * data->nb_column) + x;
			data->point++;
			if (ft_is_in_str((const char *)data->line[(y * data->nb_point) + x++], '\n'))
				break;
		}
		y++;
	}
	data->point->point_id = data->nb_column * data->nb_row;
	data->nb_point = data->point->point_id;
	reset_ptr_point(data);
}
static void	get_nb_elem(char **str, int *nb)
{
	while (*str && !ft_strchr(*str, '\n'))
	{
		(*nb)++;
		str++;
	}
}

char	**get_line(int fd, int *nb_row, int *nb_column)
{
	char	*line;
	char	*temp;
	char	**res;

	line = get_next_line(fd);
	if (line && ft_strchr(line, '\n'))
		(*nb_row)++;
	while (line)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		if (ft_strchr(temp, '\n'))
			(*nb_row)++;
		line = ft_strjoin(line, temp);
		free(temp);
	}
	res = ft_split(line, " ");
	if (res)
		get_nb_elem(res, nb_column);
	close(fd);
	return (free(line), res);
}
void	get_bis(t_data *data)
{
	reset_ptr_point(data);
	while (data->point->point_id != data->nb_row * data->nb_column)
	{
		data->point->x_bis = data->point->x * data->zoom;
		data->point->y_bis = data->point->y * data->zoom;
		data->point->z_bis = data->point->z * data->zoom;
		get_matrix_point(data, *data->point, &data->point->x_bis,
				&data->point->y_bis);
		data->point->x_bis += data->beg_x / 2;
		data->point->y_bis += data->beg_y / 2;
		data->point++;
	}
	reset_ptr_point(data);
}

void	reset_ptr_point(t_data *data)
{
	if (data->point->point_id != 0)
	{
		while (data->point->point_id != 0)
			data->point--;
	}
}