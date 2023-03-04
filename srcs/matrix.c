/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:18:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/03 19:34:52 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_point_bis(t_data *data)
{
	float	**matrix_x;
	float	**matrix_y;
	float	**matrix_z;
	float	*matrix_point;

	matrix_x = init_matrix_x(*data);
	matrix_y = init_matrix_y(*data);
	matrix_z = init_matrix_z(*data);
	matrix_point = malloc(sizeof(int) * 3);
	if (!matrix_point)
		return ;
	while (data->point->point_id != (data->nb_row * data->nb_column))
	{
	}
}

void	get_point_bis(t_point *point, int **matrix_x, int **matrix_y,
		int **matrix_z)
{

}

float	**init_matrix(void)
{
	float	**matrix;

	matrix = malloc(3 * sizeof(float *));
	if (!matrix)
		return (NULL);
	matrix[0] = malloc(3 * sizeof(float));
	if (!matrix[0])
		return (free(matrix), NULL);
	matrix[1] = malloc(3 * sizeof(float));
	if (!matrix)
	{
		free(matrix[0]);
		return (free(matrix), NULL);
	}
	matrix[2] = malloc(3 * sizeof(float));
	if (!matrix)
	{
		free(matrix[0]);
		free(matrix[1]);
		return (free(matrix), NULL);
	}
	return (matrix);
}

float	**init_matrix_x(t_data data)
{
	float	**matrix;

	matrix = init_matrix();
	if (!matrix)
		return (NULL);
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(data.angle_x * RADIAN);
	matrix[1][2] = -sin(data.angle_x * RADIAN);
	matrix[2][0] = 0;
	matrix[2][1] = sin(data.angle_x * RADIAN);
	matrix[2][2] = cos(data.angle_x * RADIAN);
	return (matrix);
}
float	**init_matrix_y(t_data data)
{
	float	**matrix;

	matrix = init_matrix();
	if (!matrix)
		return (NULL);
	matrix[0][0] = cos(data.angle_y * RADIAN);
	matrix[0][1] = 0;
	matrix[0][2] = sin(data.angle_y * RADIAN);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(data.angle_x * RADIAN);
	matrix[2][1] = 0;
	matrix[2][2] = cos(data.angle_x * RADIAN);
	return (matrix);
}

float	**init_matrix_z(t_data data)
{
	float **matrix;

	matrix = init_matrix();
	if (!matrix)
		return (NULL);
	matrix[0][0] = cos(data.angle_x * RADIAN);
	matrix[0][1] = -sin(data.angle_x * RADIAN);
	matrix[0][2] = 0;
	matrix[1][0] = sin(data.angle_x * RADIAN);
	matrix[1][1] = cos(data.angle_x * RADIAN);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	return (matrix);
}