/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_help_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:18:40 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/01 11:48:03 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/// @brief Check if value is in range.
/// @param nb Int to check,
/// @param highest Highest value acceptable,
/// @param lowest Lowest value acceptable,
/// @return Return integer in range.
int	no_higher(int nb, int highest, int lowest)
{
	if (nb < lowest)
		return (no_higher(nb + highest, highest, lowest));
	if (nb > highest)
		return (no_higher(nb - highest, highest, lowest));
	return (nb);
}

/// @brief Initialize and assign colour to point.
/// @param colour RGB int value of colour (-1 if not known),
/// @param colour r int value of colour (-1 if not known),
/// @param colour g int value of colour (-1 if not known),
/// @param colour b int value of colour (-1 if not known).
/// @return Return colour structur of point.
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
	elem.r = no_higher(elem.r, 255, 0);
	elem.g = no_higher(elem.g, 255, 0);
	elem.b = no_higher(elem.b, 255, 0);
	return (elem);
}

/// @brief Update nb value from str of hexadecimal.
/// @param *nb Pointer to int to update,
/// @param *str Str containing hex value of point's colour.
void	init_colour_help(int *nb, const char *str)
{
	*nb *= hex2int(*str++) + 1;
	if (hex2int(*str++) != 0)
		*nb *= hex2int(*(str - 1) + 1);
	(*nb)--;
}

/// @brief Initialize colour of point from str.
/// @param *str Str containing hex value of point's colour.
/// @return Return colour structur of point.
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

/// @brief Get integer value from hexa char.
/// @param byte hexadecimal char.
/// @return Return integer value from 0 to 15.
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
