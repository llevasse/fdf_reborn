/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_details.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:15:10 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_para(const char *str)
{
	int	spec;

	spec = 0;
	while (*(str - spec) != '%')
		spec++;
	return (*(str - (spec - 1)));
}

int	has_prec(const char *str)
{
	while (*str != '%')
		str--;
	str++;
	while (!is_specifier(*str, 0))
	{
		if (*str++ == '.')
			return (1);
	}
	return (0);
}

int	get_spec(const char *str)
{
	while (!(is_specifier(*str, 0)) && *str)
		str++;
	return (*str);
}
