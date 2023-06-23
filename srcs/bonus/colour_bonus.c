/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:42:12 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/23 13:07:14 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

unsigned int	get_colour(t_line line)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			gradiant;

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
	r = line.p_b.colour.r - ((1 - gradiant) * (line.p_b.colour.r
				- line.p_a.colour.r));
	g = line.p_b.colour.g - ((1 - gradiant) * (line.p_b.colour.g
				- line.p_a.colour.g));
	b = line.p_b.colour.b - ((1 - gradiant) * (line.p_b.colour.b
				- line.p_a.colour.b));
	if (line.p_a.z > line.p_b.z || (line.p_a.z == line.p_b.z
			&& line.p_a.colour.hex != line.p_b.colour.hex))
	{
		r = line.p_b.colour.r - (gradiant * (line.p_b.colour.r
					- line.p_a.colour.r));
		g = line.p_b.colour.g - (gradiant * (line.p_b.colour.g
					- line.p_a.colour.g));
		b = line.p_b.colour.b - (gradiant * (line.p_b.colour.b
					- line.p_a.colour.b));
	}
	return ((r * 256 * 256) + (g * 256) + b);
}

t_colour	init_colour(int colour, int r, int g, int b)
{
	struct s_colour	elem;

	elem.r = r;
	elem.g = g;
	elem.b = b;
	elem.hex = get_rgb(r, g, b);
	if (colour == -1)
		elem.hex = -1;
	if (r == 0 && g == 0 && b == 0 && colour != 0)
	{
		elem.hex = colour;
		elem.r = (colour >> 16);
		elem.g = (colour >> 8);
		elem.b = colour;
	}
	if (elem.r < 0)
		elem.r = 0;
	if (elem.r > 255)
		elem.r = 255;
	if (elem.g < 0)
		elem.g = 0;
	if (elem.g > 255)
		elem.g = 255;
	if (elem.b < 0)
		elem.b = 0;
	if (elem.b > 255)
		elem.b = 255;
	return (elem);
}

int	get_rgb(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

t_colour	init_colour_from_str(const char *str)
{
	int	r;
	int	g;
	int	b;

	r = 1;
	g = 1;
	b = 1;
	while (*str != 'x')
		str++;
	str++;
	if (ft_strlen(str) >= 2)
	{
		r *= hex2int(*str++) + 1;
		if (hex2int(*str++) != 0)
			r *= hex2int(*(str - 1) + 1);
		r--;
	}
	if (ft_strlen(str) >= 2)
	{
		g *= hex2int(*str++) + 1;
		if (hex2int(*str++) != 0)
			g *= hex2int(*(str - 1) + 1);
		g--;
	}
	if (ft_strlen(str) >= 2)
	{
		b *= hex2int(*str++) + 1;
		if (hex2int(*str++) != 0)
			b *= hex2int(*(str - 1) + 1);
		b--;
	}
	return (init_colour(0, r, g, b));
}

int	hex2int(char byte)
{
	if (byte >= '0' && byte <= '9')
		byte = byte - '0';
	else if (byte >= 'a' && byte <= 'f')
		byte = byte - 'a' + 10;
	else if (byte >= 'A' && byte <= 'F')
		byte = byte - 'A' + 10;
	return ((int)byte);
}