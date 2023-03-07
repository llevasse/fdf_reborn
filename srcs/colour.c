/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:42:12 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/07 09:11:55 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	}
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