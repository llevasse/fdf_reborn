/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:37:51 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/03 20:05:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	project(t_data *data)
{
	int	i;
	get_bis(data);
	i = 0;
	while(data->point->point_id != data->nb_point)
	{
		if ((data->point + 1)->x != 0)
			draw_line(*data, *data->point, *(data->point + 1));
		if (i < data->nb_point - data->nb_column)
			draw_line(*data, *data->point, *(data->point + data->nb_column));
		data->point++;
		i++;
	}
}

void	draw_line(t_data data, t_point point_a, t_point point_b)
{
	(void)data;
	(void)point_a;
	(void)point_b;
}