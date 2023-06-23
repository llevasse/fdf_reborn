/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:53:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/23 13:33:03 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include <stdio.h>

void	init_points(t_data *data, int fd)
{
	data->line = get_line(fd, &data->nb_row, &data->nb_column);
	if (!data->line)
		return ;
	data->line -= data->nb_point;
	data->point = malloc(((data->nb_row * data->nb_column) + 1)
			* sizeof(t_point));
	if (!data->point)
		return ;
	set_points(data);
	data->point->x = (float)(data->nb_column - 1) / 2;
	data->point->y = (float)(data->nb_row - 1) / 2;
	data->point->z = 0;
	data->point->point_id = data->nb_column * data->nb_row;
	data->nb_point = data->point->point_id;
	reset_point_ptr(data);
}

void	set_points(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->nb_row)
	{
		x = 0;
		while (x < data->nb_column)
		{	
			data->point->x = x;
			data->point->y = y;
			data->point->z = ft_atoi((const char *)data->line[(y
						* (data->nb_column)) + x]);
			data->point->point_id = (y * data->nb_column) + x;
			data->point->colour = init_colour(-1, -1, -1, -1);
			if (ft_is_in_str(data->line[(y * data->nb_column) + x], ','))
				data->point->colour = init_colour_from_str(data->line[(y
							* data->nb_column) + x]);
			data->point++;
			if (x++ == data->nb_column)
				break ;
		}
		y++;
	}
}

static void	get_nb_elem(char **str, int *nb)
{
	while (*str && !ft_strchr(*str, '\n'))
	{
		(*nb)++;
		str++;
	}
	if (ft_is_in_str("0123456789", **str))
		(*nb)++;
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
	free_tab(res);
	res = ft_split(line, " \n");
	return (free(line), res);
}

void	reset_point_ptr(t_data *data)
{
	if (data->point->point_id > 0)
	{
		while (data->point->point_id != 0)
			data->point--;
	}
}

void	set_colour(t_data *data)
{
	double	gradiant;

	reset_point_ptr(data);
	while (data->point->point_id != data->nb_point)
	{
		while (data->point->point_id != data->nb_point - 1
			&& data->point->colour.hex != -1)
			data->point++;
		if (data->point->z == 0)
			data->point->colour = init_colour(0, ZERO_R, ZERO_G, ZERO_B);
		else if (data->point->z == data->highest_z)
			data->point->colour = init_colour(0, HIGHEST_R, HIGHEST_G,
					HIGHEST_B);
		else if (data->point->z == data->lowest_z)
			data->point->colour = init_colour(0, LOWEST_R, LOWEST_G, LOWEST_B);
		else if (data->point->z > 0)
		{
			gradiant = (double)data->point->z / data->highest_z;
			data->point->colour = init_colour(0, BEG_R - (gradiant * (BEG_R
							- HIGHEST_R)), BEG_G - (gradiant * (BEG_G
							- HIGHEST_G)), BEG_B - (gradiant * (BEG_B
							- HIGHEST_B)));
		}
		else if (data->point->z < 0)
		{
			gradiant = (double)data->point->z / data->lowest_z;
			data->point->colour = init_colour(0, BEG_R - (gradiant * (BEG_R
							- LOWEST_R)), BEG_G - (gradiant * (BEG_G
							- LOWEST_G)), BEG_B - (gradiant * (BEG_B
							- LOWEST_B)));
		}
		data->point++;
	}
}
