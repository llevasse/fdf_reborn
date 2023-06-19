/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:49:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_minus(const char *str, va_list args, int *sum)
{
	int	min;

	skip_minus(&str);
	while (!ft_isdigit(*str) && !is_specifier(*str, 2))
		str++;
	min = ft_atoi(str);
	if (min < 0)
		return (print_field_width(str, args, sum));
	min = *sum + ft_atoi(str);
	while (!is_specifier(*str, 0))
	{
		if (*str++ == '.')
			print_prec(str, args, sum);
	}
	if (!has_prec(str))
		print_var(str, args, sum);
	while (*sum < min)
		ft_putchar(' ', sum);
}
