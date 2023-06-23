/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_help_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:18:40 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/23 14:27:15 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	no_higher(int *nb)
{
	if (*nb < 0)
		*nb = 0;
	if (*nb > 255)
		*nb = 255;
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
	no_higher(&elem.r);
	no_higher(&elem.g);
	no_higher(&elem.b);
	return (elem);
}

void	init_colour_help(int *nb, const char *str)
{
	*nb *= hex2int(*str++) + 1;
	if (hex2int(*str++) != 0)
		*nb *= hex2int(*(str - 1) + 1);
	(*nb)--;
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
		init_colour_help(&r, str);
	if (ft_strlen(str) >= 2)
		init_colour_help(&g, str);
	if (ft_strlen(str) >= 2)
		init_colour_help(&b, str);
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