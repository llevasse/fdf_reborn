/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priorities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:46:32 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_priorities(const char *str, va_list args, int *sum)
{
	if (get_spec(str) == '%')
		return (ft_putchar('%', sum), 1);
	if (*str == '0')
		return (priorities_zero(str, args, sum));
	if (*str == ' ')
	{
		while (!is_specifier(*str, 0) && *str)
		{
			if (*str == '+')
				return (print_plus((str), args, sum), 1);
			if (ft_is_in_str("132456789", *str))
				return (print_field_width(str, args, sum), 1);
			str++;
		}
	}
	return (0);
}

int	priorities_zero(const char *str, va_list args, int *sum)
{
	while (!is_specifier(*str, 0) && *str)
	{
		if (ft_isdigit(*str) && *str != '0' && has_prec(str))
			return (print_field_width(str, args, sum), 1);
		if (ft_isdigit(*str) && *str != '0')
			return (print_padding(str, args, '0', sum), 1);
		if (*str == '-')
			return (print_minus(str, args, sum), 1);
		if (*str++ == '.' && ft_is_in_str("diuxX", get_spec(str)))
			return (print_prec((str), args, sum), 1);
	}
	return (0);
}
