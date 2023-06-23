/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:42:12 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/23 14:40:01 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

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

int	get_rgb(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}
