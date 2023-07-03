/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:53:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/02 13:07:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/// @brief Initialize and assign points to *data.
/// @param *data Pointer to data struct,
/// @param fd file descriptor to .fdf file.
void	init_points(t_data *data, int fd)
{
	data->line = get_line(fd, &data->nb_row, &data->nb_column);
	close(fd);
	if (!data->line)
		return ((void)ft_printf("Error. Check map's format.\n"));
	data->point = NULL;
	data->point = malloc(((data->nb_row * data->nb_column) + 1)
			* sizeof(t_point));
	if (!data->point)
		return ((void)(free_tab(data->line), data->line = NULL));
	set_points(data);
	data->nb_point = data->point->point_id;
	reset_point_ptr(data);
}

/// @brief Assign points to *data.
/// @param *data Pointer to data struct.
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
			ft_printf("Assigning point x:%dy:%d\n", x, y);
			data->point->x = x;
			data->point->y = y;
			data->point->z = ft_atoi((const char *)data->line[(y
						* (data->nb_column)) + x]);
			data->point->point_id = (y * data->nb_column) + x;
			data->point++;
			if (x++ == data->nb_column)
				break ;
		}
		y++;
	}
	data->point->x = (float)(data->nb_column - 1) / 2;
	data->point->y = (float)(data->nb_row - 1) / 2;
	data->point->z = 0;
	data->point->point_id = data->nb_column * data->nb_row;
}

/// @brief Get number of elements in str (pre split).
/// @param *str Pointer to chars to check.
/// @returm Return numbers of elements in str.
int	get_nb_elem(char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		if (ft_is_in_str("0123456789", *str))
		{
			while (ft_is_in_str("0123456789", *str))
				str++;
			nb++;
		}
		str++;
	}
	return (nb);
}

/// @brief Get array of pointers to chars in .fdf file.
/// @param fd File descriptor of .fdf file,
/// @param *nb_row Pointer of (int)nb_row to update the nb of rows,
/// @param *nb_column Pointer of (int)nb_column to update the nb of column.
/// @returm Return an array of str containing every point data in .fdf file.
char	**get_line(int fd, int *nb_row, int *nb_column)
{
	char	*line;
	char	*temp;
	char	**res;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	(*nb_row)++;
	*nb_column = get_nb_elem(line);
	while (line)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		ft_printf("row : %d, format column %d | current column %d\n",*nb_row, *nb_column, get_nb_elem(temp));
//		if (*nb_column != get_nb_elem(temp))
//			return ((void)free(line), free(temp), NULL);
		(*nb_row)++;
		line = ft_strjoin_free_first(line, temp);
		free(temp);
	}
	res = ft_split(line, " \n");
	return (free(line), res);
}

/// @brief Reset array of points to first point.
/// @param *data Pointer to data structur.
void	reset_point_ptr(t_data *data)
{
	if (data->point->point_id > 0)
	{
		while (data->point->point_id != 0)
			data->point--;
	}
}
