/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:42:12 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/02 13:06:55 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/// @brief Get colour to print at index of line.
/// @param line Line structur currently being printed.
unsigned int	get_colour(t_line line)
{
	t_colour	rgb;
	double		gradiant;

	if (line.p_a.colour.hex == line.p_b.colour.hex)
		return (line.p_a.colour.hex);
	if (line.p_a.z < line.p_b.z)
		gradiant = (double)line.i / line.len;
	else
		gradiant = (double)(line.len - line.i) / line.len;
	if (line.p_a.z == 0 && line.p_b.z != 0)
		line.p_a.colour = init_colour(0, BEG_R, BEG_G, BEG_B);
	if (line.p_b.z == 0 && line.p_a.z != 0)
		line.p_b.colour = init_colour(0, BEG_R, BEG_G, BEG_B);
	if (gradiant > 1.0)
		gradiant = 1;
	help_get_colour(line, &rgb, gradiant);
	return ((rgb.r * 256 * 256) + (rgb.g * 256) + rgb.b);
}

/// @brief Update the rgb structur in a line structur.
/// @param line Line structur currently being printed,
/// @param *rgb Pointer to rgb structur int current line,
/// @param gradiant Value between 0 and 1.
void	help_get_colour(t_line line, t_colour *rgb, double gradiant)
{
	rgb->r = line.p_b.colour.r - ((1 - gradiant) * (line.p_b.colour.r
				- line.p_a.colour.r));
	rgb->g = line.p_b.colour.g - ((1 - gradiant) * (line.p_b.colour.g
				- line.p_a.colour.g));
	rgb->b = line.p_b.colour.b - ((1 - gradiant) * (line.p_b.colour.b
				- line.p_a.colour.b));
	if (line.p_a.z > line.p_b.z || (line.p_a.z == line.p_b.z
			&& line.p_a.colour.hex != line.p_b.colour.hex))
	{
		rgb->r = line.p_b.colour.r - (gradiant * (line.p_b.colour.r
					- line.p_a.colour.r));
		rgb->g = line.p_b.colour.g - (gradiant * (line.p_b.colour.g
					- line.p_a.colour.g));
		rgb->b = line.p_b.colour.b - (gradiant * (line.p_b.colour.b
					- line.p_a.colour.b));
	}
}

/// @brief Assign the colour of every point based on their altitude
/// and if they are not specified in the .fdf file.
/// @param *data Pointer to a data structur containing the map's info.
void	set_colour(t_data *data)
{
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
			set_colour_high(data);
		else if (data->point->z < 0)
			set_colour_low(data);
		data->point++;
	}
}

/// @brief Assign the colour of a point with positive and non-zero altitude.
/// @param *data Pointer to a data structur containing the map's info.
void	set_colour_high(t_data *data)
{
	double	gradiant;

	gradiant = (double)data->point->z / data->highest_z;
	data->point->colour = init_colour(0, BEG_R - (gradiant * (BEG_R
					- HIGHEST_R)), BEG_G - (gradiant * (BEG_G
					- HIGHEST_G)), BEG_B - (gradiant * (BEG_B
					- HIGHEST_B)));
}

/// @brief Assign the colour of a point with negative and non-zero altitude.
/// @param *data Pointer to a data structur containing the map's info.
void	set_colour_low(t_data *data)
{
	double	gradiant;

	gradiant = (double)data->point->z / data->lowest_z;
	data->point->colour = init_colour(0, BEG_R - (gradiant * (BEG_R
					- LOWEST_R)), BEG_G - (gradiant * (BEG_G
					- LOWEST_G)), BEG_B - (gradiant * (BEG_B
					- LOWEST_B)));
}
