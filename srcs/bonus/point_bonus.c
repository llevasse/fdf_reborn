/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:53:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/30 11:11:33 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	init_points(t_data *data, int fd)
{
	data->line = get_line(fd, &data->nb_row, &data->nb_column);
	if (!data->line)
		return ;
	data->point = malloc(((data->nb_row * data->nb_column) + 1)
			* sizeof(t_point));
	if (!data->point)
		return ((void)(free_tab(data->line), data->line = NULL));
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

int	get_nb_elem(char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		if (ft_is_in_str("0123456789,xXaAbBcCdDeEfF", *str))
		{
			while (ft_is_in_str("0123456789,xXaAbBcCdDeEfF", *str))
				str++;
			nb++;
		}
		str++;
	}
	return (nb);
}

char	**get_line(int fd, int *nb_row, int *nb_column)
{
	char	*line;
	char	*temp;
	char	**res;

	line = get_next_line(fd);
	if (line && ft_strchr(line, '\n'))
		(*nb_row)++;
	*nb_column = get_nb_elem(line);
	while (line)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		if (*nb_column > get_nb_elem(temp))
			*nb_column = get_nb_elem(temp);
		(*nb_row)++;
		line = ft_strjoin_free_first(line, temp);
		free(temp);
	}
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
