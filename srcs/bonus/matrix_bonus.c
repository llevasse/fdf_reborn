/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:18:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/20 11:00:32 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_matrix_point(t_data *data, t_point point, float *x, float *y)
{
	float	**matrix_x;
	float	**matrix_y;
	float	**matrix_z;
	float	*matrix_point;

	matrix_point = malloc(sizeof(float) * 3);
	matrix_x = init_matrix_x(*data);
	matrix_y = init_matrix_y(*data);
	matrix_z = init_matrix_z(*data);
	if (!matrix_z || !matrix_x || !matrix_y || !matrix_point)
		return (free_all_matrix(matrix_point, matrix_x, matrix_y, matrix_z));
	matrix_point[0] = point.x_bis;
	matrix_point[1] = point.y_bis;
	matrix_point[2] = point.z_bis;
	matrix_point = multiply_matrix(matrix_x, matrix_point, data);
	matrix_point = multiply_matrix(matrix_y, matrix_point, data);
	matrix_point = multiply_matrix(matrix_z, matrix_point, data);
	*x = matrix_point[0];
	*y = matrix_point[1];
	return (free_all_matrix(matrix_point, matrix_x, matrix_y, matrix_z));
}

//		matrix X				matrix Y				matrix Z
//	1	|	0	|	0		cos	|	0	|  sin		cos	| -sin	|	0
//	0	|  cos	| -sin		0	|	1	|	0		sin	|  cos	|	0
//	0	|  sin	|  cos		-sin	|	0	|  cos		0	|	0	|	1

float	*multiply_matrix(float **matrix, float *matrix_point, t_data *data)
{
	float	temp_x;
	float	temp_y;
	float	temp_z;

	temp_x = ((matrix_point[0] - data->beg_x) * matrix[0][0])
		+ ((matrix_point[1] - data->beg_y) * matrix[0][1]) + (matrix_point[2]
			* matrix[0][2]);
	temp_y = ((matrix_point[0] - data->beg_x) * matrix[1][0])
		+ ((matrix_point[1] - data->beg_y) * matrix[1][1]) + (matrix_point[2]
			* matrix[1][2]);
	temp_z = ((matrix_point[0] - data->beg_x) * matrix[2][0])
		+ ((matrix_point[1] - data->beg_y) * matrix[2][1]) + (matrix_point[2]
			* matrix[2][2]);
	matrix_point[0] = temp_x + data->beg_x;
	matrix_point[1] = temp_y + data->beg_y;
	matrix_point[2] = temp_z;
	return (matrix_point);
}

void	free_all_matrix(float *matrix_point, float **matrix_x, float **matrix_y,
		float **matrix_z)
{
	if (matrix_point)
		free(matrix_point);
	free_matrix(matrix_x);
	free_matrix(matrix_y);
	free_matrix(matrix_z);
}

void	free_matrix(float **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (i < 3)
		{
			if (matrix[i])
				free(matrix[i]);
			i++;
		}
		free(matrix);
	}
	i = 0;
}