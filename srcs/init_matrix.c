/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:53:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/02 13:07:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/// @brief Allocate memory for an array of array of floats.
/// @return Return an array of array of pointer (matrix[3][3]).
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
	if (!matrix[1])
	{
		free(matrix[0]);
		return (free(matrix), NULL);
	}
	matrix[2] = malloc(3 * sizeof(float));
	if (!matrix[2])
	{
		free(matrix[0]);
		free(matrix[1]);
		return (free(matrix), NULL);
	}
	return (matrix);
}

/// @brief Allocate memory for an array of array of floats used in X rotation.
/// @return Return an array of array of pointer (matrix[3][3]).
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

/// @brief Allocate memory for an array of array of floats used in Y rotation.
/// @return Return an array of array of pointer (matrix[3][3]).
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

/// @brief Allocate memory for an array of array of floats used in Z rotation.
/// @return Return an array of array of pointer (matrix[3][3]).
float	**init_matrix_z(t_data data)
{
	float	**matrix;

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
