/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:18:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/05 09:13:33 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_matrix_point(t_data *data, t_point point, float *x, float *y)
{
	float	**matrix_x;
	float	**matrix_y;
	float	**matrix_z;
	float	*matrix_point;

	matrix_x = init_matrix_x(*data);
	matrix_y = init_matrix_y(*data);
	matrix_z = init_matrix_z(*data);
	matrix_point = malloc(sizeof(float) * 3);
	if (!matrix_point)
		return (free_matrix(matrix_x, matrix_y, matrix_z));
	matrix_point[0] = point.x_bis;
	matrix_point[1] = point.y_bis;
	matrix_point[2] = point.z_bis;
	matrix_point = multiply_matrix(matrix_x, matrix_point);
	matrix_point = multiply_matrix(matrix_y, matrix_point);
	matrix_point = multiply_matrix(matrix_z, matrix_point);
	*x = matrix_point[0];
	*y = matrix_point[1];
	free_matrix(matrix_x, matrix_y, matrix_z);
	free(matrix_point);
	(void)point;
}

//		matrix X				matrix Y				matrix Z
//	1	|	0	|	0	   cos	|	0	|  sin	  cos	| -sin	|	0
//	0	|  cos	| -sin		0	|	1	|	0	  sin	|  cos	|	0
//	0	|  sin	|  cos	  -sin	|	0	|  cos		0	|	0	|	1
//
//

float	*multiply_matrix(float **matrix, float *matrix_point)
{
	float	temp_x;
	float	temp_y;
	float	temp_z;

	temp_x = (matrix_point[0] * matrix[0][0]) + (matrix_point[1] * matrix[0][1]) + (matrix_point[2]
			* matrix[0][2]);
	temp_y = (matrix_point[0] * matrix[1][0]) + (matrix_point[1] * matrix[1][1]) + (matrix_point[2]
			* matrix[1][2]);
	temp_z = (matrix_point[0] * matrix[2][0]) + (matrix_point[1] * matrix[2][1]) + (matrix_point[2]
			* matrix[2][2]);
	matrix_point[0] = temp_x;
	matrix_point[1] = temp_y;
	matrix_point[2] = temp_z;
	return (matrix_point);
}

void	free_matrix(float **matrix_x, float **matrix_y, float **matrix_z)
{
	int	i;

	i = 0;
	if (matrix_x)
	{
		while (i < 3)
		{
			if (matrix_x[i])
				free(matrix_x[i]);
			i++;
		}
		free(matrix_x);
	}
	i = 0;
	if (matrix_y)
	{
		while (i < 3)
		{
			if (matrix_y[i])
				free(matrix_y[i]);
			i++;
		}
		free(matrix_y);
	}
	i = 0;
	if (matrix_z)
	{
		while (i < 3)
		{
			if (matrix_z[i])
				free(matrix_z[i]);
			i++;
		}
		free(matrix_z);
	}
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
	matrix[2][0] = -sin(data.angle_y * RADIAN);
	matrix[2][1] = 0;
	matrix[2][2] = cos(data.angle_y * RADIAN);
	return (matrix);
}

float	**init_matrix_z(t_data data)
{
	float **matrix;

	matrix = init_matrix();
	if (!matrix)
		return (NULL);
	matrix[0][0] = cos(data.angle_z * RADIAN);
	matrix[0][1] = -sin(data.angle_z * RADIAN);
	matrix[0][2] = 0;
	matrix[1][0] = sin(data.angle_z * RADIAN);
	matrix[1][1] = cos(data.angle_z * RADIAN);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	return (matrix);
}