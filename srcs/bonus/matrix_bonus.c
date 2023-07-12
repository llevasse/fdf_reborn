/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:18:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/12 23:45:27 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/// @brief Assign to *x and *y their values post matrix multiplication.
/// @param *data Pointer to structur cointaining map data,
/// @param point Structur of point data,
/// @param *x Pointer to x value of a point,
/// @param *y Pointer to y value of a point.
void	get_matrix_point(t_data *data, t_point point, double *x, double *y)
{
	double	**matrix_x;
	double	**matrix_y;
	double	**matrix_z;
	double	*matrix_point;

	matrix_point = malloc(sizeof(double) * 3);
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
//	no_higher_double(x, WINDOW_WIDTH + 1, -1);
//	no_higher_double(y, WINDOW_HEIGHT + 1, -1);
	return (free_all_matrix(matrix_point, matrix_x, matrix_y, matrix_z));
}

//		matrix X				matrix Y				matrix Z
//	1	|	0	|	0		cos	|	0	|  sin		cos	| -sin	|	0
//	0	|  cos	| -sin		0	|	1	|	0		sin	|  cos	|	0
//	0	|  sin	|  cos		-sin	|	0	|  cos		0	|	0	|	1

/// @brief Multiply the matrix of point with the matrix of XYZ.
/// @param **matrix Pointer to pointers of to multiply with,
/// @param *matrix_point Pointer to doubles to be multiplied,
/// @param *data Pointer to structur cointaining map data.
/// @return Return a pointer to a matrix of doubles.
double	*multiply_matrix(double **matrix, double *matrix_point, t_data *data)
{
	double	temp_x;
	double	temp_y;
	double	temp_z;

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

/// @brief Free all matrix in program.
/// @param *matrix_point Pointer to doubles to be freed,
/// @param **matrix_x Pointer to pointers of double to be freed,
/// @param **matrix_y Pointer to pointers of double to be freed,
/// @param **matrix_z Pointer to pointers of double to be freed.
void	free_all_matrix(double *matrix_point,
		double **matrix_x, double **matrix_y, double **matrix_z)
{
	if (matrix_point)
		free(matrix_point);
	free_matrix(matrix_x);
	free_matrix(matrix_y);
	free_matrix(matrix_z);
}

/// @brief Free one matrix in array.
/// @param **matrix Pointer to pointers of double to be freed.
void	free_matrix(double **matrix)
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
}
