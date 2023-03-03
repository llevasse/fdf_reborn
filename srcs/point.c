/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:53:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/03 16:00:57 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_points(t_data *data, int fd)
{
	int	x;
	int	y;

	data->line = get_line(fd, &data->nb_row, &data->nb_column);
	data->point = malloc((data->nb_row * data->nb_column) * sizeof(t_point));
	if (!data->point)
		return ;
	y = 0;
	while (y < data->nb_row)
	{
		x = 0;
		while (x < data->nb_column)
		{
			data->point->x = x++;
			data->point->y = y;
			data->point->z = (float)ft_atoi((const char *)data->line++);
			data->point++;
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
